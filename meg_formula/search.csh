#!/bin/csh

set num_max = 1000
set num = 1

while ($num <= $num_max)
  echo "$num" > q.txt
  echo "Yes" >> q.txt
  printf "%4d: " $num >> result_with_rule4.dat
  ./meg_formula.out < q.txt >> result_with_rule4.dat
  rm q.txt
  @ num += 1
end
