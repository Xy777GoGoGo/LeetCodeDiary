/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int returnS;
int *returnCol;
void bt(int *num,int numsSize, int startdex, int *path, int pathsize, int **ans){
    int *tmp = malloc(sizeof(int ) * (pathsize + 1));
        for(int j = 0; j < pathsize; j++)
            tmp[j] = path[j];
        returnCol[returnS] = pathsize;
        ans[returnS++] = tmp;
    //放在判别之前，把空集合也算进去
    if(startdex >= numsSize)
        return;
    for(int i = startdex; i < numsSize; i++){
        path[pathsize] = num[i];
        bt(num, numsSize, i + 1, path, pathsize + 1, ans);
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = (int **) malloc(sizeof(int *) * 10000);
    int *path = (int *) malloc(sizeof(int ) * 10000);
    returnCol = (int *) malloc(sizeof(int ) * 10000);
    returnS = 0;

    bt(nums, numsSize, 0, path, 0, ans);


    *returnColumnSizes = returnCol;
    *returnSize = returnS;
    return ans;
}
