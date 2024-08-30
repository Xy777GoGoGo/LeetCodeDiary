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




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int returnS;
int *returnCol;
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
void bt(int* candidates, int candidatesSize, int target, int *path, int pathsize, int **ans, int dex){
    int sum = 0;
    for(int i = 0; i < pathsize; i++)
        sum = sum + path[i];
    if(sum > target)
        return;
    else if(sum == target){
        int *tmp = (int *) malloc(sizeof(int) * pathsize);
        for(int i = 0; i < pathsize; i++)
            tmp[i] = path[i];
        ans[returnS] = tmp;
        returnCol[returnS++] = pathsize;
    }

    for(int i = dex; i < candidatesSize; i++){
        path[pathsize] = candidates[i];
        bt(candidates, candidatesSize, target, path, pathsize + 1, ans, i);
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
     qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    int **ans = (int **)malloc(sizeof(int *) * 1000);
    returnCol = (int *)malloc(sizeof(int) * 1000);
    int *path = (int *)malloc(sizeof(int) * 1000);
    returnS = 0;

    bt(candidates, candidatesSize, target, path, 0, ans, 0);
    *returnSize = returnS;
    *returnColumnSizes = returnCol;
    return ans;
}
