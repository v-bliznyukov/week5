#!/bin/bash
# if file exists
#the race condition can appear at dipperent time, we can see it by dublicate numbers
if [ -f file.txt ]
then
#put hte first number 0
  echo  0 > file
fi
#while true
while :
do
#set number to the last value from file
#critical region
 number=`tail -1 file`

 number=$((number+1))
# append the increased number
 echo $number >> file
done
