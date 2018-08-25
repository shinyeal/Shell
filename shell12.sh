#!/bin/bash

#mem
#时间  总量  剩余量  当前占用（%)  占用百分比动态平均值

time_now=`date +"%Y-%m-%d__%H:%M:%S"`
last=$1
if  [ ! $last  ];then
    echo "error"
else
    total=`free -m | head -n 2 | tail -n 1 | awk '{printf("%s",$2)}'`
    free=`free -m | head -n 2 | tail -n 1 | awk '{printf("%s",$2 - $3)}'`
    used=`free -m |head -n 2 | tail -n 1 | awk '{printf("%s",$3)}'`
    present=`echo "scale=1;${used} * 100 / ${total}" | bc`
    equal=`echo "scale=1;0.7 * ${present} + 0.3 * ${last}" | bc`

    echo ${time_now} ${total} ${free} ${present}% ${equal}%
fi
