#!/bin/bash
pid_max=$(cat /proc/sys/kernel/pid_max)
echo "The maximum ID value is : $pid_max"