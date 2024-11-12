/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc (const void *a, const void *b)
{
    int *intervalX = *((int **)a);
    int *intervalY = *((int **)b);
    int ret = intervalX[0] - intervalY[0];

    if (ret == 0) {
        ret = intervalX[1] - intervalY[1];
    }

    return ret;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int *) * intervalsSize);
    int returnsize = 0;
    int *returnColumn = malloc(sizeof(int ) * intervalsSize);
    int *returnCol = malloc(sizeof(int ) * 2);
    for(int i = 0; i < intervalsSize; i++)
        returnColumn[i] = 2;
    //排序
    qsort(intervals, intervalsSize, sizeof(int) * 2, cmpfunc);

    ans[returnsize] = intervals[0];
    int j = 1;
    while(j < intervalsSize){
        //此时j区间不需要合并
        returnCol = intervals[j];
        if(ans[returnsize][1] < intervals[j][0]){
            returnsize++;
            ans[returnsize] = returnCol;
            j++;
        }
        else if(ans[returnsize][1] >= intervals[j][0] && ans[returnsize][1] < intervals[j][1]){//此时该区间需要合并
            returnCol[0] = ans[returnsize][0];
            returnCol[1] = intervals[j][1];
            ans[returnsize] = returnCol;
            j ++;
        }
        else
            j++;
    }
    *returnSize = returnsize  + 1;
    *returnColumnSizes = returnColumn;
    return ans;
}
