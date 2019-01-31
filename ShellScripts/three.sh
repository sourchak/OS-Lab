i="y"
sum=0
echo -n "Enter the first number: "
read a
echo -n "Enter the second number: "
read b
while [[ $i = "y" || $i = "Y" ]] ; do
    echo -ne "Enter a number corresponding to the function you want to perform:\n(1) Addition\n(2) Subtraction\n(3)Multiplication\n(4)Division\nYour Choice: "
    read i
    case $i in
        "1") echo "$a+$b=$((a+b))";;
        "2") echo "$a-$b=$((a-b))";;
        "3") echo "$a*$b=$((a*b))";;
        "4") echo "$a/$b=$((a/b))";;
    esac
    echo -n "Do you want to continue (Yes/Y, No/N) :"
    read i
done
