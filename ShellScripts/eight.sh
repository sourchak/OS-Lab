# Write a script to swap the values of two variables

read -p "Enter the first number: " a
read -p "Enter the second number: " b

echo -e "Before swarp:\na=$a\nb=$b"

a=$((a+b))
b=$((a-b))
a=$((a-b))

echo -e "After swap:\na=$a\nb=$b"
