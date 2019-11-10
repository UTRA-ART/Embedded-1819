#!/bin/sh
usbid=`ls /dev/serial/by-id/ | grep Arduino`
usbid="/dev/serial/by-id/$usbid"
baud_rate=9600;
stty -F $usbid cs8 $baud_rate ignbrk -brkint -icrnl \
  -imaxbel -opost -onclr -isig -icanon -iexten -echo \
  -echoe -echok -echoctl -echoke noflsh-ixon -crtscts;
tail -f $usbid & bg;
while:
do

IP=`/sbin/ifconfig wlan0 | grep 'inet addr' | cut -d: -f2 | awk '{print $1}'`
printf $IP > $usbid
sleep 10;
done
