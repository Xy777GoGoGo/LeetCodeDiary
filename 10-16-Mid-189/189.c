void reverse(int* nums, int start, int end){
    int mid;
    if(start + 1 >= end)
        return;
    int i = 0;
    while(i < (end - start) / 2){
        mid = nums[start + i];
        nums[start + i] = nums[end - 1 -i];
        nums[end - 1 - i] = mid;
        i++;
    }
    // 3 , 7
}
void rotate(int* nums, int numsSize, int k) {
    reverse(nums, 0, numsSize);
    reverse(nums, 0, k % numsSize);
    reverse(nums, k % numsSize, numsSize);
}



