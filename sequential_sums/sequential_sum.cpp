#include <cstdio>
using namespace std;

void print_ans(long index, long now_length);

int main()
{
  long length, index, cnt;
  long progress;
  long sum_left, sum_right;

  scanf("%ld", &length);
  // printf("length = %ld\n", length);
  sum_left = 0, sum_right = 0, index = 1, cnt = 0, progress = 0;
  for (long i = 1; i <= length; i++){
    sum_right += i;
    while (sum_left < sum_right){
      sum_left += index;
      sum_right -= index;
      index++;
    }
    if (sum_left == sum_right){
      print_ans(index, i);
      cnt++;
    }
    // if (i >= length * (progress / 10.0)){
    //   printf("\r[");
    //   for (int j = 0; j < progress; j++)
    //     printf("*");
    //   for (int j = progress; j < 10; j++)
    //     printf(".");
    //   printf("]");
    //   fflush(stdout);
    //   progress++;
    // }
  }
  // printf("num ans = %ld\n", cnt);
}

/*++++++++++ function ++++++++++*/
void print_ans(long index, long now_length){
  for (long i = 1; i < index; i++){
    if (index == 3){
      printf("1 + 2");
      break;
    }else if (i == 1 || i == index-1)
      printf("%ld",i);
    else if (i == 2)
      printf(" + ... + ");
  }
  printf(" = ");
  for (long i = index; i <= now_length; i++){
    if (now_length - index == 1)
      printf("%ld + %ld", index, now_length);
    else if (i == index || i == now_length)
      printf("%ld", i);
    else if (i == index+1)
      printf(" + ... + ");
  }
  printf("\n");
}
