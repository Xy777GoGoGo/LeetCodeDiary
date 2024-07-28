//首先想到的是排序
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int missingNumber(int* nums, int numsSize) {
    //排序
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    for(int i = 0;i < numsSize; i++){
        if  (i != nums[i])
            return i;
    }
    return numsSize;
}

/*hash
 * int missingNumber(int* nums, int numsSize) {
  //hash表
  int map[numsSize + 1];
  memset(map, 0, sizeof(map));
  for (int i = 0; i < numsSize; i++)
    map[nums[i]] = 1;
  for (int i = 0; i <= numsSize; i++){
    if (map[i] == 0)
        return i;
  }
  return -1;
}


int missingNumber(int* nums, int numsSize) {
  //位运算
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans = ans ^ nums[i] ^(i+1);
    }
    return ans;
}



int missingNumber(int* nums, int numsSize) {
  //数学
    int ans = 0;
    for(int i = 0; i < numsSize; i++){
        ans = ans + nums[i];
    }
    return numsSize * (numsSize + 1) / 2 - ans;
}`
