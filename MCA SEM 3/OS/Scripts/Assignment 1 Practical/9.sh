#9. Check whether the entered no. is prime or not.

read -p "Enter the Number : " prime
i=2 
f=0 
while test $i -le `expr $prime / 2`  
do 
	if test `expr $prime % $i` -eq 0  
	then
		f=1 
	fi
	i=`expr $i + 1` 
done

if test $f -eq 1  
then
	echo "Not Prime"
else
	echo "Prime"
fi

#Output :
#Enter the Number : 7
#Prime

#Enter the Number : 8
#Not Prime

#Enter the Number : 9
#Not Prime
