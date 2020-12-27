#Q2) Write a shell script to generate summary from the sales.dat file.
#Sales made by 3 salesman by selling 3 products are entered in a file. Add atleast
#10 records. The format is as shown below:
#Salesman:Product1:Product2:Product3
#Sample data:
#Mr. Abhishek Sharma:21:29:12
#Mr. Akash Srivastava:11:15:28
#Mr. Abhilash Dwivedi:31:04:13

#Calculate the followings :
#• Total sales of the company
#• Highest sold product
#• Best salesman (who sold the most)
#• Worst salesman (who sold the least)

#Script

product1=0
product2=0
product3=0
total=0
max=0
min=0
bestsalesman=""
worstsalesman=""
highestsale=""

while read v1 v2 v3 v4; do
        product1=$(echo $product1+$v2 | bc)
        product2=$(echo $product2+$v3 | bc)
        product3=$(echo $product3+$v4 | bc)
        total=$(echo $v2+$v3+$v4 | bc)

        if [ $min -eq 0 ]
        then
                min=$total
                worstsalesman=$(echo $v1)
        fi

        if [ $max -lt $total ]
        then
                max=$total
                bestsalesman=$(echo $v1)
        fi

        if [ $min -gt $total ]
        then
                min=$total
                worstsalesman=$(echo $v1)
        fi


        done < sales.dat

if [ $product1 -gt $product2 ] && [ $product1 -gt $product3 ]
then
        highestsale=$(echo "Procuct 1 (" $product1 ")")
elif [ $product2 -gt $product1 ] && [ $product2 -gt $product3 ]
then
        highestsale=$(echo "Procuct 2 (" $product2 ")")
else
        highestsale=$(echo "Procuct 3 (" $product3 ")")
fi


echo "Total Sales of the Company : " $(echo $product1+$product2+$product3 | bc)
echo "Highest Sold Product : "  $highestsale
echo "Best Salesman : " $bestsalesman
echo "Worst Salesman : " $worstsalesman

#Output :

#pradip@DESKTOP-RITLBFA:~$ cat sales.dat
#Mr.Pradip_Karmakar 34 45 12
#Mr.Monil_Karmakar 23 5 12
#Mr.Sudip_Karmakar 13 28 9
#Mr.Sandeep_Karmakar 3 8 19
#Mr.Shubham_Karmakar 12 2 14
#Mr.Milind_Karmakar 21 18 9
#Mr.Ajinkya_Karmakar 23 8 17
#Mr.Lakshya_Karmakar 31 28 19
#Mr.Vraj_Karmakar 33 8 29

#pradip@DESKTOP-RITLBFA:~$ sh Q2.sh
#Total Sales of the Company :  552
#Highest Sold Product :  Procuct 1 ( 224 )
#Best Salesman :  Mr.Pradip_Karmakar
#Worst Salesman :  Mr.Shubham_Karmakar

