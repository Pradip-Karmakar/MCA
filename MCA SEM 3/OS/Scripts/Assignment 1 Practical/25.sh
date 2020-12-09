#25. Program must display all the combinations of 1, 2, and 3.


for i in 1 2 3
do
        for j in 1 2 3
        do
                for k in 1 2 3
                do
                            if [ $k -le $j ]
                            then
                                    if [ $j -le $i ]
                                    then
                                        echo $i $j $k
                                    fi
                            fi
                done
        done
done

#Output:

#1 1 1
#2 1 1
#2 2 1
#2 2 2
#3 1 1
#3 2 1
#3 2 2
#3 3 1
#3 3 2
#3 3 3
