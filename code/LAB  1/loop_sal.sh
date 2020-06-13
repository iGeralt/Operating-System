#! bin/sh
count=0
#sum_1=0
#sum_2=0
#sum_3=0
#sum_4=0
ccount=0
ecount=0
#nc=0
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
sal[$num]=$((${sal[$num]} + salary))
done < input.txt
for i in "${sal[@]}"
do
  echo $i
done
