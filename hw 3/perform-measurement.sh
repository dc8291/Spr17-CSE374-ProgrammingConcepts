#!/bin/bash 
#Daniel Chai
#CSE 374
#April 20th,2017

if [ $# -lt 1 ]
then 
  >&2 echo "Error: No argument"
  exit 1
fi

website=$1

temp=`mktemp /tmp/tempHtml.XXXXX`
wget -t 2 --timeout=3 -O ${temp} ${website} 2> /dev/null
count=`wc -c ${temp} | cut -f1 -d' '`

echo ${count}
rm ${temp}
