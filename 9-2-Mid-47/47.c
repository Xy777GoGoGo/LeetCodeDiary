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
        int s ;
        for(int j = 0; j < returnS; j++){
            s = 0;
            for(int l = 0; l < numsSize; l++){
                if(ans[j][l] == path[l])
                    s++;
            }
            if( s == numsSize)
                return;
        } 

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
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
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






/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int returnS;
int *returnCol;
int cmp(int *a, int *b){
    return(*(int *)a - *(int *)b);
}
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
        if(j > 0 && nums[j] == nums[j-1] && sign[j - 1] ==0)//注意这里的判别
            continue;
        sign[j] = 1;
        path[pathsize] = nums[j];
        bt(nums, numsSize, path, pathsize + 1, ans, sign);
        sign[j] = 0;//回溯
    }

}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = (int **)malloc(sizeof(int *) * 1000);
    int *path = (int *)malloc(sizeof(int *) * numsSize);
    int *sign = (int *)malloc(sizeof(int) * numsSize);
    returnS = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    bt(nums, numsSize, path, 0, ans, sign);

    returnCol = (int *) malloc(sizeof(int) * returnS);
    for(int i = 0; i < returnS; i++)
        returnCol[i] = numsSize;
    *returnColumnSizes = returnCol;
    *returnSize = returnS;
    return ans;
}
