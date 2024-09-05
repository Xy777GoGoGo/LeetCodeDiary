int jump(int* nums, int numsSize) {
    int ans = 0;
    if(numsSize == 1)
        return ans;
    int nextarr = 0, nowarr = 0;
    for(int i = 0; i < numsSize; i++){
        int l = i + nums[i];
        if(nextarr < l)
            nextarr = l;
        if(i == nowarr){//到达当前范围最后一个
            ans ++;
            nowarr = nextarr;
        if(nextarr > numsSize - 2)
            break;
        }
    }
    return ans;
}
