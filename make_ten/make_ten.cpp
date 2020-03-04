#include <cstdio>
#include <vector>
#define DUMMY 3.14159265
using namespace std;

void make_ten(int a, int b, int c, int d, char *equation);
double calc_equation(double a, double b, char op);

int main()
{
  int a, b, c, d;
  char *equation;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  make_ten(a, b, c, d, equation);
  printf("%s\n", equation);
}

/*++++++++++ function ++++++++++*/
void make_ten(int a, int b, int c, int d, char *equation)
{
  vector<double> group = {(double)a, (double)b, (double)c, (double)d};
  vector<char> operater = {'+', '-', '*', '/'};
  bool can_make_ten;
  double tmp_a, tmp_b, tmp_c, tmp_d;

  /* two and two */
  for (int i = 0; i < 3; i++){
    double tmp_calc_ab, tmp_calc_ba;
    double tmp_calc_cd, tmp_calc_dc;
    tmp_a = group.at(0);
    tmp_b = group.at(i % 3 + 1);
    tmp_c = group.at((i+1) % 3 + 1);
    tmp_d = group.at((i+2) % 3 + 1);
    can_make_ten = false;

    for (auto op1 : operater){
      tmp_calc_ab = calc_equation(tmp_a, tmp_b, op1);
      tmp_calc_ba = calc_equation(tmp_b, tmp_a, op1);
      for (auto op2 : operater){
        tmp_calc_cd = calc_equation(tmp_c, tmp_d, op2);
        tmp_calc_dc = calc_equation(tmp_d, tmp_c, op2);
        for (auto op3 : operater){
          if (calc_equation(tmp_calc_ab, tmp_calc_cd, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_a, op1, tmp_b, op3, tmp_c, op2, tmp_d);
          }else if (calc_equation(tmp_calc_cd, tmp_calc_ab, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_c, op2, tmp_d, op3, tmp_a, op1, tmp_b);
          }else if (calc_equation(tmp_calc_ab, tmp_calc_dc, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_a, op1, tmp_b, op3, tmp_d, op2, tmp_c);
          }else if (calc_equation(tmp_calc_dc, tmp_calc_ab, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_d, op2, tmp_c, op3, tmp_a, op1, tmp_b);
          }else if (calc_equation(tmp_calc_ba, tmp_calc_cd, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_b, op1, tmp_a, op3, tmp_c, op2, tmp_d);
          }else if (calc_equation(tmp_calc_cd, tmp_calc_ba, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_c, op2, tmp_d, op3, tmp_b, op1, tmp_a);
          }else if (calc_equation(tmp_calc_ba, tmp_calc_dc, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_b, op1, tmp_a, op3, tmp_d, op2, tmp_c);
          }else if (calc_equation(tmp_calc_dc, tmp_calc_ba, op3) == 10){
            can_make_ten = true;
            sprintf(equation, "(%1.0lf%c%1.0lf)%c(%1.0lf%c%1.0lf)", tmp_d, op2, tmp_c, op3, tmp_b, op1, tmp_a);
          }
          if (can_make_ten) break;
        }
        if (can_make_ten) break;
      }
      if (can_make_ten) break;
    }
    if (can_make_ten) break;
  }
  if (!can_make_ten){
    /* one and three */
    for (int i = 0; i < 4; i++){
      double tmp_calc_bc, tmp_calc_cb;
      double tmp_calc_bcd, tmp_calc_dbc, tmp_calc_cbd, tmp_calc_dcb;
      vector<double> tmp_group(3);

      tmp_a = group.at(i);
      for (int j = 0; j < 3; j++)
        tmp_group.at(j) = group.at((i+j+1)%4);
      can_make_ten = false;

      for (int j = 0; j < 3; j++){
        tmp_b = tmp_group.at(j % 3);
        tmp_c = tmp_group.at((j+1) % 3);
        tmp_d = tmp_group.at((j+2) % 3);
        for (auto op1 : operater){
          tmp_calc_bc = calc_equation(tmp_b, tmp_c, op1);
          tmp_calc_cb = calc_equation(tmp_c, tmp_b, op1);
          for (auto op2 : operater){
            tmp_calc_bcd = calc_equation(tmp_calc_bc, tmp_d, op2);
            tmp_calc_dbc = calc_equation(tmp_d, tmp_calc_bc, op2);
            tmp_calc_cbd = calc_equation(tmp_calc_cb, tmp_d, op2);
            tmp_calc_dcb = calc_equation(tmp_d, tmp_calc_cb, op2);
            for (auto op3 : operater){
              if (calc_equation(tmp_a, tmp_calc_bcd, op3) == 10){
                sprintf(equation, "%1.0lf%c((%1.0lf%c%1.0lf)%c%1.0lf)", tmp_a, op3, tmp_b, op1, tmp_c, op2, tmp_d);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_a, tmp_calc_dbc, op3) == 10){
                sprintf(equation, "%1.0lf%c(%1.0lf%c(%1.0lf%c%1.0lf))", tmp_a, op3, tmp_d, op2, tmp_b, op1, tmp_c);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_a, tmp_calc_cbd, op3) == 10){
                sprintf(equation, "%1.0lf%c((%1.0lf%c%1.0lf)%c%1.0lf)", tmp_a, op3, tmp_c, op1, tmp_b, op2, tmp_d);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_a, tmp_calc_dcb, op3) == 10){
                sprintf(equation, "%1.0lf%c(%1.0lf%c(%1.0lf%c%1.0lf))", tmp_a, op3, tmp_d, op2, tmp_c, op1, tmp_b);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_calc_bcd, tmp_a, op3) == 10){
                sprintf(equation, "((%1.0lf%c%1.0lf)%c%1.0lf)%c%1.0lf", tmp_b, op1, tmp_c, op2, tmp_d, op3, tmp_a);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_calc_dbc, tmp_a, op3) == 10){
                sprintf(equation, "(%1.0lf%c(%1.0lf%c%1.0lf))%c%1.0lf", tmp_d, op2, tmp_b, op1, tmp_c, op3, tmp_a);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_calc_cbd, tmp_a, op3) == 10){
                sprintf(equation, "((%1.0lf%c%1.0lf)%c%1.0lf)%c%1.0lf", tmp_c, op1, tmp_b, op2, tmp_d, op3, tmp_a);
                can_make_ten = true;
              }
              else if (calc_equation(tmp_calc_dcb, tmp_a, op3) == 10){
                sprintf(equation, "(%1.0lf%c(%1.0lf%c%1.0lf))%c%1.0lf", tmp_d, op2, tmp_c, op1, tmp_b, op3, tmp_a);
                can_make_ten = true;
              }
            }
            if (can_make_ten) break;
          }
          if (can_make_ten) break;
        }
        if (can_make_ten) break;
      }
      if (can_make_ten) break;
    }
  }
}

double calc_equation(double a, double b, char op)
{
  if (op == '+')
    return a + b;
  else if (op == '-')
    return a - b;
  else if (op == '*')
    return a * b;
  else if (b != 0)
    return a / b;
  else
    return DUMMY;
}
