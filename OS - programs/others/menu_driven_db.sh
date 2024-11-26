#!/bin/bash
echo "enter no. of records:"
read record
echo
x=0
echo "Enter Student Information:"
while [ "$x" -lt "$record" ]
do
    echo
    echo "Enter your name:"
    read name[$x]
    echo "Enter your division:"
    read div[$x]
    echo "Enter your roll no:"
    read rno[$x]
    ((x++))
done

y=0
echo
echo "Student Information:"
while [ "$y" -lt "$record" ]
do
    echo
    echo "Name: ${name[$y]}"
    echo "Div: ${div[$y]}"
    echo "Roll no: ${rno[$y]}"
    ((y++))
done
