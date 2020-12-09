#33. A script will receive any number of filenames as arguments. It should check whether such  
#files already exist. If they do, then it       should be reported, if not then check if a         
#subdirectory "mydir" exists or not in the current directory, if it doesnt exist then it         
#should be created and in it the files supplied as arguments should be created. 

if [ $# -eq 0 ]; then
        echo "No Arguments passed"
        exit
fi

for i; do
        # If file exists
        if [ -f $i ]
        then
                echo "$i exists"
        else
                # if "mkdir" exists
                if [ -d "mydir" ]
                then
                     # Directory exists
                     printf ""
                else
                     mkdir mydir
                fi
                touch mydir/$i
                echo "$i file created in \"mydir\""
        fi
done

#Output:

#pradip@DESKTOP-8NGKNR6:~$ ls
#1      13.sh  16.sh  19.sh  21.sh  25.sh  29.sh  31.sh  34.sh  38.sh  40.sh  file1.txt  new.txt   unix.txt
#1.sh   14.sh  17.sh  2.sh   22.sh  27.sh  3.sh   32.sh  35.sh  39.sh  5.sh   hello      new1.txt  wordFile.txt
#11.sh  15.sh  18.sh  20.sh  24.sh  28.sh  30.sh  33.sh  37.sh  4.sh   6.sh   hello.sh   try

#pradip@DESKTOP-8NGKNR6:~$ sh 33.sh new.txt
#new.txt exists

#pradip@DESKTOP-8NGKNR6:~$ sh 33.sh new2.txt
#new2.txt file created in "mydir"

#pradip@DESKTOP-8NGKNR6:~$ ls
#1      13.sh  16.sh  19.sh  21.sh  25.sh  29.sh  31.sh  34.sh  38.sh  40.sh  file1.txt  mydir     try
#1.sh   14.sh  17.sh  2.sh   22.sh  27.sh  3.sh   32.sh  35.sh  39.sh  5.sh   hello      new.txt   unix.txt
#11.sh  15.sh  18.sh  20.sh  24.sh  28.sh  30.sh  33.sh  37.sh  4.sh   6.sh   hello.sh   new1.txt  wordFile.txt

#pradip@DESKTOP-8NGKNR6:~$ cd mydir/

#pradip@DESKTOP-8NGKNR6:~/mydir$ ls
#new2.txt
