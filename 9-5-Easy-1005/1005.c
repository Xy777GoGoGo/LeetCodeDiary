int cmp (const void * a, const void * b)
{
   return ( abs(*(int*)a) - abs(*(int*)b) );
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    int sum = 0;
    qsort(nums, numsSize, sizeof(int), cmp);//按照绝对值大小排序
    for(int i = numsSize - 1; i >= 0; i--){
        if(nums[i] < 0 && k > 0){
            nums[i] = abs(nums[i]);
            k--;
        }
       sum = sum + nums[i];
    }
    if(k % 2)
        return sum - 2 * nums[0];
    else
        return sum;
}
