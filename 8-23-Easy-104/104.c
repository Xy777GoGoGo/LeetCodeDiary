/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int lo, hi, size, depth;
    struct TreeNode** que = malloc (sizeof(struct TreeNode *) * 10000);
    lo = hi = depth = 0;
    if(root == NULL)
        return depth;
    else 
        que[hi++] = root;

    while(hi > lo){
        size = hi - lo;
        while(size--){
            struct TreeNode* node = que[lo++];
            if(node->left != NULL)
                que[hi++] = node->left;
            if(node->right != NULL)
                que[hi++] = node->right;
        }
        depth++;
    }
    return depth; 
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
int k;
void dfs(struct TreeNode* node, int depth){
    if(node == NULL)
        return ;
    if(depth > k)
        k = depth;
    if(node->left)
        dfs(node->left, depth+1);
    if(node->right)
        dfs(node->right, depth+1);
}
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    k = 0;
    dfs(root, 0);
    return k + 1;
}
