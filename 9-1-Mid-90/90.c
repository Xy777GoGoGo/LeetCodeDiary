/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int returnS;
int *returnCol;
int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
void bt(int *nums, int numsSize, int dex, int *path, int pathsize, int **ans){
    int *tmp =malloc(sizeof(int) * pathsize);
    for(int i =0; i < pathsize; i++)
        tmp[i] = path[i];
    returnCol[returnS] = pathsize;
    ans[returnS++] = tmp;

    if(dex >= numsSize)
        return;
    for(int j = dex; j < numsSize; j++){
        if(j > dex && nums[j] == nums[j - 1])
            continue;
        path[pathsize] = nums[j];
        bt(nums, numsSize, j + 1, path, pathsize + 1, ans);
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    //先排序
    qsort(nums, numsSize, sizeof(int), cmp);

    int **ans = (int **)malloc(sizeof(int *) * 10000);
    int *path = (int *)malloc(sizeof(int) * numsSize);
    returnCol = (int *)malloc(sizeof(int) * 10000);
    returnS = 0;

    bt(nums, numsSize, 0, path, 0, ans);
    *returnSize = returnS;
    *returnColumnSizes = returnCol;
     return ans;
}
