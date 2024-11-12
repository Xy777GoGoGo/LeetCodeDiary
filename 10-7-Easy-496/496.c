/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //单调栈
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = (int* )malloc(sizeof(int) * nums1Size);
    int* mid = (int* )malloc(sizeof(int) * nums2Size);
    int* zhan = (int* )malloc(sizeof(int) * nums2Size);
    for(int i = 0; i < nums1Size; i++)
        ans[i] = -1;
    for(int i = 0; i < nums2Size; i++)
        mid[i] = -1;
    //先每个元素的下一个更大元素算出来
    int head = 0;
    for(int j = 0; j < nums2Size; j++){
        if(head == 0){
            zhan[head ++] = j;
            continue;
        }
        if(nums2[j] <= nums2[zhan[head - 1]])
            zhan[head++] = j;
        else{
            while(head > 0 && nums2[j] > nums2[zhan[head - 1]]){
                mid[zhan[head - 1]] = nums2[j];
                head--;
            }
            //再入栈
            zhan[head++] = j;
        }
    }
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums1[i] == nums2[j])
                ans[i] = mid[j];
        }
    }
    *returnSize = nums1Size;
    return ans;

}

