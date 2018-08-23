#!/bin/bash

#wall 广播

for i in `w -h | awk '{printf $2}'`;do

    echo "`who am i`" >> /dev/$i
    echo  $1 >> /dev/$i
done
