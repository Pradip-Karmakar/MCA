#37. Display all the numbers from 1 to 100 which are divisible by 7.

echo "Numbers divisible By 7 inbetwwen 1 - 100 are :"
num=7
start=1
while [ $start -le 100 ]
do
        if [ $(echo $start%$num | bc) -eq 0 ]
        then
                echo $start
        fi

        start=$((start+1))
done

#Output:
#Numbers divisible By 7 inbetwwen 1 - 100 are :
#7
#14
#21
#28
#35
#42
#49
#56
#63
#70
#77
#84
#91
#98