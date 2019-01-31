echo -n "Enter the number of terms of the fibonacci sequence to be printed: "
read n
a=0
b=1
for((i=0;i<n;i++))
do
    if [ $i -eq 0 ]; then
        echo -n -e "$a\t"
    elif [ $i -eq 1 ]; then
        echo -ne "$b\t"
    else
        c=$((a+b))
        a=$b
        b=$c
        echo -ne "$b\t"
    fi
done
echo
