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
int icpr(int * i1, int *i2, int size){
    for(int i = 0; i < size; i++){
        if(i1[i] != i2[i])
            return 0;
    }
    return 1;
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
        return ;
    }

    for(int i = dex; i < candidatesSize; i++){
        if(i > dex && candidates[i] == candidates[i - 1])
            continue;
        path[pathsize] = candidates[i];
        bt(candidates, candidatesSize, target, path, pathsize + 1, ans, i + 1);
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    int **ans = (int **)malloc(sizeof(int *) * 1000);
    returnCol = (int *)malloc(sizeof(int) * 1000);
    int *path = (int *)malloc(sizeof(int) * 1000);
    int hash[51] = {0};
    returnS = 0;

    bt(candidates, candidatesSize, target, path, 0, ans, 0);
    *returnSize = returnS;
    *returnColumnSizes = returnCol;
    return ans;
}

//去重的是“同一树层上的使用过”，判断同一树层上元素（相同的元素）是否使用过了
