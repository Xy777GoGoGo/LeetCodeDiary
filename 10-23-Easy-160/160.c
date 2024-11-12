/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //从直接末尾开始呗
    struct ListNode* nowA = malloc(sizeof(struct ListNode));
    nowA = headA;
    struct ListNode* nowB = malloc(sizeof(struct ListNode));
    nowB = headB;
    if(nowA == NULL || nowB == NULL)
        return NULL;
    while(true){
        if(nowA == nowB)
            return nowA;
        nowA = nowA->next;
        nowB = nowB->next;
        if(nowA == NULL && nowB == NULL)
            return NULL;
        if(nowA == NULL)
            nowA = headB;
        if(nowB == NULL)
            nowB = headA;
    }
}
