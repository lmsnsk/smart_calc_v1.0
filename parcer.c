#include "s21_smart_calc.h"

void parse_3_char_oper(List** main_stack, int* result, const char* str, int* i,
                       type_t type, char c1, char c2) {
  if (str[*i + 1] == c1 && str[*i + 2] == c2) {
    int priority = (c1 == 'o' && c2 == 'd') ? 2 : 3;
    push_stack(0.0, priority, type, main_stack);
    *i += 2;
  } else
    *result = ERROR;
}

void parse_4_char_oper(List** main_stack, int* result, const char* str, int* i,
                       type_t type, char c1, char c2, char c3) {
  if (str[*i + 1] == c1 && str[*i + 2] == c2 && str[*i + 3] == c3) {
    push_stack(0.0, 3, type, main_stack);
    *i += 3;
  } else
    *result = ERROR;
}

double parse_number(const char* str, int* i, int* error, char* x) {
  double num;
  if (str[*i] == 'x') {
    sscanf(x, "%lf", &num);
    (*i)++;
  } else {
    int check_double_remainder = 0;
    int len = 0;
    int counter = *i;
    while ((str[counter] >= '0' && str[counter] <= '9') ||
           str[counter] == '.') {
      if (check_double_remainder && str[counter] == '.') *error = 1;
      if (str[counter] == '.') check_double_remainder = 1;
      len++, counter++;
    }
    char number_array[len + 1];
    for (int j = 0; j < len; j++) {
      number_array[j] = str[*i];
      (*i)++;
    }
    number_array[len] = '\0';
    sscanf(number_array, "%lf", &num);
  }
  return num;
}

void plus_minus(List** list, char* str, int i, int is_minus) {
  if (i && (str[i - 1] == ')' || is_number(str[i - 1])))
    push_stack(0.0, 1, (is_minus ? MINUS : PLUS), list);
  else {
    push_stack(0.0, 5, (is_minus ? U_MINUS : U_PLUS), list);
  }
}

void parser_switch(List** list, char* str, int* i, int* result) {
  switch (str[*i]) {
    case '(':
      push_stack(0.0, -1, O_BRACKET, list);
      break;
    case ')':
      push_stack(0.0, -1, C_BRACKET, list);
      break;
    case '+':
      plus_minus(list, str, *i, 0);
      break;
    case '-':
      plus_minus(list, str, *i, 1);
      break;
    case '*':
      push_stack(0.0, 2, MUL, list);
      break;
    case '/':
      push_stack(0.0, 2, SUB, list);
      break;
    case '^':
      push_stack(0.0, 4, EXP, list);
      break;
    case 'm':
      parse_3_char_oper(list, result, str, i, MOD, 'o', 'd');
      break;
    case 'c':
      parse_3_char_oper(list, result, str, i, COS, 'o', 's');
      break;
    case 's':
      if (str[*i + 1] == 'i') {
        parse_3_char_oper(list, result, str, i, SIN, 'i', 'n');
      } else if (str[*i + 1] == 'q') {
        parse_4_char_oper(list, result, str, i, SQRT, 'q', 'r', 't');
      } else
        *result = ERROR;
      break;
    case 't':
      parse_3_char_oper(list, result, str, i, TAN, 'a', 'n');
      break;
    case 'a':
      if (str[*i + 1] == 'c') {
        parse_4_char_oper(list, result, str, i, ACOS, 'c', 'o', 's');
      } else if (str[*i + 1] == 's') {
        parse_4_char_oper(list, result, str, i, ASIN, 's', 'i', 'n');
      } else if (str[*i + 1] == 't') {
        parse_4_char_oper(list, result, str, i, ATAN, 't', 'a', 'n');
      } else
        *result = ERROR;
      break;
    case 'l':
      if (str[*i + 1] == 'o') {
        parse_3_char_oper(list, result, str, i, LOG, 'o', 'g');
      } else if (str[*i + 1] == 'n') {
        push_stack(0.0, 3, LN, list);
        (*i)++;
      } else
        *result = ERROR;
      break;
    default:
      *result = ERROR;
  }
}

int parcer(List** list, char* str, char* x) {
  int result = OK, i = 0;
  while (str[i]) {
    if (is_number(str[i])) {
      double num;
      num = parse_number(str, &i, &result, x);
      push_stack(num, 0, NUMBER, list);
      if (str[i] == '(' || str[i] == 'x' || str[i] == 'c' || str[i] == 's' ||
          str[i] == 'a' || str[i] == 't' || str[i] == 'l') {
        push_stack(0.0, 2, MUL, list);
      }
      continue;
    }
    parser_switch(list, str, &i, &result);
    if (result) break;
    i++;
  }
  List* p = peek_stack(*list);
  if (p->priority > 0 && !p->next) result = ERROR;
  return result;
}