#16. Write a shell script to display the menu driven interface :- 
#1) list all files of the current directory 
#2) print the current directory 
#3) print the date 
#4) print the users otherwise     
#display "Invalid Option".


echo "1) List all Files"
echo "2) Print Current Directory"
echo "3) Print Date"
echo "4) Print Users"

read choice

case $choice in
        1)  ls
            ;;
        2)  pwd
            ;;
        3)  echo `date +%d-%B-%Y`
            ;;
        4)  awk -F: '{ print $1}' /etc/passwd
            ;;
        *)  echo "Invalid Option"
esac

#Output:

#pradip@DESKTOP-8NGKNR6:~$ sh 16.sh
#1) List all Files
#2) Print Current Directory
#3) Print Date
#4) Print Users
#1
#1     11.sh  14.sh  16.sh  18.sh  2.sh   21.sh  24.sh  34.sh  37.sh  39.sh  40.sh  6.sh       hello
#1.sh  13.sh  15.sh  17.sh  19.sh  20.sh  22.sh  3.sh   35.sh  38.sh  4.sh   5.sh   file1.txt  hello.sh
#pradip@DESKTOP-8NGKNR6:~$ sh 16.sh
#1) List all Files
#2) Print Current Directory
#3) Print Date
#4) Print Users
#2
#/home/pradip
#pradip@DESKTOP-8NGKNR6:~$ sh 16.sh
#1) List all Files
#2) Print Current Directory
#3) Print Date
#4) Print Users
#3
#30-November-2020
#pradip@DESKTOP-8NGKNR6:~$ sh 16.sh
#1) List all Files
#2) Print Current Directory
#3) Print Date
#4) Print Users
#4
#root
#daemon
#bin
#sys
#sync
#games
#man
#lp
#mail
#news
#uucp
#proxy
#www-data
#backup
#list
#irc
#gnats
#nobody
#systemd-network
#systemd-resolve
#systemd-timesync
#messagebus
#syslog
#_apt
#tss
#uuidd
#tcpdump
#sshd
#landscape
#pollinate
#pradip