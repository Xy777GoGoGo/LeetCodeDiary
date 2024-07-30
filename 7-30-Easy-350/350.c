int cmp(const void *a, const void *b ){
    return (*(int *)a - *(int *)b);
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int min = nums1Size;
    int k = 0;
    if (nums2Size < min)
        min = nums2Size;
    int *ans = malloc(sizeof(int) * min);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int flag1 = 0, flag2 = 0;
    while(flag1 < nums1Size && flag2 < nums2Size){
        if(nums1[flag1] < nums2[flag2])
            flag1++;
        else if (nums1[flag1] > nums2[flag2])
            flag2++;
        else {
            ans[k] = nums1[flag1];
            k++;
            flag1++;
            flag2++;
        }

    }
    *returnSize = k;
    return ans;
}

