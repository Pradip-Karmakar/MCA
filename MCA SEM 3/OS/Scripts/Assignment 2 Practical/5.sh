#Q5) A reputed MCA institute of Gujarat has students from various states. A sample file “students.dat” is shown as under :
#	State               M         F
#	-----------------------------------
#	Gujarat             18        12
#	Maharashtra         12        04
#	M.P.                08        04
#	U.P.                05        00
#	Rajasthan           07        00
#   Total Male candidates are 50 and Female are 20. Write a shell script to generate a Statewise Candidate Distribution
#  Report as under :
#       	                     STATEWISE CANDIDATES LISTING
#	      ----------------------------------------------------------------------------------------
#             		STATE                %MALE              %FEMALE           TOTAL
#	      ----------------------------------------------------------------------------------------
#             		GUJARAT               36                  60               30
#             		MAHARASHTRA           24                  20               16
#			……………………………… and so on …………………………………..



#Script

male=0
female=0
while read v1 v2 v3; do
        male=$(echo $male+$v2 | bc)
        female=$(echo $female+$v3 | bc)
done < "students.dat"
echo "  STATEWISE CANDIDATES LISTING "
echo "---------------------------------------"
echo "STATE             %MALE   %FEMALE TOTAL"
echo "---------------------------------------"
while read v1 v2 v3; do
        echo $v1"       "$(echo $v2*100/$male | bc)"    "$(echo $v3*100/$female | bc)"  "$(echo $v2+$v3 | bc)
done < "students.dat"


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat students.dat
#Gujarat-------- 18      12
#Maharastra----- 12      04
#Madhya_Pradesh- 08      04
#Uttar_Pradesh-- 05      00
#Rajasthan------ 07      00
#Jammu&Kashmir-- 00      02

#pradip@DESKTOP-RITLBFA:~$ sh Q5.sh
#        STATEWISE CANDIDATES LISTING
#---------------------------------------
#STATE           %MALE   %FEMALE TOTAL
#---------------------------------------
#Gujarat-------- 36      54      30
#Maharastra----- 24      18      16
#Madhya_Pradesh- 16      18      12
#Uttar_Pradesh-- 10      0       5
#Rajasthan------ 14      0       7
#Jammu&Kashmir-- 0       9       2
