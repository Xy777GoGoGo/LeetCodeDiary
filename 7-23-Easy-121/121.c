int maxProfit(int* prices, int pricesSize) {
    int ans = 0,a;
    for (int i = 0; i < pricesSize - 1 ; i++){
        for (int j = i + 1; j < pricesSize; j++ ){
            a = prices[j] - prices[i];
            if (a > 0 && a > ans){
                ans = a;
            }
        }
    }
    return ans;
}
//首先当然是双重for循环，但每通过全部测试，超时了
//想了一下，其实就是确定一个下标找后面最大的数，能否先排序，记录下标呢然后再找。
//感觉不对看了别人的题解
//int maxProfit(int* prices, int pricesSize){
    int maxPro = 0;
    int min = prices[0];    //先让0位置为最小
    for(int i=1; i<pricesSize; i++){
        if(prices[i] > min){
            maxPro = fmax(maxPro, prices[i] - min);   //如果后面比最小大，求差，与现有最大比取最大值
        }else if(prices[i] < min){
            min = prices[i];    //如果后面比最小还小，那么替换最小值，从这里继续算起
        }
    }
    return maxPro;
}
//1、先判断今天是不是从开始到现在的历史最低点
//2、如果不是最低点，那么如果今天卖股票的话，获利是不是最多的？最后找出获利最多的结果就行了
//感觉自己想叉了，没必要两次循环，因为当有历史最低点时，一定会从之前的天买入，因为之后一定会赚得多
