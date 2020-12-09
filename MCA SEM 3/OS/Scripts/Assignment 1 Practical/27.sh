#27. A file called wordfile consists of several words. Write a shell script which will receive a 
#list of filenames, the first of which would be       wordfile. The shell script should report         
#all occurences of each word in wordfile in the rest of the files supplied as arguments.

filesToRead=$(($#-1))
echo $filesToRead

# Reading Line by Line
while read line; do
        # Reading Word by Word
        for word in $line; do
                echo "Searching word: '$word' ..."
                # 2 is slice starting index
                # filesToRead is slice length
                grep --color=always -n $word $2
                printf "Done.\n\n"
        done
done <"$1" # $1 is the file name we want to search


#Output :
#Searching word: 'find' ...
#1:I need to find a girlfriend
#Done.

#Searching word: 'all' ...
#2:I seached all universes
#Done.

#Searching word: 'these' ...
#Done.

#Searching word: 'words' ...
#Done.