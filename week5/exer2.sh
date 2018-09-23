#!/bin/bash
FILE="hardcode.txt"

if [ ! -f $FILE ]; then
    echo 0 > $FILE
fi

while [ true ]
do
    if `ln $FILE $FILE.lock`; then
        echo $((`cat $FILE | tail -n 1` + 1)) >> $FILE
        rm $FILE.lock
    fi
done
