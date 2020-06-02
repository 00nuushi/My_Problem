#!/bin/csh

set num_max = 1000
set num = 1

while ($num <= $num_max)
  echo "$num" > q.txt
  printf "%4d: " $num >> result.dat
  ./meg_formula < q.txt >> result.dat
  rm q.txt
  @ num += 1
end
