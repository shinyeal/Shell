#!/bin/bash

#10000以内的素数
for(( i=2 ; i<10000 ; i++ ));do
    for(( j=2 ; j*j<i ; j++ ));do
        d=0
        if [[ $((i%j)) -eq 0 ]];then
           d=1
           break
        fi
    done
    if [[ $d == 0 ]];then
        echo $i
    fi
done

