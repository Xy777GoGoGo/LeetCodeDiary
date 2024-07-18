int searchInsert(int* nums, int numsSize, int target) {
    //第一反应是二分法
    int lo, hi;
    lo = 0; hi = numsSize - 1;
    if (nums[lo] > target)
        return 0;
    if (nums[hi] < target)
        return numsSize;//判断是否超出整个数组
    while ( lo <= hi){
       int mid = (lo + hi) / 2;
        if(nums[mid] > target)
            hi = mid - 1;//左边区间
        else if(nums[mid] < target)
            lo = mid + 1 ;//右边区间
        else    
            return mid;   
    }
    return hi + 1;
    //此时若target范围在[lo , hi]之中，但数组无该元素，发现循环继续，
    //直到hi = lo，而mid由于除法特性偏向前面，导致lo变成 lo + 1，循环结束
    //这时就得返回 hi + 1 或者 lo
}
//这也算是运行速度最快的  内存优化也没有更好的办法了
