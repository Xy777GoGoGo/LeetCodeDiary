//双指针
int maxArea(int* height, int heightSize) {
    int low = 0, hi = heightSize - 1, max = 0;
    while(low < hi){
        int con = (hi - low) *(height[low] > height[hi] ? height[hi] : height[low]);
        if (con > max)
            max = con;
        if(height[low] > height[hi])
            hi --;
        else    
            low ++;
    }
    return max;
}
