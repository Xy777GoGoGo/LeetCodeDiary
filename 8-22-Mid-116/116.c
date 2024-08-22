/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	struct Node* que[4096];
    int hi, lo, size;
    hi = lo = 0;
    if(root == NULL)
        return root;
    else 
        que[hi++] = root;

    while( hi > lo){
        size = hi -lo;
        while(size){
            struct Node* node = que[lo++];
            if(size == 1)
                node->next = NULL;
            else 
                node->next = que[lo];
            if(node->left != NULL){
                que[hi++] = node->left;
                que[hi++] = node->right;
            }
            size--;
        }
    }
    return root;
}

//
//
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
//没有的话直接不用给next赋值，
struct Node* connect(struct Node* root) {
    if(root == NULL)
        return root;

    struct Node* leftmost = root;
    while(leftmost->left != NULL){
        struct Node* head = leftmost;
        while(head != NULL){
            head->left->next = head->right;
            if(head->next != NULL)
                head->right->next = head->next->left;
            head = head->next; 
        }
        leftmost = leftmost->left;
    }
    return root;
}
