#!/bin/sh
echo "ENTER THE VALUE:"
read a

for ((c=0;c<=a;c++))
do
    echo "welcome $c"
done

count=1
while [ $count -le 5 ]
do
    echo "count is $count"
    ((count++))
done

if [ $a -lt 5 ]
then
    echo "$a is less than 5"
elif [ $a -eq 5 ]
then
    echo "GIVEN VALUE IS EQUAL TO 5"
else
    echo "$a is more than 5"
fi

echo "PRINTING EVEN..."
for ((c=0;c<=a;c++))
do
    if [ $((c%2)) -eq 0 ]
    then
        echo "$c"
    fi
done
