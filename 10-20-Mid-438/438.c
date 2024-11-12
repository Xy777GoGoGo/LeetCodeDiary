/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isbelong(int *pwindow, int *swindow){
    for(int i =0 ; i < 26; i++){
        if(pwindow[i] != swindow[i])
            return false;
    }
    return true;
}
int* findAnagrams(char* s, char* p, int* returnSize) {
    //滑动窗口长度固定为ptrlen（p）
    int plen = strlen(p);
    int slen = strlen(s);
    int prenode = 0;
    int* ans = malloc(sizeof(int) * slen);
    *returnSize = 0;
    if(plen > slen)
        return ans;
    int pwindow[26] = {0};
    int swindow[26] = {0};
    for(int i = 0; i < plen; i++)
        pwindow[p[i] - 'a']++;
    for(int j = 0; j < plen; j++)
        swindow[s[j] - 'a']++;
    for(int start = plen; start < slen; start++){
        if(isbelong(pwindow, swindow))
            ans[(*returnSize)++] = prenode;
        swindow[s[prenode] - 'a']--;
        prenode++;
        swindow[s[start] - 'a']++;
    }
    if(isbelong(pwindow, swindow))
        ans[(*returnSize)++] = prenode;
    return ans;
}
