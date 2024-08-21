double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double *ans = (double *) malloc(sizeof(double) * 10000);
    *returnSize = 0;
    struct TreeNode* que[10000];
    int lo = 0, hi = 0, size, k;
    double mid;

    if(root == NULL)
        return ans;
    else 
        que[hi++] = root;
    
    while(hi > lo){
        mid = 0;
        size = hi - lo;
        k = size;
        while(size--){
            struct TreeNode* node = que[lo++];
            if(node != NULL)
                mid = mid + node->val;
            if(node->left != NULL)
                que[hi++] = node->left;
            if(node->right != NULL)
                que[hi++] = node->right;  
        }
        ans[(*returnSize)++] = mid / k;
    }
    return ans;
}
//深度优先：
//


int counts[10000];
double sums[10000];
int countsSize;
int sumsSize;
 void dfs(struct TreeNode* root, int depth){
    if(root == NULL)
        return;
    if (depth < sumsSize) {
        sums[depth] += root->val;
        counts[depth] += 1;
    } else {
        sums[sumsSize++] = (double)root->val;
        counts[countsSize++] = 1;
    }
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1 );
}
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double* ans = (double *) malloc(sizeof(double) * 10000);
    *returnSize = 0;
    countsSize = sumsSize = 0;
    int k;
    if(root == NULL)
        return ans;
    dfs(root, 0);
    for(int i = 0; i < sumsSize; i++){
        ans[i] = sums[i] / counts[i];
    }
    *returnSize = sumsSize;
    return ans;
}
