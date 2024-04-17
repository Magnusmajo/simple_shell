#!/bin/bash

# Obtain the max PID value
max_pid=$(cat /proc/sys/kernel/pid_max)

echo "$max_pid"
