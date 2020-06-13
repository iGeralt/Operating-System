#! bin/sh
count=0
ccount=0
ecount=0
scount=0
declare -a sal
sum=0

while read num dept salary
do
if [ $count == 0 ]
then
  echo "$num" "$dept" "$salary"
  ((count++))
  continue
fi
if [ $dept == "CSE" ]
then
  ((ccount++))
fi
if [ $dept == "ECE" ]
then
  ((ecount++))
fi
echo "$num" "     " "$dept"  "$salary"
sal[$num]=$((${sal[$num]} + salary))
done < input.txt
echo
echo
echo "EMPNUM         TOTALSAL"
for i in "${sal[@]}"
do
  ((++scount))
  echo "$scount                $i"
  sum=$(($i + $sum))
done
echo "        " "SUM : $sum"
echo 
echo
echo
echo
echo
echo "PART B"
echo
echo
echo "DEPT" "  " "COUNT"
echo "CSE" "    " "$ccount"
echo "ECE" "    " "$ecount"
if [ $ccount -gt $ecount ]
then
  echo "Max Employees are in CSE Dept."
else
  echo "Max Employees are in ECE Dept."
fi
