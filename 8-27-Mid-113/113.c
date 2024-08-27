int** ret;
int retSize;
int* retColSize;

int* path;
int pathSize;

void dfs(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return;
    }
    path[pathSize++] = root->val;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL && targetSum == 0) {
        int* tmp = malloc(sizeof(int) * pathSize);
        memcpy(tmp, path, sizeof(int) * pathSize);
        ret[retSize] = tmp;
        retColSize[retSize++] = pathSize;
    }
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    pathSize--;
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    ret = malloc(sizeof(int*) * 2001);
    retColSize = malloc(sizeof(int) * 2001);
    path = malloc(sizeof(int) * 2001);
    retSize = pathSize = 0;
    dfs(root, targetSum);
    *returnColumnSizes = retColSize;
    *returnSize = retSize;
    return ret;
}
