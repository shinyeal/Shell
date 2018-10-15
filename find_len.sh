#!/bin/bash

maxtest=("" "" "")
#字符串
path=("" "" "")
#路径
long=("" "" "")
#长度
line=("" "" "")
#行号

filter() {
    a=(rmvb png img jpg jpeg gif md avi zip tar gz out)
    suffix=`echo $1 | awk -F. '{print $NF}'`
    echo ${a[*]} | grep "$suffix" >/dev/null
    if [[ $? -eq 0 ]]; then
        return 1
    fi
    return 0
}

dele_exec() {
    file $1 | grep "exec" >/dev/null
    if [[ $? -eq 1 ]];then
        filter $1
        if [[ $? -eq 0 ]]; then
        get_len $1
        fi
    fi
}

find_file() {
    for i in `ls $1`; do
        if [[ -d "$1/$i" ]]; then
            find_file "$1/$i"
        elif [[ -f "$1/$i" ]]; then
            dele_exec "$1/$i"
        fi
    done
}

get_len() {
    word=`cat $1 | tr -s -c "a-zA-Z" "\n"`
    for i in $word; do
        message=${#i}
        for (( j = 1; j <= 3; j++ )); do
            if [[ $message -gt ${long[1]} ]]; then
                long[j]=$message
                maxtest[j]=$i
                path[j]=$1
                #line[1]=`grep -n`
            fi
        done
    done
}

find_file /home/xinyue/Daily_code

echo ${lone[1]}    ${maxtest[1]}    ${path[1]}
echo ${lone[2]}    ${maxtest[2]}    ${path[2]}
echo ${lone[3]}    ${maxtest[3]}    ${path[3]}
