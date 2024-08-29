/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int returnS;
void bt(int k, int n, int top, int* path, int **ans, int dex){
    if(top > k)
        return;
    if(top == k){
        int sum = 0;
        for(int i = 0 ; i < k; i++)
            sum = sum + path[i];
        if(sum == n){
            int *tmp = malloc(sizeof(int) * k);
            for(int i = 0; i < k; i++)
                tmp[i] = path[i];
            ans[returnS ++] = tmp;
            return;
        }       
    }

    for(int i = dex; i <= 9; i++){
        path[top++] = i;
        bt(k, n, top, path, ans, i + 1);
        top--;
    }
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int **ans = (int **) malloc(sizeof(int * ) * 10000);
    int *path = malloc(sizeof (int) * (k+ 1));
    returnS = 0;
     bt(k, n, 0, path, ans, 1);
    *returnColumnSizes = malloc(sizeof (int) * returnS);
    for(int i = 0; i < returnS; i++)
        (*returnColumnSizes)[i] = k;
    *returnSize = returnS;
    return ans;
}
