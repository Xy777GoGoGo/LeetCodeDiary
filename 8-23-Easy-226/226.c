/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
*/

//思路就是反转每个节点的左右节点，遍历就行
void inv(struct TreeNode* node){
    if(node->left != NULL || node->right != NULL){
        struct TreeNode* mid;
        mid = node->left;
        node->left = node->right;
        node->right = mid;
    }
    if(node->left !=  NULL)
        inv(node->left);
    if(node->right != NULL)
        inv(node->right);
}
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
        return root;
    inv(root);
    return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
        return root;

    struct TreeNode* mid;
        mid = root->left;
        root->left = root->right;
        root->right = mid;
    invertTree(root->left);
    invertTree(root->right);

    return root;
}
//因为是先前序遍历，所以先进行交换左右孩子节点，然后反转左子树，反转右子树。
