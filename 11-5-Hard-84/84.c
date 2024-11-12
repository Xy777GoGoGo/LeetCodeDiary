int largestRectangleArea(int* heights, int heightsSize) {
    //记录了下标其实对应的高度就可以直接从输入数组中得出，因此，应该记录的是下标。
    //遍历一遍元素，确定每个hieghts【i】对应的最大
    //头尾都加入哨兵结点0
    //每遇到一个小的元素，出栈，说明以前一位元素为高的矩形找不到了
    int *newheights = malloc(sizeof(int) * (heightsSize + 2));
    for(int i = 1; i < heightsSize + 1; i ++)
        newheights[i] = heights[i - 1];
    newheights[0] = 0;
    newheights[heightsSize + 1] = 0;
    //   放入哨兵结点
    int ans = 0;

    int *zhan = malloc(sizeof(int) * (heightsSize + 2));
    //栈里面存的是下标
    //还得找向左的界限
    int top = 0;
    for(int i = 0; i < heightsSize + 2; i++){
        if(top == 0 || newheights[i] > newheights[zhan[top - 1]]){
            //相邻相等的不要入栈            
            zhan[top++] = i;
            continue;
        }
        //下标入栈
        //下面说明遇到了小的情形
        while(newheights[i] < newheights[zhan[top - 1]]){
            //此时右边界就是i,左边界是[zhan[top - 2]，注意我们入栈的条件
            int mid = (i - zhan[top - 2] - 1) * newheights[zhan[top - 1]];
            if(ans < mid)
                ans = mid;
            //出栈
            top --;
        }
        //再把i入栈
        zhan[top++] = i;
    }
    return ans;
}
