a/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root){
    if(root == NULL)
        return 0;
    int leftn = dfs(root->left);
    int rightn = dfs(root->right);
    int treen = leftn + rightn + 1;
    return  treen;
}
int countNodes(struct TreeNode* root) {
    return dfs(root);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//关键思想，在完全二叉树中，如果递归向左遍历的深度等于递归向右遍历的深度，那说明就是满二叉树，
//如果整个树不是满二叉树，就递归其左右孩子，直到遇到满二叉树为止，用公式计算这个子树（满二叉树）的节点数量

int countNodes(struct TreeNode* root) {
    if(root == NULL)
        return 0;
        // 开始根据左深度和右深度是否相同来判断该子树是不是满二叉树
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    int leftdepth = 0, rightdepth = 0;
    while(left){
        left = left->left;
        leftdepth++;
    }
    while(right){
        right = right->right;
        rightdepth++;
    }
    if(leftdepth == rightdepth)
        return (2<<leftdepth) - 1;

    int leftTreen = countNodes(root->left);
    int rightTreen = countNodes(root->right);

    int result = leftTreen + rightTreen + 1;//把剩余节点加上了
    return result;
}
