#!/usr/bin/env bash
info=$(echo "#Architecture: $(uname -a)"
echo "#CPU physical: $(lscpu | awk '/Socket/ {print $2}')"
echo "#vCPU: $(nproc)"
used_mem=$(free -m | awk '/^Mem:/ { print $3 }')
total_mem=$(free -m | awk '/^Mem:/ { print $2 }')
percent_mem=$((used_mem * 100 / total_mem))
echo "#Memory Usage: $used_mem/${total_mem}MB ($percent_mem%)"
total_bytes=$(lsblk -b | awk '/sda/ { print $4; exit }')
total_disk_mb=$((total_bytes / 1048576))
total_disk_gb=$((total_disk_mb / 1024))
bytes_used=$(df -B1 --output=used | awk 'NR>1 {sum += $1} END {print sum}')
used_disk_mb=$((bytes_used / 1048576))
percent_disk=$((used_disk_mb * 100 / total_disk_mb))
echo "#Disk Usage: $(df -B1 --output=used | awk 'NR>1 {sum += $1} END {print int(sum / 1048576)}')/$(df -B1 --output=s>
echo "#CPU load: $(mpstat 1 1 | awk '/Average/ {printf "%.1f%%\n", 100 - $NF}')"
echo "#Last boot: $(who -b | awk '/boot/ {print $3, $4}')"
echo "#LVM use: $(if lsblk -o TYPE | grep -q lvm; then echo "yes"; else echo "no"; fi)"
echo "#Connections TCP: $(ss -t state established | grep -v LISTEN | wc -l) ESTABLISHED"
echo "#User log: $(who | awk '{print $1}' | sort -u | wc -l)"
echo "#Network: IP $(hostname -I | awk '{print $1}') ($(ip link show | awk '/ether/ {print $2}'))"
echo "#Sudo: $(journalctl _COMM=sudo | grep -c COMMAND)")
echo "$info" | wall
