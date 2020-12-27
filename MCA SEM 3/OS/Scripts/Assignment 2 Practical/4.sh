#Q4) Write a shell script to generate summary from a file : #“student.dat” with following format :	
#Student_no : student_name : gender : marks1 : marks2 : marks3
#Each field must be separated by a delimeter ‘-‘
#Process the following queries:
#• Calculate the total marks of each student
#• Calculate the percentage of marks for each student
#• Count the total number of male and female students
#• Count the total number of students who pass and those who fail.

#Script

IFS='-'
male=0
female=0
pass=0
fail=0

echo "1. Calculate Total Marks for each Students."
echo "2. Calculate Percentage for each Students."
echo "3. Count Total Number of Male & Female."
echo "4. Count Students Who Pass & Fail."
read -p "Enter Your Choice : " choice

while read v1 v2 v3 v4 v5 v6; do
        total=$(echo $v4+$v5+$v6 | bc)
        percentage=$(echo $total*100/150 | bc)
        if [ $choice -eq 1 ]
        then
                echo $v1 ". " $v2 " : " $total
        elif [ $choice -eq 2 ]
        then
                echo $v1 ". " $v2 " : " $percentage "%"
        elif [ $choice -eq 3 ]
        then
                if [ $v3 = "Male" ]
                then
                        male=$(echo $male+1 | bc)
                else
                        female=$(echo $female+1 | bc)
                fi
        elif [ $choice -eq 4 ]
        then
                if [ $percentage -lt 35 ]
                then
                        fail=$(echo $fail+1 | bc)
                else
                        pass=$(echo $pass+1 | bc)
                fi
        else
                echo "Invalid Choice"
        fi

done < "student.dat"

if [ $choice -eq 3 ]
then
        echo "Males : " $male
        echo "Females : " $female
elif [ $choice -eq 4 ]
then
        echo "Pass : " $pass
        echo "Fail : " $fail
fi

#Output :

#pradip@DESKTOP-RITLBFA:~$ cat student.dat
#01-Pradip_Karmakar-Male-32-45-39
#02-Sudip_Karmakar-Male-30-25-19
#03-Priya_Karmakar-Female-42-45-49
#04-Supriya_Karmakar-Female-2-5-9
#05-Monil_Karmakar-Male-23-41-29

#pradip@DESKTOP-RITLBFA:~$ sh Q4.sh
#1. Calculate Total Marks for each Students.
#2. Calculate Percentage for each Students.
#3. Count Total Number of Male & Female.
#4. Count Students Who Pass & Fail.
#Enter Your Choice : 1
#01 .  Pradip_Karmakar  :  116
#02 .  Sudip_Karmakar  :  74
#03 .  Priya_Karmakar  :  136
#04 .  Supriya_Karmakar  :  16
#05 .  Monil_Karmakar  :  93

#pradip@DESKTOP-RITLBFA:~$ sh Q4.sh
#1. Calculate Total Marks for each Students.
#2. Calculate Percentage for each Students.
#3. Count Total Number of Male & Female.
#4. Count Students Who Pass & Fail.
#Enter Your Choice : 2
#01 .  Pradip_Karmakar  :  77 %
#02 .  Sudip_Karmakar  :  49 %
#03 .  Priya_Karmakar  :  90 %
#04 .  Supriya_Karmakar  :  10 %
#05 .  Monil_Karmakar  :  62 %

#pradip@DESKTOP-RITLBFA:~$ sh Q4.sh
#1. Calculate Total Marks for each Students.
#2. Calculate Percentage for each Students.
#3. Count Total Number of Male & Female.
#4. Count Students Who Pass & Fail.
#Enter Your Choice : 3
#Males :  3
#Females :  2

#pradip@DESKTOP-RITLBFA:~$ sh Q4.sh
#1. Calculate Total Marks for each Students.
#2. Calculate Percentage for each Students.
#3. Count Total Number of Male & Female.
#4. Count Students Who Pass & Fail.
#Enter Your Choice : 4
#Pass :  4
#Fail :  1


