#!/bin/sh
echo "Basic Calculator"
echo "Enter first number:"
read num1
echo "Enter second number:"
read num2
echo "Select choice: 1) Addition 2) Subtration 3) Multiplication 4) Division
read ch
case $ch in
1)result=$(echo "$num1 + $num2" | bc)
echo "The result is: $result"	
;;        		
2)result=$(echo "$num1 - $num2" | bc)
echo "The result is: $result"	
;;
3)result=$(echo "$num1 * $num2" | bc)
echo "The result is: $result"	
;;
4)if [ $num2 -ne 0 ]; 
then
            			result=$(echo "scale=2; $num1 / $num2" | bc)
echo "The result is: $result"	
        		else
            			echo "Division by zero is not allowed."
        		fi
        		;;
   	       *) echo "Invalid choice"
       		 ;;
esac