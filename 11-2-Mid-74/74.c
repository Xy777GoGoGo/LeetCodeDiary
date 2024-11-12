bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    //先对列进行二分查找，确定在哪一行
    //再对行进行二分查找
    int high = 0, left = 0;
    int low = matrixSize - 1, right = (*matrixColSize) - 1;
    while(high <= low){
        int mid1 = high + (low - high) / 2;
        if(target > matrix[mid1][0])
            high = mid1 + 1;
        else if(target < matrix[mid1][0])
            low = mid1 - 1;
        else 
            return true;
    }
    //在low这一行了
    if(low < 0)
        return false;
    while(left <= right){
        int mid2 = left + (right - left) / 2;
        if(target > matrix[low][mid2])
            left = mid2 + 1;
        else if(target < matrix[low][mid2])
            right = mid2 - 1;
        else 
            return true;
    }
    if(matrix[low][right] != target)
        return false;
    return true;
}
