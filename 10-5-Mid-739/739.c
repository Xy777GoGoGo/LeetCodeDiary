/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置
 //此时我们就要想到可以用单调栈了
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    //单调栈
    int* ans = (int *) malloc(sizeof(int) * temperaturesSize);
    memset(ans, 0, sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    int* zhan  = (int *) malloc(sizeof(int) * temperaturesSize);
    int high = 0;
    zhan[high ++] = 0;
    for(int i = 1; i < temperaturesSize; i++){
        if(temperatures[i] <= temperatures[zhan[high - 1]])
            zhan[high++] = i;
        else{
            while(high > 0 &&temperatures[i] > temperatures[zhan[high - 1]]){
                    ans[zhan[high - 1]] = i - zhan[high - 1];
                    high--;
                //出栈，说明找到比他大的了
            }
            //入栈
            zhan[high++] = i;
        }
              
    }

    return ans;
}
