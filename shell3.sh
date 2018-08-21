#!/bin/bash

#线性筛
declare -a prime

for(( k=1 ; k<=10000 ; k++  ));do
    prime[k]=0
done

for(( i=2 ; i<10000 ; i++));do
    if [[ ${prime[$i]} -eq 0 ]];then
        ((prime[0]++))
        # prime[0]=$[ $prime[0] + 1 ]
        prime[${prime[0]}]=$i
    fi

    for (( j=1 ; j<=prime[0] ; j++ )); do
        if [[ $(( i*prime[j] )) -gt 10000 ]];then
            break
        fi
        prime[$(( i*prime[j] ))]=1
        if [[ $(( i%prime[j] )) -eq 0 ]];then
            break
        fi
    done
done

for(( n=1 ; n<=prime[0] ; n++ ));do
    echo ${prime[$n]}
done
