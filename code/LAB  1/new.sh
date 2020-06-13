#!/bin/sh
salary=()
count=0
file=$(<input.txt)
echo PART1
for word in $file
do
  count=$((count+1))
  s=$((count-1))
  if (( $s % 3 == 0 )) && (( s != 0 ))#[[ $word == 1 ]] || [[ $word == 2 ]] || [[ $word == 3 ]] || [[ $word == 4 ]]
  then
      b=$((word-1))
  fi
  if (( $count % 3 == 0 )) && (( count !=3))
  then
       salary[$b]=$((${salary[$b]}+$word));
  fi
done
echo EMPNUM$'\t'TOTALSAL

#echo 1$'\t'"${salary[0]}"
#echo 2$'\t'"${salary[1]}"
#echo 3$'\t'"${salary[2]}"
#echo 4$'\t'"${salary[3]}"
sum=0;
ct2=0
for i in ${salary[@]}
do
    ct2=$((ct2+1))
    echo "$ct2"$'\t'"$i"
    sum=`expr $sum + $i`
done
#sum=$((${salary[0]}+${salary[1]}+${salary[2]}+${salary[3]}))
echo TOTAL SALARY$'\t'"$sum"
###################################################################################
echo PART2
temp1=0
temp2=0
for word in $file
do
  if [[ $word == CSE ]]
  then
      temp1=$((temp1+1))
  fi
  if [[ $word == ECE ]]
  then
      temp2=$((temp2+1))
  fi
done
echo DEPT$'\t'Count

echo CSE$'\t'"$temp1"
echo ECE$'\t'"$temp2"
if [[ $temp1 > $temp2 ]]
then
    echo "Max employees are in CSE Dept"
fi
if [[ $temp2 > $temp1 ]]
then
    echo "Max employees are in ECE Dept"
fi
