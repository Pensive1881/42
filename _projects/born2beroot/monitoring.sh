# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasper <acasper@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 21:18:15 by acasper           #+#    #+#              #
#    Updated: 2025/08/14 21:19:43 by acasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/env bash
set -euo pipefail
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
exec > >(tee -a /var/log/monitoring.log | /usr/bin/wall) 2>&1

cmd=$(uname -a)
printf "#Architecture: %s\n" "$cmd"

cmd=$(lscpu 2>/dev/null | awk -F: '/Socket\(s\)/{gsub(/ /,"",$2);print $2;exit}')
: "${cmd:=1}"
printf "#CPU physical: %s\n" "$cmd"

cmd=$(nproc)
printf "#vCPU: %s\n" "$cmd"

cmd1=$(free -m | awk '/^Mem:/ {print $3}')
cmd2=$(free -m | awk '/^Mem:/ {print $2}')
cmd3=$(( cmd2 > 0 ? cmd1 * 100 / cmd2 : 0 ))
printf "#Memory Usage: %s/%sMB (%s%%)\n" "$cmd1" "$cmd2" "$cmd3"

cmd1=$(df -BG --total | awk 'END{gsub(/G/,"",$3); print $3}')
cmd2=$(df -BG --total | awk 'END{gsub(/G/,"",$2); print $2}')
cmd3=$(df -h --total | awk 'END{gsub(/%/,"",$5); print $5}')
printf "#Disk Usage: %s/%sGb (%s%%)\n" "$cmd1" "$cmd2" "$cmd3"

if command -v mpstat >/dev/null 2>&1; then
  cmd=$(mpstat 1 1 | awk '/Average/ {printf "%.1f%%", 100 - $NF}')
else
  read _ a b c d _ < /proc/stat; idle1=$d; total1=$((a+b+c+d))
  sleep 1
  read _ a b c d _ < /proc/stat; idle2=$d; total2=$((a+b+c+d))
  cmd=$(awk -v i1="$idle1" -v t1="$total1" -v i2="$idle2" -v t2="$total2" 'BEGIN{printf "%.1f%%", (1-((>
fi
printf "#CPU load: %s\n" "$cmd"

cmd=$(who -b | awk '/boot/ {print $3, $4}')
printf "#Last boot: %s\n" "$cmd"

cmd=$(lsblk -o TYPE | awk 'BEGIN{s="no"} /^lvm$/{s="yes"} END{print s}')
printf "#LVM use: %s\n" "$cmd"

cmd=$(ss -H -t state established 2>/dev/null | wc -l | awk '{print $1+0}')
printf "#Connections TCP: %s ESTABLISHED\n" "$cmd"

cmd=$(who | awk '{print $1}' | sort -u | wc -l | awk '{print $1+0}')
printf "#User log: %s\n" "$cmd"

ipaddr=$(hostname -I 2>/dev/null | awk '{print $1}')
mac=$(ip link show | awk '/link\/ether/ {print $2; exit}')
printf "#Network: IP %s (%s)\n" "$ipaddr" "$mac"

cmd=$(journalctl --no-pager -q --since=today _COMM=sudo 2>/dev/null | grep -c COMMAND || true)
printf "#Sudo: %s cmd\n" "$cmd"

