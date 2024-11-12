int findMin(int* nums, int numsSize) {
    //比较第一个和最后一个元素
    int ans = nums[0];
    //说明旋转直接转回去了
    if(nums[0] < nums[numsSize - 1])
        return nums[0];
    //下面说明旋转之后
    else{
        int left = 0, right = numsSize - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) 
                right = mid;
            else    
                left = mid + 1;
        }
        ans = nums[left];
    }
    return ans;
}
