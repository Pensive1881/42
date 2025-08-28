# Born2beroot Commands Reference
*Comprehensive command list organized by topic for Born2beroot evaluation*

---

## 🔐 **USER MANAGEMENT & GROUPS**

### **Create and Manage Users**
```bash
# Create new user
sudo adduser <username>

# Change password
passwd
sudo passwd <username>

# Check user information
id <username>
whoami
```

### **Group Management**
```bash
# Create group
sudo groupadd user42
sudo groupadd evaluating

# Add user to group
sudo usermod -aG sudo <username>
sudo usermod -aG user42 <username>
sudo usermod -aG evaluating <username>

# Check group membership
groups <username>
getent group sudo
getent group user42
getent group evaluating

# List all groups
cat /etc/group
getent group
cut -d: -f1 /etc/group | sort
```

---

## 🔒 **PASSWORD POLICY**
PROS: Better security, forced rotation, prevents weak passwords.
CONS: Can annoy users, too frequent changes may lead to bad habits (e.g., writing passwords down).

### **Password Aging Settings**
```bash
# Check password aging policy
sudo cat /etc/login.defs | grep -E "(PASS_MAX_DAYS|PASS_MIN_DAYS|PASS_WARN_AGE)"

# Check user's password status
sudo chage -l <username>

# Set password expiration
sudo chage -M 30 <username>  # Expires in 30 days
sudo chage -m 2 <username>   # Minimum 2 days between changes
sudo chage -W 7 <username>   # Warn 7 days before expiration
```

### **Password Quality**
```bash
# Check password quality settings
sudo cat /etc/security/pwquality.conf

# Check PAM password configuration
sudo cat /etc/pam.d/common-password

# Test password strength
echo "password" | sudo pwscore
```

### **Login Retry Policy**
```bash
# Check login retry settings
sudo cat /etc/pam.d/common-auth | grep -E "(retry|deny)"

# Check PAM authentication
sudo cat /etc/pam.d/common-auth
```

---

## 🖥️ **HOSTNAME & SYSTEM INFO**

### **Hostname Management**
```bash
# Check current hostname
hostname

# Change hostname
sudo hostnamectl set-hostname <login>42
sudo nano /etc/hostname

# Restart after hostname change
sudo reboot
```

### **Operating System**
```bash
# Check OS information
cat /etc/os-release
cat /etc/os-release | grep PRETTY_NAME

# Check system architecture
uname -a
```

### **System Status**
```bash
# Check current user
whoami

# Check system uptime
who -b
uptime

# Check if graphical environment is disabled
systemctl get-default
```

---

## 💾 **PARTITIONING & DISKS**

### **View Partitions**
```bash
# List block devices
lsblk
lsblk -f

# Show disk space
df -h

# List partition tables
sudo fdisk -l

# View partitions (from your notes)
lsblk
```

### **LVM Information**
```bash
# Show volume groups
sudo vgdisplay

# Show logical volumes
sudo lvdisplay

# Check LVM usage
cat /etc/fstab | grep /dev/mapper
```

### **Encryption Status**
```bash
# Check LUKS encryption
sudo cryptsetup status <encrypted_device>
# Example: sudo cryptsetup status sda5_crypt
```

---

## 🔧 **SUDO CONFIGURATION**

### **Installation & Status**
```bash
# Check if sudo is installed
which sudo
dpkg -s sudo

# Check sudo package status
dpkg -l | grep sudo
```

### **Sudo Logging**
```bash
# Check sudo logging configuration
sudo cat /etc/sudoers | grep -E "(logfile|iolog_dir)"

# Check sudo log directory
ls -la /var/log/sudo/

# Check sudo sequence number
sudo cat /var/log/sudo/seq

# View sudo logs
sudo grep -r "sudo" /var/log/sudo/
```

### **Sudo Security**
```bash
# Check restricted sudo PATH
sudo cat /etc/sudoers | grep -i secure_path

# Edit sudoers file
sudo visudo

# Check sudo environment
sudo env | grep PATH
```

---

## 🛡️ **FIREWALL (UFW)**

### **Installation & Status**
```bash
# Install UFW
sudo apt install ufw

# Check UFW status
sudo ufw status
sudo ufw status verbose

# Check UFW service
sudo systemctl status ufw
```

### **UFW Configuration**
```bash
# Set default policies
sudo ufw default deny incoming
sudo ufw default allow outgoing

# Allow specific ports
sudo ufw allow 4242
sudo ufw allow 8080

# List rules
sudo ufw status numbered
sudo ufw show added

# Delete rules
sudo ufw delete allow 8080
sudo ufw delete <rule_number>
```

### **UFW Management**
```bash
# Enable/disable UFW
sudo ufw enable
sudo ufw disable

# Reset UFW
sudo ufw reset
```

---

## 🔌 **SSH CONFIGURATION**

### **Installation & Status**
```bash
# Check SSH installation
which sshd
sudo systemctl status ssh

# Check SSH service
sudo service ssh status
```

### **SSH Configuration**
```bash
# Edit SSH config
sudo nano /etc/ssh/sshd_config

# Check SSH settings
sudo cat /etc/ssh/sshd_config | grep -E "(Port|PermitRootLogin)"

# Check listening ports
sudo ss -tulnp | grep 4242
sudo netstat -tulnp | grep 4242
```

### **SSH Connection**
```bash
# Connect via SSH
ssh -p 4242 <username>@127.0.0.1

# Test SSH connection
ssh localhost -p 4242
```

---

## 📊 **MONITORING SCRIPT**

### **Script Management**
```bash
# Check script existence
ls -la /usr/local/bin/monitoring.sh

# Make script executable
sudo chmod +x /usr/local/bin/monitoring.sh

# Test script manually
bash /usr/local/bin/monitoring.sh
```

