/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool sign;
int gethigh(struct TreeNode* node){ 
    if(node == NULL)
        return 0;
    int leftHeight = gethigh(node->left);
    if (leftHeight == -1) return -1;
    int rightHeight = gethigh(node->right);
    if (rightHeight == -1) return -1;

    int result;
    if(abs(leftHeight - rightHeight) > 1)
        result = -1;
    else
        result = 1 + (leftHeight > rightHeight ?  leftHeight : rightHeight);
    return result;
}
bool isBalanced(struct TreeNode* root) {
    //首先肯定是要遍历
    if(gethigh(root) == -1)
        return false;
    else    
        return true;

}
