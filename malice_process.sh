#!/bin/bash

# 恶意进程检测

time_now=`date +"%Y-%m-%d__%H:%M:%S"`
pid=( `ps aux | awk '{if($3 > 50 || $4 > 50) {printf("%s", $2)}}'` )
if [[ $pid ]];then
    sleep 5
    process=`ps aux | awk '{if($3 > 50 || $4 > 50) {printf("%s %s %s %.2f%% %.2f%%\n", $11, $2, $1, $3, $4)}}'` 
    echo $time_now $process
else
    echo "error"
fi
