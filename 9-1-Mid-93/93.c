//记录结果
char** result;
int resultTop;
//记录应该加入'.'的位置
int segments[3];
int isValid(char* s, int start, int end) {
    if(start > end)
        return 0;
    if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
            return false;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) { // 如果大于255了不合法
            return false;
        }
    }
    return true;
}

//startIndex为起始搜索位置，pointNum为'.'对象
void backTracking(char* s, int startIndex, int pointNum) {
    //若'.'数量为3，分隔结束
    if(pointNum == 3) {
        //若最后一段字符串符合要求，将当前的字符串放入result种
        if(isValid(s, startIndex, strlen(s) - 1)) {
            char* tempString = (char*)malloc(sizeof(char) * strlen(s) + 4);
            int j;
            //记录添加字符时tempString的下标
            int count = 0;
            //记录添加字符时'.'的使用数量
            int count1 = 0;
            for(j = 0; j < strlen(s); j++) {
                tempString[count++] = s[j];
                //若'.'的使用数量小于3且当前下标等于'.'下标，添加'.'到数组
                if(count1 < 3 && j == segments[count1]) {
                    tempString[count++] = '.';
                    count1++;
                }
            }
            tempString[count] = 0;
            //扩容result数组
            result = (char**)realloc(result, sizeof(char*) * (resultTop + 1));
            result[resultTop++] = tempString;
        }
        return ;
    }

    int i;
    for(i = startIndex; i < strlen(s); i++) {
        if(isValid(s, startIndex, i)) {
            //记录应该添加'.'的位置
            segments[pointNum] = i;
            backTracking(s, i + 1, pointNum + 1);
        }
        else {
            break;
        }
    }
}

char ** restoreIpAddresses(char * s, int* returnSize){
    result = (char**)malloc(0);
    resultTop = 0;
    backTracking(s, 0, 0);
    *returnSize = resultTop;
    return result;
}
