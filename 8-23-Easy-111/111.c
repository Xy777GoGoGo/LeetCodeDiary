/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int k ;
 void dfs(struct TreeNode* node, int depth){
    if(node == NULL)
        return;
    if(node->left == NULL && node->right == NULL){
        if(k == 0 || k > depth)
            k = depth;
    }
    if(node->left != NULL)
        dfs(node->left, depth + 1);
    if(node->right != NULL)
        dfs(node->right, depth + 1);
 }
int minDepth(struct TreeNode* root) {
    k = 0;
    if(root == NULL)
        return 0; 
    dfs(root, 0);
    return k + 1;
}
