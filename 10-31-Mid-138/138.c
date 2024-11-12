/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    struct Node* node = head;
    if(node == NULL)
        return NULL;
    //一次遍历创建复制节点
	while(node != NULL){
        struct Node* mid = malloc(sizeof(struct Node));
        mid->val = node->val;
        mid->next = node->next;
        mid->random = NULL;

        node->next = mid;
        node = mid->next;
    }
    //二次遍历修正random指针
    struct Node* newhead = malloc(sizeof(struct Node));
    newhead->next = head;
    newhead->random = NULL;
    newhead->val = 0;

    struct Node* pre = newhead;
    while(head != NULL){
        if(head->random != NULL)
            head->next->random = head->random->next;//节点的random以完成
        pre->next = head->next;
        pre = pre->next;
        head = pre->next;
    }
    return newhead->next;
}
