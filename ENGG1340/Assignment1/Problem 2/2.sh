#!/bin/bash
echo "Enter the number for checking:"
read number
len=${#number}
sum=0
for ((i=0; i<len; i++))
do
	char="${number:$((len-i-1)):1}
	if [ $((i % 2)) -eq 1 ] 
	then 
		char="$((char*2))"
		if [ $char -gt 9 ]
		then
			temp=$(( (char/10) + (char%10) ))
			sum="$((sum + temp))"
		else
			sum="$((sum + char))"
		fi
	else
		sum="$((sum + char))"
	fi
done
if [ $((sum % 10)) -eq 0 ]
then
	echo "The number $number is valid."
else
	echo "The number $number is invalid."
fi
