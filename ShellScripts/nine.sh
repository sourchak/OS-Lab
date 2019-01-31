read -p "Enter the number upto which prime numbers are to be printed: " n

declare -a primes   #stores the values of the primes
p=0                 #keeps track of the number of primes

for((i=2;i<=n;i++))
do
    flag=0
    for j in ${primes[*]}   #initiially primes is empty and hence 2 WILL be added to primes without the for loop running
    do
        if [ $((i%j)) -eq 0 ] && [ $flag -eq 0 ]; then
            flag=1
        fi
    done
    if [ $flag -eq 0 ]; then
        primes[$p]=$i
        p=$((p+1))
    else
        flag=0
    fi
done

echo -n "Primes are: "
for i in ${primes[*]}
do
    echo -ne "\t$i"
done
echo 
