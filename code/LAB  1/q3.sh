#! bin/sh
#print unique lines only
echo
echo "Print only unique lines"
echo
awk '{!seen[$0]++};END{for(i in seen) if(seen[i]==1)print i}' demo.txt
#delete duplicate
echo
echo
echo
echo "Delete duplicate lines"
echo
awk '{!seen[$0]++};END{for(i in seen) if(seen[i]==1)print i}' demo.txt >> new.txt
rm demo.txt
mv new.txt demo.txt
cat demo.txt
sort -u -o demo.txt demo.txt

#duplicate first 5 lines
echo
echo
echo
echo "Duplicate first 5 lines and add at the end of the file "
(head -5 demo.txt)>>demo.txt
cat demo.txt
#comment 10 t0 20 lines in c file
sed -i '10,10 s#^#/*# ' demo.c
sed -i '20,20 s#$#*/# ' demo.c
