bool sign;
void bt(char** board, int index, int m, int n, int mmax, int nmax, char* word, int** mid){
    int len = strlen(word);
    if(index >= len)
        return;
    if(board[m][n] != word[index])
        return;
    mid[m][n] = 1;
    if(index == len - 1){//3
        sign = true;
        return;
    }
    //向上
    if(m > 0 && mid[m - 1][n] == 0){
        bt(board, index + 1, m - 1, n, mmax, nmax, word, mid);
        mid[m - 1][n] = 0;
    }
    //向下
    if(m < mmax - 1 && mid[m + 1][n] == 0){
        bt(board, index + 1, m + 1, n, mmax, nmax, word, mid);
        mid[m + 1][n] = 0;
    }
    //向左
    if(n > 0 && mid[m][n - 1] == 0){
        bt(board, index + 1, m, n - 1, mmax, nmax, word, mid);
        mid[m][n - 1] = 0;
    }
    if(n < nmax - 1 && mid[m][n + 1] == 0){
        bt(board, index + 1, m, n + 1, mmax, nmax, word, mid);
        mid[m][n + 1] = 0;
    }
    mid[m][n] = 0;//每个循环结束应该恢复原状
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize, n = (*boardColSize);
    int **mid = malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++){
        int *hang = malloc(sizeof(int) * n);
        memset(hang, 0, sizeof(int) * n);
        mid[i] = hang;
    }
    sign = false;
    if( m * n < strlen(word))
        return false;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(word[0] == board[i][j]){
                bt(board, 0, i, j, m, n, word, mid);
            }
        }
    }
    return sign;
}
