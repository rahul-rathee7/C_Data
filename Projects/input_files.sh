#!/bin/bash


awk -F '-' '{OFS = " "} {st = $1}' input_files.txt
awk -F '-' '{OFS = " "} {print $2}' input_files.txt
awk -F '-' '{OFS = " "} {print $3}' input_files.txt
awk -F '-' '{OFS = " "} {print $4}' input_files.txt

if [ st = "rahul" ];
then
	echo "Correct"
fi


