#4. If a five digit number is entered through the keyboard, calculate the sum of its digits.


total=0
read -p "Enter Number : " num
length=$(echo -n $num | wc -c)
i=1
while [ $i -le $length ]
do
        remainder=$(echo $num%10 | bc)
        total=$(echo $total+$remainder | bc)
        num=$(echo $num/10 | bc)
        i=$(echo $i+1 | bc)
done
echo "Total : " $total


#Output :
#Enter Number : 123456
#Total :  21