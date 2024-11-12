//递归回溯求解，注意减枝
#define MAX_SIZE 1430
void generate(int left, int right, int n, char *str, int index, char **result, int *returnSize) {
  if (left == n && right == n) {  //左右括号都用完
    result[(*returnSize)] =  (char*)calloc((2 * n + 1), sizeof(char));
    strcpy(result[(*returnSize)++], str);
    return;
  }

  if (left < n) {  //当左括号没用完时
    str[index] = '(';
    generate(left + 1, right, n, str, index + 1, result, returnSize);
  }
  if (left > right && right < n) {  //右括号数量必须小于左括号，否则一定不合法，且右括号没有用完
    str[index] = ')';
    generate(left, right + 1, n, str, index + 1, result, returnSize);
  }
}

char **generateParenthesis(int n, int *returnSize) {
  char *str = (char*)calloc((2 * n + 1), sizeof(char));
  char **result = (char **)malloc(sizeof(char *) * MAX_SIZE);
  *returnSize = 0;
  generate(0, 0, n, str, 0, result, returnSize);
  return result;
}

