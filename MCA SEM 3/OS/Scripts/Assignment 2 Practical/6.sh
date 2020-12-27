#Q6) Write a Shell script  to generate summary from  a file “books.dat” which contains the following details :
#	Field             Description
#    ------------------------------------------------------------
#	No                Numeric (4) – uniquely identifies each book.
#	Title             Alphanumeric(30) – title of the book
#	Author            Character(20) – Author of the book
#	Publisher         Character(20) – Publisher (PHI , TMH, BPB…)
#	Edition           Numeric (2)
#	Sample Data:
#			b1001	Programming in Java	Balagurusway	TMH	Second
#			b1002	Computer Networks       Tanenbaum       Pearson Fifth
#			b1003	Operating Systems       Chaudhari       Jaico   First
#	After creating the file do the followings :
#		• Your script must replace all the BPB publisher with TMH.
#		• List the titles with the name ‘Java’.
#		• List the books written ‘Balaguruswamy
#		• List the books which are not the first edition


#Script

file="books.dat"
echo "1. Replace All the BPB Publisher with TMH."
echo "2. List Titles with name 'Java'."
echo "3. List the books Wriiten By 'Balaguruswamy'."
echo "4. List the books which are not First Edition."
read -p "Enter Your Choice : " choice
if [ $choice -eq 4 ]
then
        sed '/First/d' $file
elif [ $choice -eq 1 ] || [ $choice -eq 2 ] || [ $choice -eq 3 ]
then
        while read v1 v2 v3 v4 v5; do
                if [ $choice -eq 1 ]
                then
                        if [ $v4 = "BPB" ]
                        then
                                sed -i "s/^\($v1        \).*/\1${v2}    ${v3}   "TMH"   ${v5}/" ${file}
                        fi
                elif [ $choice -eq 2 ]
                then
                        if test "${v2#*"Java"}" != "$v2"
                        then
                                echo $v2
                        fi
                else
                        if [ $v3 = "Balaguruswamy" ]
                        then
                                echo $v1"       "$v2"   "$v3"   "$v4"   "$v5
                        fi
                fi
        done < $file
else
        echo "Invalid Input"
fi


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat books.dat
#1001    Programming_in_Java     Balaguruswamy    BPB     Second
#1002    Computer_Networks       Tanenbaum       Pearson Fifth
#1003    Operating Systems       Chaudhari       Jaico   First
#1004    C_Programming_Basics    Ramanath        BPB     First

#pradip@DESKTOP-RITLBFA:~$ sh Q6.sh
#1. Replace All the BPB Publisher with TMH.
#2. List Titles with name 'Java'.
#3. List the books Wriiten By 'Balaguruswamy'.
#4. List the books which are not First Edition.
#Enter Your Choice : 1
#pradip@DESKTOP-RITLBFA:~$ cat books.dat
#1001    Programming_in_Java     Balagurusway    TMH     Second
#1002    Computer_Networks       Tanenbaum       Pearson Fifth
#1003    Operating Systems       Chaudhari       Jaico   First
#1004    C_Programming_Basics    Ramanath        TMH     First

#pradip@DESKTOP-RITLBFA:~$ sh Q6.sh
#1. Replace All the BPB Publisher with TMH.
#2. List Titles with name 'Java'.
#3. List the books Wriiten By 'Balaguruswamy'.
#4. List the books which are not First Edition.
#Enter Your Choice : 2
#Programming_in_Java

#pradip@DESKTOP-RITLBFA:~$ sh Q6.sh
#1. Replace All the BPB Publisher with TMH.
#2. List Titles with name 'Java'.
#3. List the books Wriiten By 'Balaguruswamy'.
#4. List the books which are not First Edition.
#Enter Your Choice : 3
#1001    Programming_in_Java     Balaguruswamy   TMH     Second

#pradip@DESKTOP-RITLBFA:~$ sh Q6.sh
#1. Replace All the BPB Publisher with TMH.
#2. List Titles with name 'Java'.
#3. List the books Wriiten By 'Balaguruswamy'.
#4. List the books which are not First Edition.
#Enter Your Choice : 4
#1001    Programming_in_Java     Balaguruswamy   TMH     Second
#1002    Computer_Networks       Tanenbaum       Pearson Fifth