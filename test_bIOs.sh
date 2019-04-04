#!/bin/sh
i=0

while [ $i -lt 500 ]
do
    ./generate_sequence >sequence
    ./test_write <sequence >coded_sequence
    ./test_read <coded_sequence >decoded_sequence

    cat sequence

    if diff decoded_sequence sequence >/dev/null
    then
        i=`expr $i + 1`
    else
        echo "Sequences differ, bfile does not work"
        exit 1
    fi
done
echo All tests passed, bfile seems to work
