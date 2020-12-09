#7. If cost price and selling price of an item are entered through the keyboard, write a program 
#to determine whether the seller has made profit or loss. Also determine how much profit/loss    
#is made.

read -p "Enter The Cost Price For Product : " cost
read -p "Enter The Swlling price for Product : " selling
if [ $cost -lt $selling ]
then
        echo "Profit : " $((selling-cost))
elif [ $cost -gt $selling ]
then
        echo "Loss : " $((selling-cost))
else
        echo "No Profit No Loss"
fi

#Output :
#Enter The Cost Price For Product : 30
#Enter The Swlling price for Product : 23
#Loss :  -7

#Enter The Cost Price For Product : 45
#Enter The Swlling price for Product : 56
#Profit :  11

#Enter The Cost Price For Product : 3
#Enter The Swlling price for Product : 3
#No Profit No Loss