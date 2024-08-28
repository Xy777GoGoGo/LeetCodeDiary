/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize == 0)
        return NULL;
    
    //找分割点
    int rootval = preorder[0];
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = rootval;
    node->left = NULL;
    node->right = NULL;

  //若前序遍历数组的大小为1，返回该结点
    if(preorderSize == 1)
        return node;
    //分割中序
    int dex;
    for(dex = 0; dex < inorderSize; dex++){
        if(inorder[dex] == node->val)
            break;
    }

    int right = inorderSize - 1 - dex;

    node->left = buildTree(preorder + 1, dex, inorder, dex);
    node->right = buildTree(preorder + dex + 1, right, inorder + dex + 1, right);
    return node; 
}
