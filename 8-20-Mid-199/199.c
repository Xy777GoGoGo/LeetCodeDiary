 //层次遍历（广度优先搜索）
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *ans  = malloc(sizeof(int) * 101);
    struct TreeNode* que[101];
    int lo = 0, hi =0, size;
    *returnSize = 0;
    if(root == NULL)
        return ans;
    else
        que[hi++] = root;
    while(hi > lo){
        size = hi - lo;
        while(size){
            struct TreeNode* node = que[lo++];
            if(node != NULL){
                if(size == 1)
                    ans[(*returnSize)++] = node->val;
                if(node->left != NULL)
                    que[hi++] = node->left;
                if(node->right != NULL)
                    que[hi++] = node->right;
            } 
            size--;
        }
    }
    return ans;
}

//深度优先搜索
//
////深度优先
int k;
void dfs(struct TreeNode* root, int depth, int *ans){
    if(root == NULL)
        return;
    if(depth > k )//如果当前节点所在深度还没有出现在其中，说明是该深度下第一个被访问的节点，加入数组
        ans[k++] = root->val;
    depth++;
    dfs(root->right, depth, ans);
    dfs(root->left, depth, ans);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *ans  = malloc(sizeof(int) * 101);
    k = 0;
    dfs(root, 1, ans);
    *returnSize = k;
    return ans;
}
