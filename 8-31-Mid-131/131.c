/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** path;
int pathTop;
char*** ans;
int ansTop = 0;
int* ansSize;

//将path中的字符串全部复制到ans中
void copy() {
    //创建一个临时tempPath保存path中的字符串
    char** tempPath = (char**)malloc(sizeof(char*) * pathTop);
    int i;
    for(i = 0; i < pathTop; i++) {
        tempPath[i] = path[i];
    }
    //保存tempPath
    ans[ansTop] = tempPath;
    //将当前path的长度（pathTop）保存在ansSize中
    ansSize[ansTop++] = pathTop;
}

//判断字符串是否为回文字符串
bool isPalindrome(char* str, int startIndex, int endIndex) {
    //双指针法：当endIndex（右指针）的值比startIndex（左指针）大时进行遍历
    while(endIndex >= startIndex) {
        //若左指针和右指针指向元素不一样，返回False
        if(str[endIndex--] != str[startIndex++])
            return 0;
    }
    return 1;
}

//切割从startIndex到endIndex子字符串
char* cutString(char* str, int startIndex, int endIndex) {
    //开辟字符串的空间
    char* tempString = (char*)malloc(sizeof(char) * (endIndex - startIndex + 2));
    int i;
    int index = 0;
    //复制子字符串
    for(i = startIndex; i <= endIndex; i++)
        tempString[index++] = str[i];
    //用'\0'作为字符串结尾
    tempString[index] = '\0';
    return tempString;
}

void backTracking(char* str, int strLen,  int startIndex) {
    if(startIndex >= strLen) {
        //将path拷贝到ans中
        copy();
        return ;
    }

    int i;
    for(i = startIndex; i < strLen; i++) {
        //若从subString到i的子串是回文字符串，将其放入path中
        if(isPalindrome(str, startIndex, i)) {
            path[pathTop++] = cutString(str, startIndex, i);
        }
        //若从startIndex到i的子串不为回文字符串，跳过这一层 
        else {
            continue;
        }
        //递归判断下一层
        backTracking(str, strLen, i + 1);
        //回溯，将path中最后一位元素弹出
        pathTop--;
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes){
    int strLen = strlen(s);
    //因为path中的字符串最多为strLen个（即单个字符的回文字符串），所以开辟strLen个char*空间
    path = (char**)malloc(sizeof(char*) * strLen);
    //存放path中的数组结果
    ans = (char***)malloc(sizeof(char**) * 40000);
    //存放ans数组中每一个char**数组的长度
    ansSize = (int*)malloc(sizeof(int) * 40000);
    ansTop = pathTop = 0;

    //回溯函数
    backTracking(s, strLen, 0);

    //将ansTop设置为ans数组的长度
    *returnSize = ansTop;
    //设置ans数组中每一个数组的长度
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int i;
    for(i = 0; i < ansTop; ++i) {
        (*returnColumnSizes)[i] = ansSize[i];
    }
    return ans;
}
