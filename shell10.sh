#!/bin/bash

#ping

for i in `seq $1 $2`;do
    ping -c 2 -t 1 192.168.1.$i 2>/dev/null 1>/dev/zero
    if [[ $? -eq 0 ]];then
        echo "192.168.1.$i"
    fi
done
