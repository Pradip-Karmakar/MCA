#21. Write a script which has the functionality similar to head and tail commands.


RED='\033[0;31m'
NC='\033[0m' # No Color

lines=$(wc -l $2 | awk '{print $1;}')


# Using SED ===================================
startFromLine=$(echo "$lines-$1" | bc)
echo -e "\e[1;36m"  # Changing Color
printf "\n ---------- Using sed ----------\n"
echo -en "\e[0m"  # Changing Color Back
sed -n 1,$1p $2
echo " ..."
tail -$1 $2

#Output:

#---------- Using sed ----------
#-en
#Hello
#My name is Pradip
# ...
#Have a good Day
#Nice to Meet You