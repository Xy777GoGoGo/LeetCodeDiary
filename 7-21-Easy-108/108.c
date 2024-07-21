//瞅了一眼网上的思路：
//我们知道，中序遍历序列的中点一定是二叉树的根，对于奇数个来说，就是中间那个，对于偶数个来说，中间两个都可以作为根，我们可以先找到这个根，然后把这个序列分为左右两个部分，左边是一个有序序列，那么左边的中点就是根的左子树，右边的中点就是根的右子树，这两个子树同样也可以看作下面那些子树的根，所以，我们只要不断地取数列的中点，不断的递归调用，就能完成这个创建平衡搜索二叉树的过程，为什么这样创建的一定是平衡的呢？
//因为左边的个数和右边的个数相差绝对不会超过1，如果是偶数个，选择中点后，左右两边相差1，如果是奇数个，选择中点后，左右个是相等的。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode TreeNode;
struct TreeNode* balance(int* nums, int left, int right){
    if(left > right) return NULL;

    int mid = (left + right) / 2;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root -> val = nums[mid];
    root -> left = balance(nums, left, mid - 1);
    root -> right = balance(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return balance(nums, 0, numsSize - 1);
}
