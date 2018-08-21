#!/bin/bash

find_file() {
    for i in `ls $1`; do
        if [[ -d "$1/$i" ]];then
           # echo "$i"
            find_file "$1/$i"
        elif [[ -f "$1/$i" ]];then
           # echo "$i"
            get_len "$1/$i"
        fi
    done

}

get_len() {
    word=`cat $1 | tr -s -c "a-zA-Z" "\n"`
    #echo $1                         
    for i in $word; do
        message=${#i}       
        if [[ $maxlen -lt $message ]];then
            maxlen=$message
            maxtest=$i
            maxpath=$1
        fi
    done

}

maxtest=''
maxlen=0
maxpath=''

find_file $1

#for i in /home/xinyue/get;do     #遍历目标文件夹下所有文件
#    if [[ -f $i ]];then
#        get_len $i
#    elif [[ -d $i ]];then
#        find_file $i
#    fi
#done

printf "the max len : %s\n" "$maxlen"
printf "the max test : %s\n" "$maxtest"
printf "the max path : %s\n" "$maxpath"


