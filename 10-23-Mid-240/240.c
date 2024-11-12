
//右上角开始
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int index = (* matrixColSize) - 1;
    int i= 0;
    while(index >= 0 && i < matrixSize){
        if(target > matrix[i][index]){
            //说明不在该排
            i++;
        }
        else if(target < matrix[i][index]){
            //说明不在该列 
            index--;
        }
        else    
            return true;
    }
    return false;
}
