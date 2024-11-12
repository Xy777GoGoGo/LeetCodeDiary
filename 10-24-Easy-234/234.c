abool isPalindrome(struct ListNode* head) {
    // //先用o（n）空间解决
    // int mid[100000];
    // int midsize = 0;
    // struct ListNode* node = head;
    // while(node){
    //     mid[midsize++] = node->val;
    //     node = node->next;
    // }
    // //反转head
    // struct ListNode* pre = NULL;
    // struct ListNode* curr = head;
    // while(curr){
    //     struct ListNode* mid = curr->next;
    //     curr->next = pre;
    //     pre = curr;
    //     curr = mid;
    // }
    // int i = 0;
    // while(pre){
    //     if(pre->val != mid[i])
    //         return false;
    //     i++;
    //     pre = pre->next;
    // }
    // return true;
