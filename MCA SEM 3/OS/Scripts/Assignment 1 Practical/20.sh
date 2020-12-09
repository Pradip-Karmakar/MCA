#20  Two numbers are entered through the keyboard, find the power, one number raised to another.

read -p "Enter base and exponent seperated by space: " base exponent
echo "$base^$exponent" | bc

#Output:

#Enter base and exponent seperated by space: 3 7
#2187