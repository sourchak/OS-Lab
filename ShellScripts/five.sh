# Write a script to input an array of numbers and delete a number at a given index

echo -n "Enter an array:"
read -a arr
echo -n "The array is: "
for x in "${arr[@]}"
do
    echo -ne "$x \t"
done
echo
echo -n "Enter the array index to unset (indices start at 0): "
read i
echo -n "The array after deletion: "
unset arr[i]

for x in "${arr[@]}"
do
    echo -ne "$x\t"
done
echo
