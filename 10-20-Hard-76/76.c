bool isbelong(int* snumber, int* tnumber){
    for(int i = 0; i < 58; i++){
        if(snumber[i] < tnumber[i])
            return false;
    }
    return true;
}
char* minWindow(char* s, char* t) {
    //利用动态hash表记录滑动窗口里面的元素
    //一个head，一个tail，tail从左到右，滑到覆盖字串的时候停止，再滑动head
    int slen = strlen(s);//记录滑动窗口里面的元素
    int tlen = strlen(t);
    int head =0;
    int curstart =-1, curend = INT_MAX / 2;
    int snumber[58] = {0};
    int tnumber[58] = {0};
    for(int i = 0; i < tlen; i++)
        tnumber[t[i] - 'A']++;
    for(int tail = 0; tail < slen; tail++){//移动右界限
        snumber[s[tail] - 'A'] ++;
        while(isbelong(snumber, tnumber)){//滑动窗口覆盖
            if(tail - head < curend - curstart){
                curstart = head;
                curend = tail;
            }
            snumber[s[head] - 'A'] --;//左界限右移
            head++;
        }
    }
    if(curstart == -1)
        return "";
    s[curend + 1] = '\0';
    return s + curstart;
}
