/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int returnS;
int *returnCol;
void bt(int *nums, int numsSize, int *path, int pathsize, int **ans, int *sign){
    if(pathsize > numsSize)
        return;
    if(pathsize == numsSize){
        int *tmp = (int *)malloc(sizeof(int) * numsSize);
        for(int i = 0; i < numsSize; i++)
            tmp[i] = path[i];
        ans[returnS++] = tmp;
    }
    for(int j = 0;j < numsSize; j++){
        if(sign[j] == 1)
            continue;
        else{
            sign[j] = 1;
            path[pathsize] = nums[j];
            bt(nums, numsSize, path, pathsize + 1, ans, sign);
            sign[j] = 0;//回溯
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = (int **)malloc(sizeof(int *) * 1000);
    int *path = (int *)malloc(sizeof(int *) * numsSize);
    int *sign = (int *)malloc(sizeof(int) * numsSize);
    returnS = 0;

    bt(nums, numsSize, path, 0, ans, sign);

    returnCol = (int *) malloc(sizeof(int) * returnS);
    for(int i = 0; i < returnS; i++)
        returnCol[i] = numsSize;
    *returnColumnSizes = returnCol;
    *returnSize = returnS;
    return ans;
}
