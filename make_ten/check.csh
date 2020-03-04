#!/bin/csh

set dig1_max = 6
set dig2_max = 7
set dig3_max = 8
set dig4_max = 9

set dig1 = 1
set check = 0
set num_KO = 0

while ($dig1 <= $dig1_max)
  @ check = 0
  @ dig2 = $dig1 + 1
  while ($dig2 <= $dig2_max)
    @ dig3 = $dig2 + 1
    while ($dig3 <= $dig3_max)
      @ dig4 = $dig3 + 1
      while ($dig4 <= $dig4_max)
        echo "$dig1 $dig2 $dig3 $dig4" > q.txt
        set ans = `./make_ten < q.txt | xargs echo "scale=5; " | bc`
        rm q.txt
        if ( `echo "10.0 - $ans >= 0.001" | bc` ) then
          echo "$dig1 $dig2 $dig3 $dig4  KO :("
          @ check += 1
          @ num_KO += 1
        else if ( `echo "$ans - 10.0 >= 0.001" | bc` ) then
          echo "$dig1 $dig2 $dig3 $dig4  KO :("
          @ check += 1
          @ num_KO += 1
        endif
        @ dig4 += 1
      end
      @ dig3 += 1
    end
    @ dig2 += 1
  end
  if ($check != 0) then
    echo "${dig1}XXX KO :("
  else
    echo "${dig1}XXX OK :)"
  endif
  @ dig1 += 1
end
if ($num_KO != 0) then
  echo "KO :("
else
  echo "OK :)"
endif
