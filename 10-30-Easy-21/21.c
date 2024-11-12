/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //以list2为本，插入list1
    struct ListNode* newhead = malloc(sizeof(struct ListNode));
    newhead->val = 0;
    newhead->next = NULL;
    struct ListNode* node = newhead;
    struct ListNode* mid = newhead;
    while(list1 != NULL && list2 != NULL){
        //比较list1和list2指向的节点
        if(list1->val <= list2->val){
            mid = list1->next;
            node->next = list1;
            node = node->next;
            list1 = mid;
        }
        else{
            mid = list2->next;
            node->next = list2;
            node = node->next;
            list2 = mid;
        }        
    }
    if(list1 == NULL)
        node->next = list2;
    if(list2 == NULL)
        node->next = list1;
    return newhead->next;
}





struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    else if(list1->val < list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
