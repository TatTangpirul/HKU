#!/bin/bash
word=$1
filename=$2
foundlist="`grep -E -o -i "\b\w*$word\w*\b" "$filename" | sort | uniq`"
> temp.txt
for i in $foundlist
do
	count="`grep -ow "$i" "$filename" | wc -l`"
	echo "$count $i" >> temp.txt 
done
sort -k1,1nr -k2,2 temp.txt > ans.txt
rm temp.txt
cat ans.txt
