//双指针和单调栈
int imin(int a, int b){
    if(a < b)
        return a;
    return b;
}
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int trap(int* height, int heightSize) {
    //对每一个坐标，要找到它的左边最高以及右边最高的柱形
    //必须得优化
    //每一个位置的左边最高高度记录在一个数组上（maxLeft）
    //右边最高高度记录在一个数组上（maxRight）
    int ans = 0, mid;
    int* maxLeft = malloc(sizeof(int) * heightSize);
    int* maxRight = malloc(sizeof(int) * heightSize);
    maxLeft[0] = height[0];
        for (int i = 1; i < heightSize; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // 记录每个柱子右边柱子最大高度
    maxRight[heightSize - 1] = height[heightSize - 1];
        for (int i = heightSize - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }

    for(int i = 0; i < heightSize; i++){
        if(imin(maxLeft[i], maxRight[i]) - height[i] > 0)
            ans = ans + imin(maxLeft[i], maxRight[i]) - height[i];
    }
    return ans;
}

int trap(int* height, int heightSize) {
    int n = heightSize;
    if (n == 0) {
        return 0;
    }
    int ans = 0;
    int stk[n], top = 0;
    for (int i = 0; i < n; ++i) {
        while (top && height[i] > height[stk[top - 1]]) {
            int stk_top = stk[--top];
            if (!top) {
                break;
            }
            int left = stk[top - 1];
            int currWidth = i - left - 1;
            int currHeight = fmin(height[left], height[i]) - height[stk_top];
            ans += currWidth * currHeight;
        }
        stk[top++] = i;
    }
    return ans;
}

