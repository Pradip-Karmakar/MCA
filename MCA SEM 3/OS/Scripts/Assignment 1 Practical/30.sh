#30. A shell script receives even number of filenames. Suppose four filenames are supplied then  
#the first file should get copied into       second file, the third file should get copied into 
#fourth and so on.. If odd number of filenames are supplied display error message.


#Zero arguments
if [ $# -eq 0 ]; then
        echo "No Arguments"
        exit
fi
prevFile=$1
# If even no of args
if [ $(echo $# % 2 | bc ) -eq 0 ]
then
        # Looping through each Argument
        count=1
        for i; do
                if !(($count % 2)); then
                        cp $prevFile $i
                        echo "'$prevFile' copied to -> $i"
                else
                        prevFile=$i
                fi
                count=$(echo $count+1 | bc )
        done
# if odd no of args
else
        echo "Odd no of Arguments"
        exit
fi


#Output :
#//checking new1.txt which is blank
#pradip@DESKTOP-8NGKNR6:~$ cat new1.txt

#//checking new.txt 
#pradip@DESKTOP-8NGKNR6:~$ cat new.txt
#Hello
#My name is Pradip
#Class MCA 3
#Have a good Day
#Nice to Meet You

#//running the scrpit
#pradip@DESKTOP-8NGKNR6:~$ sh 30.sh new.txt new1.txt
#'new.txt' copied to -> new1.txt

#//checking new1.txt again
#pradip@DESKTOP-8NGKNR6:~$ cat new1.txt
#Hello
#My name is Pradip
#Class MCA 3
#Have a good Day
#Nice to Meet You