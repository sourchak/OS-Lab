
echo -n "Enter a number: "
read num
echo -e "\tMultiplication Table of $num"
for((i=0;i<11;i++))
do
    echo -e "\t\t$num * $i= $((num*i))"
done
