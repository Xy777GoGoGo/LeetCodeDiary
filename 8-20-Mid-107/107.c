int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
     int **ans = (int **)malloc(sizeof(int *) * 2001);
    *returnSize = 0;
    int columnSizes[2001];
    struct TreeNode *que[2001];//维护一个队列
    int hi = 0, lo = 0;
    int size,sum ;
    if(root == NULL)
        return ans;
    else{//入队列
        que[hi++] = root;
    }

    while(hi > lo){
        int k = 0;
        size = hi - lo;//当前队列大小
        columnSizes[(*returnSize)] = size; 
        int * tmp = (int *) malloc(sizeof(int ) * size); 
        while(size--){
            //下面出队列
            struct TreeNode * node = que[lo++];
            if (node != NULL){
                tmp[k++] = node->val;
            }
            if (node->left){
                que[hi++] = node->left;//入队列
            }
            if(node ->right){
                que[hi++] = node->right;//入队列
            }
        }
        ans[(*returnSize)++] = tmp;
    }
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
     for(int i=0; i<(*returnSize);i++){
        (*returnColumnSizes)[i]=columnSizes[(*returnSize) - i - 1];
     }
     for(int i=0; 2 * i<(*returnSize);i++){
        int* tm=(int*)malloc(sizeof(int)*2005);
        tm = ans[i];
        ans[i] = ans[(*returnSize) - i - 1];
        ans[(*returnSize) - i - 1] = tm;
     }
    return ans;
}
