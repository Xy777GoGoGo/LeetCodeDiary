int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int *robTree(struct TreeNode *node) {
    int* amounts = (int*) malloc(sizeof(int) * 2);
    memset(amounts, 0, sizeof(int) * 2);
    if(node == NULL){
        return amounts;
    }
    int * left = robTree(node->left);
    int * right = robTree(node->right);
    // 偷当前节点
    amounts[1] = node->val + left[0] + right[0];
    // 不偷当前节点
    amounts[0] = max(left[0], left[1]) + max(right[0], right[1]);
    return amounts;
}

int rob(struct TreeNode* root) {
    int * dp = robTree(root);
    // 0代表不偷当前节点可以获得的最大值，1表示偷当前节点可以获取的最大值
    return max(dp[0], dp[1]);
}

