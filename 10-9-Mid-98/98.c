/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int size;
void zbianli(struct TreeNode* node, int* mid){
    if(node == NULL)
        return;
    zbianli(node->left, mid);
    mid[size++] = node->val;
    zbianli(node->right, mid);
}
bool isValidBST(struct TreeNode* root) {
    //中序遍历就是递增
    //也就是对层次遍历转化为中序遍历
    int *mid  = malloc(sizeof(int) * 10000);
    size = 0;
    zbianli(root, mid);
    for(int i = 0; i < size - 1; i++){
        if(mid[i] >= mid[i + 1])
            return false;
    }
    return true;
}
