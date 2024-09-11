int max(int a, int b){
    if(a > b)
        return a;
    return b;
}
int lastStoneWeightII(int* stones, int stonesSize) {
    int sum = 0;
    for(int i = 0; i < stonesSize; i++)
        sum = sum + stones[i];
    int weight = sum / 2;
    int ans[15000] = {0};
    for(int i = 0; i < stonesSize; i++){
        for(int j = weight; j >= stones[i]; j--){
            ans[j] = max(ans[j], ans[j - stones[i]] + stones[i]);
        }
    }
    return sum - 2*ans[weight];
}
