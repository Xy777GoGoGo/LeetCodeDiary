int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++)
        sum = sum + nums[i];
    if(sum % 2)
        return false;
    int weight = sum / 2;
    int ans[10001] = {0};
    for(int i = 0; i < numsSize; i ++){
        for(int j = weight; j >= nums[i]; j--){
            ans[j] = max(ans[j], ans[j - nums[i]] + nums[i]);
        }
    }
     if(ans[weight] == weight)
                return true;
    return false;
}
