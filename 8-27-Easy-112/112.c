/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//先深度
bool sign;
void bfs(struct TreeNode* root, int targetSum, int top, int* path){
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL){
        int num = 0;
        for(int i = 0; i < top; i++)
            num = num + path[i];
        if(num + root->val == targetSum)
            sign = true;
    }
    else{
        path[top++] = root->val;
   //    que[top++] = root;
        bfs(root->left, targetSum, top, path);
        bfs(root->right, targetSum, top, path);
    }
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
 //   struct TreeNode ** que = malloc(sizeof(struct TreeNode*) * 5000);
    int *path = malloc(sizeof(int) * 5000);
    int top = 0;
    sign = false;
    bfs(root, targetSum, top, path);
    return sign;
}




///
//
//
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//并不要遍历整棵树

bool bfs(struct TreeNode* root, int count){
    if(root->left == NULL && root->right == NULL && count == 0)
        return true;
    if(root->left == NULL && root->right == NULL)
        return false;
    if(root->left != NULL)
        if(bfs(root->left, count - root->left->val))//回溯的话count不变
            return true;
    if(root->right != NULL)
        if(bfs(root->right, count - root->right->val))
            return true;
    return false;
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
 //   struct TreeNode ** que = malloc(sizeof(struct TreeNode*) * 5000);
    if(root == NULL)
        return false;
    return bfs(root, targetSum - root->val);
}

