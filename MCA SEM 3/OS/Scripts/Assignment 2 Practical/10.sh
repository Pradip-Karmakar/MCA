#Q10) Create two files employee.dat and departments.dat and add atleast 10 records in the following format :
#
#	employee.dat
#
#	emp_id:department_id:birthdate
#	e101:M1:11-01-1960
#	e102:C1:21-03-1973
#	e103:M2:21-03-1973
#	e104:C1:21-03-1973
#	e105:B1:08-10-1965
#	e101:M1:11-11-1964
#
#	departments.dat
#
#	departmend_id:department_name
#	B1:Botany
#	C1:Chemistry
#	M1:Mathematics
#	M2:Management
#
#   Write a shell script to do the followings:
#	1) List all the employee_ids department-wise
#	2) List the employee_ids born after 1970
#	3) List the employee_ids according to birthdate in sorted order


#Script


file1="employee.dat"
file2="departments.dat"
IFS=': -'
echo "1. Display IDs according to Department."
echo "2. Display IDs of employee who born after 1970."
echo "3. Display Ids in sorted order according to birth year."
read -p "Enter Your Choice : " choice

if [ $choice -eq 3 ]
then
        sort -k 1.15,1.18 $file1
elif [ $choice -eq 1 ] || [ $choice -eq 2 ]
then
        while read v1 v2 v3 v4 v5; do
                while read d1 d2; do
                        if [ $choice -eq 1 ]
                        then
                                if [ $v2 = $d1 ]
                                then
                                        echo "ID : "$v1 " lies in Department : "$d2
                                fi
                        fi
                done < $file2

                if [ $choice -eq 2 ]
                then
                        if [ $v5 -gt 1970 ]
                        then
                                echo "ID : "$v1 " had born after 1970."
                        fi
                fi
        done < $file1
else
        echo "Invalid Choice"
fi


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat employee.dat
#e101:M1:11-10-1960
#e102:C1:21-03-1973
#e103:M2:21-03-1973
#e104:C1:21-03-1973
#e105:B1:08-10-1965
#e106:M1:11-11-1964
#e107:M2:07-12-1945
#e108:B1:29-04-1974
#e109:M1:18-07-1969
#e110:C1:12-03-1971

#pradip@DESKTOP-RITLBFA:~$ cat departments.dat
#B1:Botany
#C1:Chemistry
#M1:Mathematics
#M2:Management

#pradip@DESKTOP-RITLBFA:~$ sh Q10.sh
#1. Display IDs according to Department.
#2. Display IDs of employee who born after 1970.
#3. Display Ids in sorted order according to birth year.
#Enter Your Choice : 1
#ID : e101  lies in Department : Mathematics
#ID : e102  lies in Department : Chemistry
#ID : e103  lies in Department : Management
#ID : e104  lies in Department : Chemistry
#ID : e105  lies in Department : Botany
#ID : e106  lies in Department : Mathematics
#ID : e107  lies in Department : Management
#ID : e108  lies in Department : Botany
#ID : e109  lies in Department : Mathematics
#ID : e110  lies in Department : Chemistry

#pradip@DESKTOP-RITLBFA:~$ sh Q10.sh
#1. Display IDs according to Department.
#2. Display IDs of employee who born after 1970.
#3. Display Ids in sorted order according to birth year.
#Enter Your Choice : 2
#ID : e102  had born after 1970.
#ID : e103  had born after 1970.
#ID : e104  had born after 1970.
#ID : e108  had born after 1970.
#ID : e110  had born after 1970.

#pradip@DESKTOP-RITLBFA:~$ sh Q10.sh
#1. Display IDs according to Department.
#2. Display IDs of employee who born after 1970.
#3. Display Ids in sorted order according to birth year.
#Enter Your Choice : 3
#e107:M2:07-12-1945
#e101:M1:11-10-1960
#e106:M1:11-11-1964
#e105:B1:08-10-1965
#e109:M1:18-07-1969
#e110:C1:12-03-1971
#e102:C1:21-03-1973
#e103:M2:21-03-1973
#e104:C1:21-03-1973
#e108:B1:29-04-1974

