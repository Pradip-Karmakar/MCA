#35. Print armstrog nos. from 1 to 500. 

i=1
while [ $i -le 500 ]
do
        j=$i
        total=0
        while [ $j -gt 0 ]
        do
                temp=$(echo $j%10 | bc)
                sum=$(echo $temp^3 | bc)
                total=$(echo $total+$sum | bc)
                j=$(echo $j/10 | bc)
        done
        if [ $total -eq $i ]
        then
                echo "Armstrong Number : " $i
        fi
        i=$(echo $i+1 | bc)
done

#Output:
#Armstrong Number :  1
#Armstrong Number :  153
#Armstrong Number :  370
#Armstrong Number :  371
#Armstrong Number :  407