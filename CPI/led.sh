#!/bin/bash
for i in $(seq 1 $1)
do
echo "led on off"
sleep 0.25
xset led 3
sleep 0.25
xset -led 3
done