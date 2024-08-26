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
void dfs(struct TreeNode* root, char **ans, int *returnSize, int *sta, int top){
    if (root != NULL){
        if(root->left == NULL && root->right == NULL){
            char* tmp = (char *)malloc(101);
            int len = 0;
            for(int i = 0; i < top; i++)
                len += sprintf(tmp + len, "%d->", sta[i]);//前面是指向一个字符数组的指针，该数组存储了 C 字符串,后面这是字符串，包含了要被写入到字符串 str 的文本，如果成功，则返回写入的字符总数，不包括字符串追加在字符串末尾的空字符
            sprintf(tmp + len, "%d", root->val);
            ans[(*returnSize)++] = tmp;
        }
        else{
            sta[top ++] = root->val;//先是1入栈，
            dfs(root->left, ans, returnSize, sta, top);//随后2也入栈，5没有入栈，这时写入1 2 5
            dfs(root->right, ans, returnSize, sta, top);//3没有入栈，写入 1 3（因为top为1） 妙！
        }
    }
    
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    char ** ans = malloc(sizeof(int *) * 100);
    int sta[100];
    dfs(root, ans, returnSize, sta, 0);
    return ans;
}

////////////

