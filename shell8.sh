#!/bin/bash

source /home/xinyue/shell/.back.rc

TIME_NOW=`date +"%Y-%m-%d %H:%M"`
TIME_FILE=`date +"%Y_%m_%d_%H_%M"`

#echo -e "\033[31m ERROR \033[0m"
#echo -e "\033[32m $TIME_NOW \033[0m"
#echo -e "\033[35m $dest_dir \033[0m"

if [[ ! -d $dest_dir ]];then
    echo "$TIME_NOW 【ERROR】 The Dest dir $dest_dir not exists" >> $log
    exit
fi

echo "$TIME_NOW backup started!" >> $log

for i in `echo $backup_path | tr ":" "\n"`;do
    if [[ ! -d $i ]];then
        echo "%TIME_NOW backup 【ERROR】 The dir $i not exist" >> $log
        continue
    fi
    echo "$i started"
#    target=`echo $i | cut -d '/' -f "2-" | tr '/' '_'`
#    target="${target}_${TIME_FILE}.tar.gz"
#    tar -czPf ${dest_dir}/${target} $i
#    ls -al  "${dest_dir}/${target}"
    if [[ $? -eq 0 ]];then
        size=`du -h ${dest_dir}/${target} | cut -f 1`
        echo "$TIME_NOW backup $i --> $target +${size}" >> $log
    else
        echo "$TIME_NOW 【ERROR】 Something .... " >> $log
    fi
done

#Del_list=`find $dest_dir -name "*.tar.gz" -mmin +2`

#for i in $Del_list;do
    size=`du -h $i | cut -f 1`
#    rm -f $i
    echo "$TIME_NOW delete $i --> remove -${size}" >> $log
#done

