#!/bin/bash

recover="/home/xinyue/.recover"

if [ ! -d $recover ];then
    mkdir $recover    #建立一个回收站文件夹
fi

rnum=0
fnum=0

get_rf(){

    for i in $@;do          #遍历所有后边的参数

        if [ "$i" == "clear" ];then     #定时清理
            cd $recover
            rm -r -f *
            exit 0
        fi


        if [ "$i" == "/" ];then   #删除根目录报错
            echo "不能删除！"
            continue
        fi
        if [ $i == "-r" ];then
            rnum=1          #参数是-r，rnum标记为1
        elif [ $i == "-f" ];then
            fnum=1          #参数是-f, fnum标记为1
        fi

        if [ -f "$i" ];then   #删除的是文件 -r,-f都可以删除
            echo "delete $i"
            mv $i $recover
        elif [ -d "$i" ];then   #删除的是文件夹 不是-r
            if [ $rnum -eq 1 ];then
                echo "delete $i"
                mv $i $recover
            else
                echo "他是一个文件夹"
            fi
        fi

    done
}

get_rf $*



    


