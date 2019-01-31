read -p "Enter a list of strings: " -a list

echo -n "Strings in the list: "
for x in ${list[*]}
do
    echo -ne "\t$x"
done

echo -en "\nEnter the string to be removed: "
read str

for i in ${!list[*]}
do
    if [ "${list[$i]}" = "$str"  ]; then
        unset list[$i]
    fi
done
echo -n "The list after deletion: "
for i in "${list[@]}"
do 
    echo -ne "\t$i"
done
echo
