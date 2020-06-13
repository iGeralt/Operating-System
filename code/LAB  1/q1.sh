#! bin/sh
#cpu
echo "CPU"
echo
lscpu
#hdd
echo
echo
echo
echo "Hard Drive "
echo
lshw -c disk
#ram
echo
echo
echo
echo "RAM"
echo
dmidecode --type memory | grep Size:
#NUmber of drives
echo
echo
echo
echo "Number of Drives"
echo
lshw -short -class disk -class storage -class volume
#network
echo
echo
echo
echo "Network"
echo
lshw -short -c network
#ip
echo
echo
echo
echo "IP address"
echo
curl ifconfig.me
#MAC
echo
echo
echo
echo "MAC address"
echo
ifconfig | grep 'ether'
#USB
echo
echo
echo
echo "USB Ports"
echo
lsusb

echo
echo
echo
echo
echo "PART B"
echo
#max sized file
echo
echo
echo "File with max size"
echo
ls -S |head -1
#recently created file
echo
echo
echo "recently created file"
echo
ls -t |head -1
#file which conatain main and not malloc
echo
echo
echo "file which contains main and but not malloc"
echo
grep -lZ 'main()' * | xargs -r0 grep -FL 'malloc'
