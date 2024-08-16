 int ansize;
void mtraverse(struct TreeNode* root, int *ans){
    if (root == NULL) 
        return;
    mtraverse(root->left, ans);
    ans[ansize] = root->val;
    ansize ++;
    mtraverse(root->right, ans);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = (int *)malloc (sizeof (int) * 100);
    ansize = 0;
    mtraverse(root, ans);
    *returnSize = ansize;
    return ans;
}
