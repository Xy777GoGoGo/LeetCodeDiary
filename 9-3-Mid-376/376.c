

int wiggleMaxLength(int* nums, int numsSize){
    int ans = 1;
    int next = 0;
    if(numsSize == 1)
        return 1;
    for(int i = 1; i < numsSize; i++){
        if(next == 0 && nums[i] - nums[i - 1] != 0)
            ans++;
        if(nums[i] - nums[i - 1] > 0 && next > 0)
            ans++;
        if(nums[i] - nums[i - 1] < 0 && next < 0)
            ans++;
        if(nums[i] - nums[i - 1] > 0)
            next = -1;
        if(nums[i] - nums[i - 1] < 0)
            next = 1;
    }
    return ans;
}
