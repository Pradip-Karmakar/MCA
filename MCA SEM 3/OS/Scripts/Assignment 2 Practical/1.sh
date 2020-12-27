#Q1) In a college, students are allowed to select any one sporting event during his
#studies. Create two files.

#Script

file1="sports.dat"
file2="student1.dat"

while read v1 v2; do
        while read s1 s2; do
                if [ $v2 -eq $s1 ]
                then
                        echo $v1 " Selected " $s2
                fi
        done < $file1
done < $file2


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat sports.dat
#101     Cricket
#102     Football
#103     Basketball
#104     Rally_Race
#105     Chess

#pradip@DESKTOP-RITLBFA:~$ cat student1.dat
#Pradip  105
#Nirav   101
#Ajinkya 105
#Lakshya 104
#Milind  102
#Hemang  103

#pradip@DESKTOP-RITLBFA:~$ sh Q1.sh
#Pradip  Selected  Chess
#Nirav  Selected  Cricket
#Ajinkya  Selected  Chess
#Lakshya  Selected  Rally_Race
#Milind  Selected  Football
#Hemang  Selected  Basketball
