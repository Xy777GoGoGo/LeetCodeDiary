#define MAX_NODE_SIZE 10000

int findBottomLeftValue(struct TreeNode* root){
    int ret;
    struct TreeNode** queue = (struct TreeNode **)malloc(sizeof(struct TreeNode) * MAX_NODE_SIZE);
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    while (head != tail) {
        struct TreeNode *p = queue[head++];
        if (p->right) {
            queue[tail++] = p->right;
        }
        if (p->left) {
            queue[tail++] = p->left;
        }
        ret = p->val;
    }
    free(queue);
    return ret;
}
////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//深度优先
//maxLen用来记录最大深度，ans记录最大深度最左节点的数值
int ans, maxLen;
void dfs(struct TreeNode* root, int depth){
    if(root->left== NULL && root->right == NULL){
        if(depth > maxLen){
            maxLen = depth;
            ans = root->val;
        }
        return ;
    }
    if(root->left != NULL){
        depth++;
        dfs(root->left, depth);
        depth--;
    }
    if(root->right != NULL){
        depth++;
        dfs(root->right, depth);
        depth--;
    }
    return;
}
int findBottomLeftValue(struct TreeNode* root) {
    maxLen = -1;
    dfs(root, 0);
    return ans;
}
