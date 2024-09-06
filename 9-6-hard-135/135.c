//该数组两次，处理出每一个学生分别满足左规则或右规则时，最少需要被分得的糖果数量。
//每个人最终分得的糖果数量即为这两个数量的最大值。
int candy(int* ratings, int ratingsSize) {
    int ans = 0;
    int *left = (int *) malloc (sizeof(int) * ratingsSize);
    left[0] = 1;
    for(int i = 1; i < ratingsSize; i++){
        if(ratings[i - 1] < ratings[i])
            left[i] = left[i - 1] + 1;
        else 
            left[i] = 1;
    }
    int mid = 0;
    for(int j = ratingsSize - 1; j >= 0; j--){
        if( j < ratingsSize - 1 && ratings[j] > ratings[j + 1])
            mid ++;
        else 
            mid = 1;
        ans = ans + fmax(mid, left[j]);
    }
    return ans;
}




int candy(int* ratings, int ratingsSize) {
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] >= ratings[i - 1]) {//说明在递增数列中
            dec = 0;  //当前递减序列长度
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;//判别两分数是否相等（前一个同学分得的糖果数量）
            ret += pre; //返回值加上
            inc = pre;//记录递增数列长度
        } else {
            dec++;//说明在递减序列
            if (dec == inc) {//两个序列长度相等
                dec++;//递减序列 加一
            }
            ret += dec;
            pre = 1;
        }
    }
    return ret;
}int candy(int* ratings, int ratingsSize) {
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] >= ratings[i - 1]) {//说明在递增数列中
            dec = 0;  //当前递减序列长度
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;//判别两分数是否相等（前一个同学分得的糖果数量）
            ret += pre; //返回值加上
            inc = pre;//记录递增数列长度
        } else {
            dec++;//说明在递减序列
            if (dec == inc) {//两个序列长度相等
                dec++;//递减序列 加一
            }
            ret += dec;
            pre = 1;
        }
    }
    return ret;
}
