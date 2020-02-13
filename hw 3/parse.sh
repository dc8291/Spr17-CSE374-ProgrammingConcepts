#!/bin/bash
#Daniel Chai
#CSE 374
#April 20th, 2017

if [ $# -lt 2 ]
then
  >&2 echo "Error: Not enough arguments"
  exit 1
fi

if ! [ -f $1 ]
then
  >&2 echo "Error: First argument does not exist"
  exit 1
fi

grep -E '(http:\/\/)' $1 | egrep -v "(100best|List\_of|babelfish)" | sed -E -e "s/.*(http:\/\/)/\1/g" | sed -E -e "s/(http:\/\/.*)\">.*/\1/g" > $2


