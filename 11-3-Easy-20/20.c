bool isValid(char* s) {
//     int len = strlen(s);
//     char *zhan = malloc(sizeof(char) * (len + 1));
//     int index = 0;
//     int i = 0;
//     while(i < len){
//         if(s[i] == '(' || s[i] == '[' || s[i] == '{')
//             zhan[index++] = s[i];
//         else if(s[i] == ')'){
//             if(index == 0)
//                 return false;
//             if(zhan[index - 1] != '(')
//                 return false;
//             else    
//                 index--;
//         }
//         else if(s[i] == ']'){
//             if(index == 0)
//                 return false;
//             if(zhan[index - 1] != '[')
//                 return false;
//             else    
//                 index--;
//         }
//         else if(s[i] == '}'){
//             if(index == 0)
//                 return false;
//             if(zhan[index - 1] != '{')
//                 return false;
//             else    
//                 index--;
//         }
//         i++;
//     }
//     if(index == 0)
//         return true;
//     return false;
    char mp[128] = {};
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';

    int top = 0; // 直接把 s 当作栈
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (mp[c] == 0) { // c 是左括号
            s[top++] = c; // 入栈
        } else if (top == 0 || s[--top] != mp[c]) { // c 是右括号
            return false; // 没有左括号，或者左括号类型不对
        }
    }
    return top == 0; // 所有左括号必须匹配完毕

 }
