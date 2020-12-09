#39. Find HCF and LCM of a given no.

read -p "Enter your Numbers : " num1 num2
if [ $num1 -le $num2 ]
then
        temp=$num1
        num1=$num2
        num2=$temp
fi
numerator=$num1
denominator=$num2
rem=1

while [ $rem -gt 0 ]
do
        rem=$(echo $numerator%$denominator | bc)
        numerator=$denominator
        denominator=$rem
done

echo "HCF : " $numerator
lcm=$(echo $num1*$num2/$numerator | bc)
echo "LCM : " $lcm

#Output:
#Enter your Numbers : 12 30
#HCF :  6
#LCM :  60
