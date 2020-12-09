#24. Print the prime nos. from 1 to 300.

checkPrime () {
        n=$1
        if [ $n -le 1 ]
        then
                return 0
        fi

        if [ $n -le 3 ]
        then
                return 1
        fi

        if [ $(($n % 2)) -eq 0 ]
        then
                return 0
        fi

        if [ $(($n % 3)) -eq 0 ]
        then
                return 0
        fi
        i=5
        while [ $(($i*$i)) -le $n ]
        do
                if [ $(($n % $i)) -eq 0 ]
                then
                        return 0
                fi
                if [ $(($n % ($i+2))) -eq 0 ]
                then
                        return 0
                fi
                i=$(($i+6))
        done
        return 1
}

num=2
while [ $num -le 300 ]
do
        checkPrime $num
        isPrime=$?

        if [ $isPrime -eq 1 ]
        then
                echo "$num "
        fi

        num=$((num+1))
done

#Output :

#2
#3
#5
#7
#11
#13
#17
#19
#23
#29
#31
#37
#41
#43
#47
#53
#59
#61
#67
#71
#73
#79
#83
#89
#97
#101
#103
#107
#109
#113
#127
#131
#137
#139
#149
#151
#157
#163
#167
#173
#179
#181
#191
#193
#197
#199
#211
#223
#227
#229
#233
#239
#241
#251
#257
#263
#269
#271
#277
#281
#283
#293