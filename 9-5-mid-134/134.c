int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum = 0;
    int min = INT_MAX;// 从起点出发，油箱里的油量最小值
    for(int i = 0; i < gasSize; i++){
        int rest = gas[i] - cost[i];
        sum = sum + rest;
        if(sum < min)
            min = sum;
    }
    if(min >= 0)//累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点
        return 0;
    if(sum < 0)
        return -1;//如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
    for(int i = gasSize - 1; i >= 0; i--){
        int rest = gas[i] - cost[i];
        min = min + rest;
        if(min >= 0)
            return i;
    }
    return -1;
}




//累加rest[i]的和Sum一旦小于0，起始位置至少要是i+1，因为从i之前开始一定不行
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum=0, tsun = 0, ans = 0;
    for(int i = 0; i < gasSize; i++){
        int rest = gas[i] - cost[i];
        tsun = tsun + rest;
        sum = sum + rest;
        if(sum < 0){
            ans = i + 1;
            sum = 0;
        }
    }
    if(tsun < 0)
        return -1;
    return ans;
}
