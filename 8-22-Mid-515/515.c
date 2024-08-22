/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    int * ans = malloc(sizeof(int) * 10000);
    struct TreeNode* que[10000];
    int hi, lo, size;
    hi = lo = 0;
    *returnSize = 0;
    long long max;
    
    if(root == NULL)
        return ans;
    else
        que[hi++] = root;

    while(hi > lo){
        size = hi - lo;
        max = LLONG_MIN;
        while(size--){
            struct TreeNode* node = que[lo++];
            if(node->val > max)
                max = node->val;
            if(node->left != NULL)
                que[hi++] = node->left;
            if(node->right != NULL)
                que[hi++] = node->right;
        }
        ans[(*returnSize)++] = max;
    }
    return ans;
}



//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int anssize;
void dfs(struct TreeNode* root, int depth, int* ans){
    if(root == NULL)
        return;
    if(anssize < depth)
        ans[++anssize] = root->val;
    else{
        if(root->val > ans[depth])
            ans[depth] = root->val;
    }
    if(root->right != NULL)
        dfs(root->right, depth + 1, ans);
    if(root->left != NULL)
        dfs(root->left, depth + 1, ans);
}
int* largestValues(struct TreeNode* root, int* returnSize) {
    int * ans = malloc(sizeof(int) * 10000);
    anssize = - 1;
    dfs(root, 0, ans);
    *returnSize = anssize + 1;
    return ans;
}
