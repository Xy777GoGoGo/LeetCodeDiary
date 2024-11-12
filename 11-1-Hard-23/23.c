/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0 || lists == NULL)
        return NULL;
    //直观的想法，两个两个合并
    struct ListNode* newhead = malloc(sizeof(struct ListNode));
    newhead->val = 0;
    newhead->next = lists[0];

    for(int i = 1; i < listsSize; i++){
        //比较newhead 和 lists[i]
        struct ListNode* l1 = newhead->next;
        struct ListNode* l2 = lists[i];
        struct ListNode* node = newhead;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                node->next = l1;
                l1 = l1->next;
                node = node->next;
            }
            else{
                node->next = l2;
                l2 = l2->next;
                node = node->next;
            }
        }
        if(l1 == NULL)
            node->next = l2;
        else if(l2 == NULL)
            node->next = l1;
    }
    return newhead->next;
}
