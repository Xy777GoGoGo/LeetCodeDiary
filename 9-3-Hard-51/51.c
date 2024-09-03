char ***ans;
char **path;
int ansTop, pathTop;
//将path中元素复制到ans中
void copyPath(int n) {
    char **tempPath = (char**)malloc(sizeof(char*) * pathTop);
    int i;
    for(i = 0; i < pathTop; ++i) {
        tempPath[i] = (char*)malloc(sizeof(char) * n + 1);
        int j;
        for(j = 0; j < n; ++j)
            tempPath[i][j] = path[i][j];
        tempPath[i][j] = '\0';

    }
    ans[ansTop++] = tempPath;
}

//判断当前位置是否有效（是否不被其它皇后影响）
int isValid(int x, int y, int n) {
    int i, j;
    //检查同一行以及同一列是否有效
    for(i = 0; i < n; ++i) {
        if(path[y][i] == 'Q' || path[i][x] == 'Q')
            return 0;
    }
    //下面两个for循环检查斜角45度是否有效
    i = y - 1;
    j = x - 1;
    while(i >= 0 && j >= 0) {
        if(path[i][j] == 'Q')
            return 0;
        --i, --j;
    }

    i = y + 1;
    j = x + 1;
    while(i < n && j < n) {
        if(path[i][j] == 'Q')
            return 0;
        ++i, ++j;
    }

    //下面两个for循环检查135度是否有效
    i = y - 1;
    j = x + 1;
    while(i >= 0 && j < n) {
        if(path[i][j] == 'Q')
            return 0;
        --i, ++j;
    }

    i = y + 1;
    j = x -1;
    while(j >= 0 && i < n) {
        if(path[i][j] == 'Q')
            return 0;
        ++i, --j;
    }
    return 1;
}

void backTracking(int n, int depth) {
    //若path中有四个元素，将其拷贝到ans中。从当前层返回
    if(pathTop == n) {
        copyPath(n);
        return;
    }

    //遍历横向棋盘
    int i;
    for(i = 0; i < n; ++i) {
        //若当前位置有效
        if(isValid(i, depth, n)) {
            //在当前位置放置皇后
            path[depth][i] = 'Q';
            //path中元素数量+1
            ++pathTop;

            backTracking(n, depth + 1);
            //进行回溯
            path[depth][i] = '.';
            //path中元素数量-1
            --pathTop;
        }
    }
}

//初始化存储char*数组path，将path中所有元素设为'.'
void initPath(int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        //为path中每个char*开辟空间
        path[i] = (char*)malloc(sizeof(char) * n + 1);
        //将path中所有字符设为'.'
        for(j = 0; j < n; j++)
            path[i][j] = '.';
        //在每个字符串结尾加入'\0'
        path[i][j] = '\0';
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    //初始化辅助变量
    ans = (char***)malloc(sizeof(char**) * 400);
    path = (char**)malloc(sizeof(char*) * n);
    ansTop = pathTop = 0;

    //初始化path数组
    initPath(n);
    backTracking(n, 0);

    //设置返回数组大小
    *returnSize = ansTop;
    int i; 
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    for(i = 0; i < ansTop; ++i) {
        (*returnColumnSizes)[i] = n;
    }
    return ans;
}
