int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    //将有障碍物那个点设置为0（注意边界情况）
    int **ans = malloc(sizeof(int *) * obstacleGridSize);
    for(int i = 0; i < obstacleGridSize; i++)
        ans[i] = malloc(sizeof(int) * (*obstacleGridColSize));
    for(int i = 0; i < obstacleGridSize; i++){
        if(obstacleGrid[i][0] == 1){
            for(int j = i; j < obstacleGridSize; j++)
                ans[j][0] = 0;
            break;
        }
        ans[i][0] = 1;
    }
    for(int j = 0; j < (*obstacleGridColSize); j++){
        if(obstacleGrid[0][j] == 1){
            for(int i = j; i < (*obstacleGridColSize); i++)
                ans[0][i] = 0;
            break;
        }
        ans[0][j] = 1;
    }
    for(int i = 1; i < obstacleGridSize; i++){
        for(int j = 1; j < (*obstacleGridColSize); j++){
            if(obstacleGrid[i][j] == 1){
                ans[i][j] = 0;
                continue;
            }
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        }
    }
    return ans[obstacleGridSize - 1][(*obstacleGridColSize) - 1];
}
