int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    //上下相同减一，邻接减一
    int m = 0, k = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if (grid[i][j] == 1){
                k++;
                if ( j + 1 < *gridColSize && grid[i][j+1] == 1)
                    m++;
            }
        }
    }
    for(int j = 0; j < *gridColSize; j++){
        for(int i = 0; i < gridSize - 1; i++){
            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == 1)
                m++;
        }
    }
    return 4*k - 2*m;
}
//深度优先搜索
//我们也可以将方法一改成深度优先搜索遍历的方式，此时遍历的方式可扩展至统计多个岛屿各自的周长。需要注意的是为了防止陆地格子在深度优先搜索中被重复遍历导致死循环，我们需要将遍历过的陆地格子标记为已经遍历过，下面的代码中我们设定值为 2 的格子为已经遍历过的陆地格子。

int dfs(int x, int y, int** grid, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return 1;
    }
    if (grid[x][y] == 2) {
        return 0;
    }
    grid[x][y] = 2;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        res += dfs(tx, ty, grid, n, m);
    }
    return res;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                ans += dfs(i, j, grid, n, m);
            }
        }
    }
		return ans;
}
