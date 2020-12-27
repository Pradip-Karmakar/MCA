#Q9) Create two files: subjects.dat and students.dat containing the subject details and the student details.
#   Sample data is as shown below:
#
#	subjects.dat
#	
#	Course_id-Semester_id-Subject_id-Subject_name
#	CS-1-1-FCO
#	CS-1-2-FOP
#	CS-1-3-SL
#	CS-2-1-DS
#	CS-2-2-DBMS
#	CS-3-1-OS
#	CS-3-2-JAVA
#
#	faculty.dat
#	
#	Faculty_id:Semester_id:Subject_id
#	F1-2-1
#	F2-3-2
#	F3-1-3
#	F1-1-1
#
#  Write a shell script to list the faculties and their respective subjects. Sample Output will be :
#	
#	F1 : FCO, DS
#	F2 : JAVA
#	F3 : SL


#Script


file1="subjects.dat"
file2="faculty.dat"
IFS='-'
while read v1 v2 v3 v4; do
        while read f1 f2 f3; do
                if [ $v2 -eq $f2 ] && [ $v3 -eq $f3 ]
                then
                        echo $v4 " taken by " $f1
                fi
        done < $file2
done < $file1


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat subjects.dat
#CS-1-1-FCO
#CS-1-2-FOP
#CS-1-3-SL
#CS-2-1-DS
#CS-2-2-DBMS
#CS-3-1-OS
#CS-3-2-JAVA

#pradip@DESKTOP-RITLBFA:~$ cat faculty.dat
#Jyoti_Mam-1-2
#Kinnari_Mam-2-1
#Kyati_Mam-1-1
#Bhumika_Mam-3-2
#Jigna_Mam-1-3
#Bhumika_Mam-2-2
#Hardik_Sir-3-1

#pradip@DESKTOP-RITLBFA:~$ sh Q9.sh
#FCO  taken by  Kyati_Mam
#FOP  taken by  Jyoti_Mam
#SL  taken by  Jigna_Mam
#DS  taken by  Kinnari_Mam
#DBMS  taken by  Bhumika_Mam
#OS  taken by  Hardik_Sir
#JAVA  taken by  Bhumika_Mam

