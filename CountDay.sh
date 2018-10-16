#!/bin/bash

#find_day $begin $num

find_day() {
    count=0
    (( now = $1 + $2 ))
    for (( i = $1; i < now; i++ ));do
        if (( ${i} \% 4 == 0 && ${i} \% 100 != 0 || ${i} \% 400 == 0 ));then
            (( count = count + 1 ))
        fi
    done
}

find_day $1 $2

sum=0
    for (( j = 1; j <= $2; j++ ));do
        (( sum = sum + 365 ))
    done
    ans=0
    (( ans = sum + count ))
    echo $ans


