#!/bin/bash
#Daniel Chai
#CSE 374
#April 20th, 2017

if [ $# -lt 2 ]
then 
  >&2 echo "Error: Not enough arguments"
  exit 1
fi

if [ -f $1 ]
then
  i=1
  cat $1 | while read -r line
  do
    echo "Performing measurement on $line..."
    size=`./perform-measurement.sh $line`
    if [ $size -eq "0" ]
    then
      echo "...failed"
    else 
      echo $i $line $size >> $2 
      echo "...success"
    fi
    let i="$i+1" 
  done
fi
