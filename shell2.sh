#!/bin/bash

while read n
do
    #read n
    for(( i=2 ; i<n ; i++ ));do
        if [[ $((n%i)) -eq 0 ]];then
            printf "%d is not a prime" "$n"
            break
        else
            printf "%d is a prime" "$n"
            break
        fi
    done
done

