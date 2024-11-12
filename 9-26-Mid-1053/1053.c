int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp[nums1Size][nums2Size];
    memset(dp, 0, sizeof(int) * nums1Size * nums2Size);
    //下面初始化：
    for(int j = 0; j < nums2Size; j++){
        if( nums1[0] == nums2[j]){
            for(int k = j; k < nums2Size; k++)
                dp[0][k] = 1;
            break;
        }
    }
    for(int i = 0; i < nums1Size; i++){
        if(nums2[0] ==  nums1[i]){
            for(int k = i; k < nums1Size; k++)
                dp[k][0] = 1;
            break;
        }
    }
    for(int i = 1; i < nums1Size; i++){
        for(int j = 1; j < nums2Size; j++){
            if( nums1[i] == nums2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[nums1Size - 1][nums2Size - 1];
}
