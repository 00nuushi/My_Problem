#include <iostream>
#include <string>
#include <vector>

typedef std::vector<int> vi;
typedef std::vector<vi> vii;

int main()
{
  int cnt;
  std::cin >> cnt;
  vii number(cnt, vi(4)), hit_blow(cnt, vi(2));
  for (int i = 0; i < cnt; i++){
    std::string tmp_num, tmp_hit_blow;
    std::cin >> tmp_num >> tmp_hit_blow;
    for (int j = 0; j < 4; j++)
      number.at(i).at(j) = tmp_num[j] - '0';
    hit_blow.at(i).at(0) = tmp_hit_blow[0] - '0';
    hit_blow.at(i).at(1) = tmp_hit_blow[2] - '0';
  }

  vii candidate;
  for (int i = 123; i < 9877; i++){
    vi tmp(4);
    tmp.at(0) = i / 1000;
    tmp.at(1) = (i % 1000) / 100;
    tmp.at(2) = (i % 100) / 10;
    tmp.at(3) = i % 10;
    if (tmp.at(0) == tmp.at(1) || tmp.at(0) == tmp.at(2) || tmp.at(0) == tmp.at(3) ||
        tmp.at(1) == tmp.at(2) || tmp.at(1) == tmp.at(2) || tmp.at(2) == tmp.at(3)) continue;
    candidate.push_back(tmp);
    for (int j = 0; j < cnt; j++){
      int hit = 0, blow = 0;
      for (int k = 0; k < 4; k++){
        for (int l = 0; l < 4; l++){
          if (number.at(j).at(k) == tmp.at(l)){
            if (k == l) hit++;
            else blow++;
          }
        }
      }
      if (hit_blow.at(j).at(0) != hit || hit_blow.at(j).at(1) != blow){
        candidate.pop_back();
        break;
      }
    }
  }
  if (candidate.size() == 0){
    std::cout << "There is no answer." << std::endl;
  }else if (candidate.size() != 1){
    std::cout << "There are multiple candidates." << std::endl;
    for (int i = 0; i < candidate.size(); i++){
      for (int j = 0; j < 4; j++){
        std::cout << candidate.at(i).at(j);
      }
      std::cout << std::endl;
    }
  }else{
    for (int i = 0; i < 4; i++){
      std::cout << candidate.at(0).at(i);
    }
    std::cout << std::endl;
  }
}
