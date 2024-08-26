
//关键就是遍历所有节点，找到左叶子节点
int sum;
void dfs(struct TreeNode* root){
    if(root == NULL)
        return;
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        sum = sum + root->left->val;
    dfs(root->left);
    dfs(root->right);
}
int sumOfLeftLeaves(struct TreeNode* root){
    sum = 0;
    dfs(root);
    return sum;
}

class Solution {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) {
        int ans = 0;
        if (node->left) {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};
复杂度分析

时间复杂度：O(n)，其中 n 是树中的节点个数。

空间复杂度：O(n)。空间复杂度与深度优先搜索使用的栈的最大深度相关。在最坏的情况下，树呈现链式结构，深度为 O(n)，对应的空间复杂度也为 O(n)。

方法二：广度优先搜索
C++
C++17
Java
Python3
Golang
C
bool isLeafNode(struct TreeNode *node) {
    return !node->left && !node->right;
}

int sumOfLeftLeaves(struct TreeNode *root) {
    if (!root) {
        return 0;
    }
    struct TreeNode **q = malloc(sizeof(struct TreeNode *) * 2001);
    int left = 0, right = 0;
    q[right++] = root;
    int ans = 0;
    while (left < right) {
        struct TreeNode *node = q[left++];
        if (node->left) {
            if (isLeafNode(node->left)) {
                ans += node->left->val;
            } else {
                q[right++] = node->left;
            }
        }
        if (node->right) {
            if (!isLeafNode(node->right)) {
                q[right++] = node->right;
            }
        }
    }
    return ans;
}

