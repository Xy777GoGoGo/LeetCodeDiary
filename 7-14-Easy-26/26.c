int removeDuplicates(int* nums, int numsSize) {
     //暴力
     int k = 0;int a[numsSize];//用另外一个数组存储
     if (numsSize == 1)
        return 1;
     for (int i = 0 ; i < numsSize - 1; i++){
            if(nums[i] == nums[i + 1])
                a[k] = nums[i]; //保留第一个
            if(nums[i] < nums[i + 1]){
                a[k] = nums[i];
                k++;
                a[k] = nums[i + 1];
            }
     }
     for (int i = 0; i <= k; i++){
        nums[i] = a[i];//给原数组
     }
     return k + 1;
}
/*用时最少
 * int removeDuplicates(int* nums, int numsSize) {
    int k=1;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]!=nums[i-1])//判断前一个是否和后一个相等
        {
            nums[k++]=nums[i];//因为第一个可以不动，只需要管后面的
        }
    }
    return k;
}
