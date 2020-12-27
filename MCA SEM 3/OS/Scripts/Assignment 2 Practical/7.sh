#Q7) Create a file “election.dat” which contains the Election details for a specific city.
#	Field               Description
#      ------------------------------------
#	Idno                Numeric    - Unique
#	Name                Character – Voter’s Name
#	Sex                 Character – M / F
#	Age                 Numeric  
#	Ward                Numeric  – Ward no. / Division no. of the city.
#	Sample data:
#		e101 - abhishek - M - 35 - 44
#		e102 - ashutosh - M - 97 - 14
#		e103 - anamika - F - 21 - 50
#	Suppose the same file is to be modified after 4 years. Write a shell script to simulate this process.
#	Your program must update the age of all People ( Add 4 years to age). In case if the age exceeds 99 then delete the record
#	from the file, assuming that the person is dead.
#	Display the election.dat and final output of your program.


#Script

file="election.dat"
IFS='-'
echo "We Assuming This file Run After Every 4 years"
while read v1 v2 v3 v4 v5; do
        if [ $v4 -lt 96 ]
        then
                newage=$(($v4+4))
                sed -i "s/^\($v1"-"\).*/\1${v2}"-"${v3}"-"${newage}"-"${v5}/" ${file}
        else
                sed -i "/\b$v1"-"\b/Id" $file
        fi
done < $file
cat $file


#Output :

#pradip@DESKTOP-RITLBFA:~$ cat election.dat
#e101-Pradip-M-21-18
#e102-Sudip-M-18-28
#e103-Monika-F-43-45
#e104-Priya-F-90-08
#e105-Milind-M-23-41
#e106-Nirav-M-52-02
#e107-Ajinkya-M-53-25
#e108-Supriya-F-94-07

#pradip@DESKTOP-RITLBFA:~$ sh Q7.sh
#We Assuming This file Run After Every 4 years
#e101-Pradip-M-25-18
#e102-Sudip-M-22-28
#e103-Monika-F-47-45
#e104-Priya-F-94-08
#e105-Milind-M-27-41
#e106-Nirav-M-56-02
#e107-Ajinkya-M-57-25
#e108-Supriya-F-98-07

#pradip@DESKTOP-RITLBFA:~$ sh Q7.sh
#We Assuming This file Run After Every 4 years
#e101-Pradip-M-29-18
#e102-Sudip-M-26-28
#e103-Monika-F-51-45
#e104-Priya-F-98-08
#e105-Milind-M-31-41
#e106-Nirav-M-60-02
#e107-Ajinkya-M-61-25

#pradip@DESKTOP-RITLBFA:~$ sh Q7.sh
#We Assuming This file Run After Every 4 years
#e101-Pradip-M-33-18
#e102-Sudip-M-30-28
#e103-Monika-F-55-45
#e105-Milind-M-35-41
#e106-Nirav-M-64-02
#e107-Ajinkya-M-65-25

