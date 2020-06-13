#!/bin/bash
for i in `seq 1 3`;
  do
    if [ $i == 1 ]
    then
      gnome-terminal -e "bash -ic \"bash q1.sh;exec bash\""
    elif [[ $i == 2 ]]; then
      gnome-terminal -e "bash -ic \"bash q2.sh;exec bash\""
  elif [[ $i == 3 ]]; then
    gnome-terminal -e "bash -ic \"bash q3.sh;exec bash\""
fi
done
