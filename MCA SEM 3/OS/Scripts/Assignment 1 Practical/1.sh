#1. Basic salary of a person is input through the keyboard. His dearness allowance is 40% of basic
#salary and house rent is 20% of basic salary. Write a program to calculate the gross pay.


read -p "Enter Your Salary : " salary
dearness=$(echo $salary*40/100 | bc)
houserent=$(echo $salary*20/100 | bc)
gross=$((salary-houserent+dearness))
echo "Dearness Allowance : "$dearness
echo "House Rent : "$houserent
echo "Gross Salaray : "$gross


#Output : 
#Enter Your Salary : 12000
#Dearness Allowance : 4800
#House Rent : 2400
#Gross Salaray : 14400