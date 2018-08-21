#!/bin/bash

#一个路径下的目录的个数
count(){

    sum=0
    for i in `ls -a $1`;do
        if [[ -f $1/$i ]];then
            continue
        else
            if [ $i == "." ] || [ $i == ".." ];then
                continue
            fi
            ((sum=sum+1))
        fi
    done
    }

    count $1
   
    echo $sum
