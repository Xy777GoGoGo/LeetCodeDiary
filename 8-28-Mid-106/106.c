/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize == 0)
        return NULL;
    
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = postorder[postorderSize - 1];

    int dex;
    for(dex = 0; dex < inorderSize; dex++){
        if(inorder[dex] == node->val)
            break;
    }

    int rightsize = inorderSize - 1 - dex;
    node->left = buildTree(inorder, dex, postorder, dex);
    node->right = buildTree(inorder + dex + 1, rightsize, postorder + dex, rightsize);
    return node;
}
