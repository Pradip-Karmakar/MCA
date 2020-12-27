#Q8) In a college, students are allowed to select any one elective subject during his studies. Create two files by entering the data as
#   mentioned below (you may skip the heading line if required) :
#	File : elective.dat
#      	
#	Code     Game
#     ---------------------------
#	101	AI
#	102	Computer Graphics
#	103	Parallel Processing
#	104	Data Mining
#
#	File : students.dat
#
#	RollNo.    Name     Code
#     ------------------------------
#	1          Sonal     101
#	2          Madhu     101
#	3          Mahim     103
#	4          Esha      104
# Write a shell script to list the students according to their choice of electives …
#   Eg. AI :- Sonal, Madhu
#       Computer Graphics: -
#       Parallel Processing :- Mahim
#       Data Mining :- Esha


#Script


file1="elective.dat"
file2="students2.dat"
while read v1 v2 v3; do
        while read e1 e2; do
                if [ $v3 -eq $e1 ]
                then
                        echo $v1". "$v2" Selected " $e2
                fi
        done < $file1
done < $file2


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat elective.dat
#101     AI
#102     Computer_Graphics
#103     Parallel Processing
#104     Data Mining

#pradip@DESKTOP-RITLBFA:~$ cat students2.dat
#1       Sonal   101
#2       Madhu   101
#3       Mahim   103
#4       Esha    104

#pradip@DESKTOP-RITLBFA:~$ sh Q8.sh
#1. Sonal Selected  AI
#2. Madhu Selected  AI
#3. Mahim Selected  Parallel Processing
#4. Esha Selected  Data Mining