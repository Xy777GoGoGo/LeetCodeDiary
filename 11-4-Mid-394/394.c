char* decodeString(char* s) {
    //栈
    char *ans = malloc(sizeof(char) * 9000);
    int len;

    int slen = strlen(s);
    
    char *zhan = malloc(sizeof(char) * 9000);
    int top = 0;
    int size;
    for(int i = 0; i < slen; i++){
        if(s[i] != ']')
            zhan[top++] = s[i];//入栈
        else{
            //遇到了]
            len = 0;
            while(zhan[top - 1] != '['){
                ans[len++] = zhan[top - 1];
                top--;
            }
            //ans 暂时存储需要复制的字符串（倒序）
            top--;
            //此时top指向[
            int index = 1;
            size = 0;
            while(top > 0 && zhan[top - 1] >= '0' && zhan[top - 1] <= '9'){
                //说明需要重复，得看看具体数字是多少
                size = (zhan[top - 1] - '0') * index + size;
                index = index * 10;
                top--;
            }
            //这时size存储着需要重复的次数，top指向数字的首位
            if(size > 0){
                //说明字符串需要重复size次
                for(int i = len; i < len * size; i++)
                    ans[i] = ans[i - len];
                len = len * size;
            }
            //把ans中的字符串从后往前压入栈
            for(int i = len - 1; i >= 0; i--)
                zhan[top++] = ans[i];
        }
    }
    //最后把栈中的数据复制到ans
    for(int i = 0; i < top; i++)    
        ans[i] = zhan[i];
    ans[top] = '\0';
    return ans;
}
