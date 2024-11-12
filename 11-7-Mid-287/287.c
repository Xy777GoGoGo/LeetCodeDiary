int findDuplicate(int* nums, int numsSize) {
    //定义 cnt[i] 表示 nums 数组中小于等于 i 的数有多少个，假设我们重复的数是 target，
    //那么 [1,target−1]里的所有数满足 cnt[i]≤i，[target,n] 里的所有数满足 cnt[i]>i，具有单调性
    int l = 1, r = numsSize - 1, ans = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        int cut = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] <= mid)
                cut++;
            //计算中间mid对应的cut
        }
        if(cut <= mid){
            //说明   mid <= target−1
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}
