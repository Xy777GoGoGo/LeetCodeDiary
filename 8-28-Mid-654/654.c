/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //思路比较清晰，就是递归
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if(numsSize == 0)
        return NULL;
    
    struct TreeNode* node = malloc(sizeof(struct TreeNode)); 
    node->val = 0;
    node->left = NULL;
    node->right = NULL;

    int dex, max;
    max = -1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max){
            max = nums[i];
            dex = i;
        }
    }
    node->val = max;

    node->left = constructMaximumBinaryTree(nums, dex);
    node->right = constructMaximumBinaryTree(nums + dex + 1, numsSize - dex - 1);  
    
    return node;
}
