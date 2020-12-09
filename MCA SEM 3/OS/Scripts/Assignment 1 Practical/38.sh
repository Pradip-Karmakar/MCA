#38. Find the largest and smallest of 3 different numbers.

read -p "Enter First Number : " num1
read -p "Enter Second Number : " num2
read -p "Enter Third Number : " num3
largest=$num1
smallest=$num1
if [ $num2 -gt $largest ]
then
        largest=$num2
        if [ $num3 -gt $largest ]
        then
                largest=$num3
        fi
fi

if [ $num2 -lt $smallest ]
then
        smallest=$num2
        if [ $num3 -lt $smallest ]
        then
                smallest=$num3
        fi
fi
echo "Largest : " $largest "Smallest : " $smallest

#Output:
#Enter First Number : 99
#Enter Second Number : 101
#Enter Third Number : 98
#Largest :  101 Smallest :  98