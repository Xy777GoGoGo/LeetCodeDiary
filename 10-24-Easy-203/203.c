/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    //先找到不相同的头节点；
    if(head == NULL)
        return NULL;
    struct ListNode* nhead = head;
    while(nhead && nhead->val == val)
        nhead = nhead->next;
    if(nhead == NULL)
        return NULL;
    struct ListNode* node = nhead;
    //遍历整个链表
    while(node && node->next){
        while(node->next && node->next->val == val)
            node->next = node->next->next;
        node = node->next;
    }

    return nhead;
}
