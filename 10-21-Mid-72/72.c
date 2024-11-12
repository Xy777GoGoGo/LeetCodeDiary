void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int mColSize = *matrixColSize;
    int onecol = 0, onerow = 0;
    for(int i = 0; i < mColSize; i++){
        if(matrix[0][i] == 0){
            onerow = 1;
            break;
        }
    }
    for(int j = 0; j < matrixSize; j++){
        if(matrix[j][0] == 0){
            onecol = 1;
            break;
        }
    }
    for(int i = 1; i < matrixSize; i++){
        for(int j = 1; j < mColSize; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < matrixSize; i++){
        for(int j = 1; j < mColSize; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }
    if(onerow){
        for(int i = 0; i < mColSize; i++)
            matrix[0][i] = 0;
    }
    if(onecol){
        for(int i = 0; i < matrixSize; i++)
            matrix[i][0] = 0;
    }

}
