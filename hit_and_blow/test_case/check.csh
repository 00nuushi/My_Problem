#!/bin/csh
set num = `find . -name "case*.txt" | wc -l`
set cnt = 1
set check = 0
set num_KO = 0
while ($cnt < $num)
  ./hit_and_blow < case$cnt.txt | xargs echo > usr_out.txt
  @ check = `diff out$cnt.txt usr_out.txt | wc -l`
  if ($check != 0) then
    echo "case$cnt KO :("
    @ num_KO += 1
  endif
  rm usr_out.txt
  @ cnt += 1
end
if ($num_KO != 0) then
  echo "KO :("
else
  echo "OK :)"
endif
