int candidatesSize_tmp;

int ansSize;

int combineSize;

int* ansColumnSize;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
void dfs(int* candidates, int target, int** ans, int* combine, int idx) {
    if (idx == candidatesSize_tmp)
        return;
    if (target == 0) {
        int* tmp = malloc(sizeof(int) * combineSize);
        for (int i = 0; i < combineSize; ++i) {
            tmp[i] = combine[i];
        }
        ans[ansSize] = tmp;//赋值给返回值
        ansColumnSize[ansSize++] = combineSize;//返回数组的列数
        return;
    }
    // 直接跳过
    dfs(candidates, target, ans, combine, idx + 1);
    // 选择当前数
    if (target - candidates[idx] >= 0) {
        combine[combineSize++] = candidates[idx];
        dfs(candidates, target - candidates[idx], ans, combine, idx);
      //  combineSize--;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    candidatesSize_tmp = candidatesSize;
    ansSize = combineSize = 0;
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    int** ans = malloc(sizeof(int*) * 1001);
    if (candidates[0] > target){
        *returnSize = 0;
        return ans;
    }
    ansColumnSize = malloc(sizeof(int) * 1001);
    int combine[2001];
    dfs(candidates, target, ans, combine, 0);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSize;
    return ans;
}
