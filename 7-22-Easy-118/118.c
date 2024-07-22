#include<stdio.h>
#include<stdlib.h>
//对我来说开辟空间以及返回值比较难做

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int *) * numRows);//开辟numRows个int*型，返回正确答案
    *returnSize = numRows;//返回的数组的个数是numRows个
    *returnColumnSizes = malloc(sizeof(int) * numRows);//开辟每个数组中的空间
    for (int i = 1; i <= numRows; i++){
        ans[i - 1] = (int *)malloc (sizeof(int) * i);
        (*returnColumnSizes)[i - 1] = i;
        //返回数组的第i - 1的数组大小为i
        ans[i - 1][0] = 1;
        ans[i - 1][i - 1] = 1; //两边都为1
        if(i > 2){
        for (int j = 1; j < i - 1  ; j++ )
            ans[i-1][j] = ans[i-2][j-1] + ans[i-2][j];
        }
    }
    return ans;
}
