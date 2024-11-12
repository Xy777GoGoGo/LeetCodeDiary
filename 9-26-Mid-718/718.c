int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //题目的意思是得连续
    //1.dp[i][j]:对于以nums1[i]为结尾和以nums2[j]为结尾的最长公共子数组
    //2.递推公式：
    //
    //4.初始化：
    // dp[0][0] = 1 如果两个元素相等dp[0][1] ~~~~~dp[0][nums2Size]
    int dp[nums1Size][nums2Size];
    memset(dp, 0, sizeof(int) * nums1Size * nums2Size);
    int result = 0;
    //下面初始化：
    for(int j = 0; j < nums2Size; j++){
        if(nums1[0] == nums2[j]){
            dp[0][j] = 1;
            result = 1;
        }
    }
    for(int i = 0; i < nums1Size; i++){
        if(nums2[0] == nums1[i]){
            dp[i][0] = 1; 
            result = 1;
        }
    }
    for(int i = 1; i < nums1Size; i++){
        for(int j = 1; j < nums2Size; j++){
            if(nums1[i] == nums2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            if(result < dp[i][j])
                result = dp[i][j];
        }
    }
    return result;
}
