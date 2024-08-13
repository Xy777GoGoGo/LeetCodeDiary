int search(int* nums, int numsSize, int target) {
    //感觉得用二分法,先找k
    //感觉上面用logn难实现，看了官方解析，不用找k
    //先将数组一分为二，必有一边为有序，再看情况查找
    if (numsSize == 1){
        if (nums[0] == target)
            return 0;
        else 
            return -1;
    }
    int lo = 0, hi = numsSize - 1, mid;
    while (lo < hi){
        mid = (hi - lo) / 2 + lo;
        if (nums[hi] == target)
            return hi;
        if (nums[mid] == target)
            return mid;
        if (nums[lo] == target)
            return lo;
        //判断需要搜索哪一边
        if(nums[lo] < nums[mid]){ //说明左边有序
            if (nums[lo] < target && target < nums[mid])//在左侧
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        else{//说明右侧有序
            if (nums[mid] < target && target < nums[hi])//在右侧
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
    }
    return -1;
}
