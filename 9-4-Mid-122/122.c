int maxProfit(int* prices, int pricesSize) {
    int ans= 0;
    for(int i = 0; i < pricesSize - 1; i++){
        int l = prices[i + 1] - prices[i];
        if(l > 0)
            ans = ans + l;
    }
    return ans;
}
