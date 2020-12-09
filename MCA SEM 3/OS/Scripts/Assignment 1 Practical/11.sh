#11. The script receives two file names as arguments, the script must check whether the files are     
#same or not, if they are similar then delete the second file.


if [ ! -f $1 ]; then
        echo "$1 not found!"
        exit
fi

if [ ! -f $2 ]; then
        echo "$2 not found!"
        exit
fi

my_var=$(cmp -b $1 $2)
if test -z "$my_var"
then
        echo "Files are same"
        rm $2
        echo $2 "Deleted"
else
        echo "Files are not same"
fi


#pradip@DESKTOP-8NGKNR6:~$ ls
#1     11.sh  14.sh  16.sh  18.sh  2.sh   21.sh  24.sh  34.sh  37.sh  39.sh  40.sh  6.sh       file2.txt  hello.sh
#1.sh  13.sh  15.sh  17.sh  19.sh  20.sh  22.sh  3.sh   35.sh  38.sh  4.sh   5.sh   file1.txt  hello

#Output : 

#pradip@DESKTOP-8NGKNR6:~$ sh 11.sh file1.txt file2.txt
#Files are same
#file2.txt Deleted

#pradip@DESKTOP-8NGKNR6:~$ ls
#1     11.sh  14.sh  16.sh  18.sh  2.sh   21.sh  24.sh  34.sh  37.sh  39.sh  40.sh  6.sh       hello
#1.sh  13.sh  15.sh  17.sh  19.sh  20.sh  22.sh  3.sh   35.sh  38.sh  4.sh   5.sh   file1.txt  hello.sh
