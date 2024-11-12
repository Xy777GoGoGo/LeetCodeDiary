/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int matrixcolsize = *matrixColSize;
    *returnSize = matrixSize * matrixcolsize;
    int *ans = malloc(sizeof(int) * matrixSize * matrixcolsize);
    memset(ans, 0, sizeof(int) * matrixSize * matrixcolsize);
    int circle = 0;
    int sumsize = 0;
    //分四个阶段
    while(true){
        //1.从左到右
        for(int j = 0 + circle; j < matrixcolsize - circle; j++){
            ans[sumsize ++] = matrix[0 + circle][j];
            if(sumsize == (*returnSize))
                return ans;
        }
        //2.从上到下
        for(int i = 1 + circle; i < matrixSize - circle; i++){
            ans[sumsize ++] = matrix[i][matrixcolsize - 1 - circle];
            if(sumsize == (*returnSize))
                return ans;
        }
        //3.从右到左
        for(int j = matrixcolsize - 2 - circle; j >= 0 + circle; j--){
            ans[sumsize ++] = matrix[matrixSize - 1 -circle][j];
            if(sumsize == (*returnSize))
                return ans;
        }
        //4.从下到上
        for(int i = matrixSize - 2 - circle; i >= 1 + circle; i--){
            ans[sumsize ++] = matrix[i][0 + circle];
            if(sumsize == (*returnSize))
                return ans;
        }
        circle++;
   
