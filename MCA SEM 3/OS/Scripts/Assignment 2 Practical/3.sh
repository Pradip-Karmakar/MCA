#Q3) Create a file “medals.dat” which contains the details of medals won by each
#country in Olympics. The data in the file may be as given below :
#( Country name is Primary key.)
#Country Gold Silver Bronze
#---------------------------------------------
#India 21 12 15
#Pakistan 12 10 08
#USA 10 14 19
#Srilanka 00 09 07
#………….and so on………………..
#• Write a shell script which will ask the user to enter the Country name, further modify the no. of medals for that country.
#• Delete all the countries who get zero Gold medals.
#• Calculate the total no. of medals won by each country.
#• Find the country with highest Gold medals.

#Script

file="medals.dat"
max=0
maxcountry=""
echo "1. Edit Medals for Specific Country."
echo "2. Delete Countries having 0 Medals."
echo "3. Calculate the total Medals Won by Each Country."
echo "4. Find Country With Higest Gold Medals."
read -p "Enter Your Choice : " choice
if [ $choice -eq 1 ]
then
        read -p "Enter Country name : " country
        read -p "Enter Gold Medals : " gold
        read -p "Enter Silver Medals : " silver
        read -p "Enter Bronze Medals : " bronze
        sed -i "s/^\($country   \).*/\1${gold}  ${silver}       ${bronze}/" ${file}
        echo "Task Complete..."
elif [ $choice -eq 2 ]
then
        while read v1 v2 v3 v4; do
                if [ $v2 -eq 00 ]
                then
                        sed -i "/\b$v1  $v2\b/Id" $file
                fi
                done < $file
        echo "Deleted all countries list having Zero Gold Medals"
elif [ $choice -eq 3 ] || [ $choice -eq 4 ]
then
        while read v1 v2 v3 v4; do
                total=$(echo $v2+$v3+$v4 | bc)
                if [ $choice -eq 3 ]
                then
                        echo $v1 " : " $total
                else
                        if [ $max -eq 0 ]
                        then
                                max=$v2
                                maxcountry=$(echo $v1 " : " $v2)
                        elif [ $max -lt $v2 ]
                        then
                                max=$v2
                                maxcountry=$(echo $v1 " : " $v2)
                        fi
                fi
                done < $file

                if [ $choice -eq 4 ]
                then
                        echo $maxcountry
                fi
else
        echo "Invalid choice.."
fi

#Output :

#pradip@DESKTOP-RITLBFA:~$ cat medals.dat
#India   24      23      12
#Pakistan        00      10      15
#USA     10      14      19
#Srilanka        00      12      09
#Australia       14      00      00
#Japan   32      10      08


#pradip@DESKTOP-RITLBFA:~$ sh Q3.sh
#1. Edit Medals for Specific Country.
#2. Delete Countries having 0 Medals.
#3. Calculate the total Medals Won by Each Country.
#4. Find Country With Higest Gold Medals.
#Enter Your Choice : 3
#India  :  59
#Pakistan  :  47
#USA  :  43
#Srilanka  :  21
#Australia  :  14
#Japan  :  50

#pradip@DESKTOP-RITLBFA:~$ sh Q3.sh
#1. Edit Medals for Specific Country.
#2. Delete Countries having 0 Medals.
#3. Calculate the total Medals Won by Each Country.
#4. Find Country With Higest Gold Medals.
#Enter Your Choice : 4
#Japan : 32

#pradip@DESKTOP-RITLBFA:~$ sh Q3.sh
#1. Edit Medals for Specific Country.
#2. Delete Countries having 0 Medals.
#3. Calculate the total Medals Won by Each Country.
#4. Find Country With Higest Gold Medals.
#Enter Your Choice : 1
#Enter Country name : Srilanka
#Enter Gold Medals : 00
#Enter Silver Medals : 18
#Enter Bronze Medals : 05
#Task Complete...
#pradip@DESKTOP-RITLBFA:~$ cat medals.dat
#India   24      23      12
#Pakistan        00      19      10
#USA     10      14      19
#Srilanka        00      18      05
#Australia       14      00      00
#Japan   32      10      08

#pradip@DESKTOP-RITLBFA:~$ sh Q3.sh
#1. Edit Medals for Specific Country.
#2. Delete Countries having 0 Medals.
#3. Calculate the total Medals Won by Each Country.
#4. Find Country With Higest Gold Medals.
#Enter Your Choice : 2
#Deleted all countries list having Zero Gold Medals
#pradip@DESKTOP-RITLBFA:~$ cat medals.dat
#India   24      23      12
#USA     10      14      19
#Australia       14      00      00
#Japan   32      10      08

