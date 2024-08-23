/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool compare(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL && right != NULL)
        return false;
    else if(left != NULL && right == NULL)
        return false;
    else if(left == NULL && right == NULL)
        return true;
    else if (left->val != right->val)
        return false;

    //剩下的是这两节点都不为空的情况，且数值相同
    //进入下层判断
    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    return outside && inside;
}
bool isSymmetric(struct TreeNode* root) {
    return compare(root->left, root->right);
}
