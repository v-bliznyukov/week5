#!/bin/bash
# if file exists
if [ -f file.txt ]
then
#put the first number 0
  echo  0 > file
fi
#while true
while :
do
#if process uses the file it blocked it 
if ln file.txt file.txt.lock
then
#set number to the last value from file
 number=`tail -1 file`

 number=$((number+1))
# append the increased number
 echo $number >> file
#remove block
rm file.txt.lock
fi
done