### **Cron Configuration**
```bash
# Edit root crontab
sudo crontab -e

# View root crontab
sudo crontab -l

# Check cron service
sudo systemctl status cron
sudo service cron status

# Start/stop cron service
sudo service cron start
sudo service cron stop
```

### **Cron Logs**
```bash
# Check cron logs
sudo grep CRON /var/log/syslog | tail -n 10

# Monitor cron logs in real-time
sudo tail -f /var/log/syslog | grep CRON
```

---

## 🔍 **SYSTEM MONITORING**

### **System Information**
```bash
# CPU information
lscpu
nproc

# Memory usage
free -m

# Disk usage
df -h

# CPU load
mpstat
```

### **Network Information**
```bash
# Show IP address
ip addr show
ip addr show | grep inet

# Show network interfaces
ip link show

# Check network connectivity
ping -c 4 8.8.8.8
```

### **Process & Services**
```bash
# Check running services
sudo systemctl list-units --type=service --state=running

# Check specific service
sudo systemctl status <service_name>

# Check process status
ps aux | grep <process_name>
```

---

## 🔐 **SECURITY & COMPLIANCE**

### **AppArmor (Debian)**
```bash
# Check AppArmor status
sudo aa-status

# List AppArmor profiles
sudo aa-status --profiled
```

### **File Permissions**
```bash
# Check file permissions
ls -la <file_path>

# Change file permissions
chmod +x <file>
chmod 755 <file>

# Change file ownership
sudo chown <user>:<group> <file>
```

### **System Logs**
```bash
# Check system logs
sudo journalctl -f

# Check authentication logs
sudo tail -f /var/log/auth.log

# Check system messages
sudo tail -f /var/log/syslog
```

---

## 🌐 **NETWORK & CONNECTIVITY**

### **Network Configuration**
```bash
# Show network interfaces
ip addr show

# Show routing table
ip route show

# Check DNS
cat /etc/resolv.conf

# Test DNS resolution
nslookup google.com
```

### **Port Management**
```bash
# Check listening ports
sudo ss -tulnp
sudo netstat -tulnp

# Check specific port
sudo ss -tulnp | grep :4242
```

---

## 📝 **USEFUL COMMANDS 

### **General System**
```bash
# Check OS
cat /etc/os-release | grep PRETTY_NAME

# View partitions
lsblk

# Show IP Address
ip addr show

# Change Hostname
sudo nano /etc/hostname
```

### **User Management**
```bash
# Add user to group
sudo usermod -aG user42 sschmidt

# Check if user is in sudo group
getent group sudo

# Give privilege as a su
groups "username"

# Add group and user
sudo addgroup evaluating
sudo adduser new_user evaluating
```

### **SSH & Connection**
```bash
# SSH connection
ssh -p 4242 sschmidt@127.0.0.1

# Edit SSH config
nano /etc/ssh/sshd_config
```

### **Monitoring Script Path**
```bash
# Script location
/usr/local/bin/monitoring.sh

# Cron management
sudo crontab -u root -e
sudo service cron start
sudo service cron stop
sudo service cron status
```

---





Host
sschmidt42
Helloworld1

user 
sschmidt42
Hallowelt1

encryption paraphrase
crankupthebass

sudo aa-status

kernel security module that allows the system administrator to restrict programs' capabilities with per-program profiles.

sudo ufw status


Check os 
cat /etc/os-release | grep PRETTY_NAME


Adding user in sudo group

$ su -
sudo usermod -aG sudo "your_username"
Check if user is in sudo group

$ getent group sudo
Give privilege as a su.

groups "username"

sudo addgroup evaluating
sudo adduser new_user evaluating

   sudo groupadd user42

Add user to new group
      sudo usermod -aG user42 sschmidt
	  gretent group
cat /etc/group

view partitions
lsblk


nano /etc/ssh/sshd_config

ssh -p 4242 sschmidt@127.0.0.1



Show IP Adress
	     ip addr show

Change Hostname
	sudo nano /etc/hostname

/usr/local/bin/monitoring.sh

sudo crontab -e
sudo service cron start
sudo service cron stop
sudo service cron status

# ┌───────────── minute (0 - 59)
# │ ┌───────────── hour (0 - 23)
# │ │ ┌───────────── day of the month (1 - 31)
# │ │ │ ┌───────────── month (1 - 12)
# │ │ │ │ ┌───────────── day of the week (0 - 6) (Sunday to Saturday)
# │ │ │ │ │
# │ │ │ │ │
# │ │ │ │ │
# * * * * * <command to execute>



Firewall

apt install ufw | Installs UFW.

ufw default deny incoming | Blocks all incoming requests.

ufw default allow outgoing | Allows all outgoing requests.

ufw allow 4242 | Allow incoming traffic on port 4242. tThis is crucial to ensure you can still access your server via SSH.

ufw enable | Enables UFW.



sudo nano /etc/pam.d/common-auth

retry | Maximum amount of incorrect attempts.

minlen | Minimum acceptable size for the new password.

difok | Number of characters in the new password that must not be present in the old password. Even with enforce_for_root, this rule doesn't apply to the root user since the old password is not required to change it.

maxrepeat | The maximum number of allowed same consecutive characters in the new password.

dcredit | Minimum number of digits in the new password. (negative value)

ucredit | Minimum number of uppercase characters in the new password. (negative value)

lcredit | Minimum number of lowercase characters in the new password. (negative value)

reject_username | The new password cannot include the username.

enforce_for_root | Applies rules to root.

With the new rules enforced, update the passwords for both your user account and the root account:

change password

password
sudo psswd username



