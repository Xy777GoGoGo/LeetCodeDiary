/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode* stk[100];
    int top = 0;
    int ansize = 0;
    int *ans = malloc(sizeof(int) * 100);
    if (root == NULL){
        *returnSize = 0;
        return ans;
    }
    struct TreeNode* node;
    stk[top++] = root;
    while(top > 0){
        //出栈
        node = stk[--top];
        if(node != NULL){
        ans[ansize++] = node->val;
        if(node->right != NULL)
            stk[top++] = node->right;
        if(node->left != NULL)
            stk[top++] = node->left;
        }
    }
    *returnSize = ansize;
    return ans;

}
//
//
//看后序遍历，先序遍历是中左右，后序遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了
///**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode* stk[100];
    int mid,top = 0;
    int ansize = 0;
    int *ans = malloc(sizeof(int) * 100);
    if (root == NULL){
        *returnSize = 0;
        return ans;
    }
    struct TreeNode* node;
    stk[top++] = root;
    node = root;
    while(top > 0){
        node = stk[--top];
        if(node != NULL){
        ans[ansize++] = node->val;
        if(node->left != NULL)
            stk[top++] = node->left;
        if(node->right != NULL)
            stk[top++] = node->right;
        }
    }
    //反转ans
    for(int i = 0; i < ansize / 2; i++){
        mid = ans[i];
        ans[i] = ans[ansize - 1 - i];
        ans[ansize - 1 - i] = mid;
    }
    *returnSize = ansize;
    return ans;
}


//
//
//
//
///**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    //先找到树中最左端的节点（一直向左），路径上的节点都入栈，找到后出栈，返回上一节点，如果该节点有右孩子，该节点先出栈，再让该孩子入栈。
    struct TreeNode* stake[100];
    struct TreeNode* node;
    int* ans = malloc(sizeof(int ) * 100);
    int top = 0;
    *returnSize = 0;
    if( root == NULL)
        return ans;

    //看了答案和之前思路有点差距
    //这个思路是，先找到整棵树最左下边， 然后出栈，如果该节点有右孩子，则入栈，入栈之后又是找该右孩子的最左边的，妙
    node = root;
    while(node !=NULL || top > 0){
        if(node != NULL){
            stake[top++] = node;
            node = node->left;
        }
        else{
            node = stake[top - 1];
            top -- ;
            ans[(*returnSize)++] = node->val;
            node = node->right;
        }
    }
    return ans;
}
