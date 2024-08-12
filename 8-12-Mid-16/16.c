int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int ans, cls = 100000;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(int i = 0; i < numsSize; i++){
        int lo = i + 1, hi = numsSize - 1, sum;
        while(lo < hi){
            sum = nums[i] +  nums[lo] + nums[hi];
            if (abs(sum - target) < cls){
                cls = abs(sum - target);
                ans = sum;
            }
            if (sum > target)
                hi--;
            else if (sum < target)
                lo++;
            else
                return sum;  
        }
    }
    return ans;
}
