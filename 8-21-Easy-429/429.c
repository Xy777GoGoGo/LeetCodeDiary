#define MAX_LEVE_SIZE 1000
#define MAX_NODE_SIZE 10000
//自己写的一直报栈溢出，完全蚌埠住
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int ** ans = (int **)malloc(sizeof(int *) * MAX_LEVE_SIZE);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_LEVE_SIZE);
    if (!root) {
        *returnSize = 0;
        return ans;
    }
    struct Node ** queue = (struct Node **)malloc(sizeof(struct Node *) * MAX_NODE_SIZE);
    int head = 0, tail = 0;
    int level = 0;
    queue[tail++] = root;

    while (head != tail) {
        int cnt = tail - head;
        ans[level] = (int *)malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; ++i) {
            struct Node * cur = queue[head++];
            ans[level][i] = cur->val;
            for (int j = 0; j < cur->numChildren; j++) {
                queue[tail++] = cur->children[j];
            }
        }
        (*returnColumnSizes)[level++] = cnt;
    }
    *returnSize = level;
    free(queue);
    return ans;
}

