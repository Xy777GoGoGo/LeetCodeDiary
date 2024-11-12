bool isrepeat(int *snumber){
    for(int i = 0; i < 128; i++){
        if(snumber[i] > 1)
            return true;
    }
    return false;
}
int lengthOfLongestSubstring(char* s) {
    //利用动态hash表记录滑动窗口里面的元素
    //一个head，一个tail，tail从左到右，
    int ans = -1;
    int snumber[128] = {0};
    int slen = strlen(s);
    if(slen <= 1)
        return slen;
    int head = 0;
    for(int tail = 0; tail < slen; tail++){
        snumber[s[tail]]++;
        while(isrepeat(snumber) && head < tail){//此时有重复
            snumber[s[head]]--;
            head++;
        }
        if(tail - head > ans)
            ans = tail - head;
    }
    return ans + 1;
}
