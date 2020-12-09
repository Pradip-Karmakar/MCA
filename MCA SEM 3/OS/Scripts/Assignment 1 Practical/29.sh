#29. The word "unix" is present in only some of the files syupplied as arguments to the shell  
#script. You script should search each of       these files in turn and stop at the first file         
#that it encounters containing the word unix. The filename should be displayed on the screen.

for i; do
    echo "Searching file: $i ..."

    if grep -q "unix" "$i"; then
        echo "Found in $i"
        exit
    fi
    echo "Done."
done

#Output:

#pradip@DESKTOP-8NGKNR6:~$ sh 29.sh unix.txt
#Searching file: unix.txt ...
#Found in unix.txt

#pradip@DESKTOP-8NGKNR6:~$ sh 29.sh file1.txt
#Searching file: file1.txt ...
#Done.