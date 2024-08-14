bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    //只要判断是否有效，用3个hash表
    int a[9][9],b[9][9],c[9][9];//a用统计行，b是统计列,c用来统计小格子
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.' ){
                if(a[i][board[i][j] - '0' - 1] != 1)
                    a[i][board[i][j] - '0' - 1] = 1;
                else 
                    return false;
                if(b[board[i][j] - '0' - 1][j] != 1)
                    b[board[i][j] - '0' - 1][j] = 1;
                else 
                    return false;
            }
        }
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] != '.' ){
                if(c[(i / 3) *3 + j / 3][board[i][j] - '0' - 1] != 1)
                    c[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] = 1;
                else 
                    return false;
            }
        }
    }
    return true;
}
//上上面是比较笨的方法
//
