/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
//先层序遍历
int maxDepth(struct Node* root) {
    struct Node** que = malloc(sizeof(struct Node*) * 10000);
    int lo, hi, size, depth;
    lo = hi = depth = 0;

    if(root == NULL)
        return 0;
    else    
        que[hi++] = root;
    
    while(hi > lo){
        size = hi - lo;
        while(size --){
            struct Node* node = que[lo++];
            for(int i = 0; i < node->numChildren; i++)
                que[hi++] = node->children[i]; 
        }
        depth++;
    }
    return depth;
}

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
int k;
void dfs(struct Node* node, int depth){
    if(node == NULL)
        return;
    if (k < depth)
        k = depth;
    for(int i = 0; i < node->numChildren; i++)
        dfs(node->children[i], depth + 1);
}
int maxDepth(struct Node* root) {
    k = 0;

    if(root == NULL)
        return 0;

    dfs(root, 0);
    return k + 1;
}
