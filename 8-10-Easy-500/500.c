#include<stdio.h>
#include<string.h>
void main(){
		char *words[4]={"Hello","Alaska","Dad","Peace"};
    char a[] = "23321222122233111121131313";//行号字符串
    int k = 0;
    for(int i = 0; i < 4; i ++){
        char dup[20];
        strcpy(dup, words[i]);
        int len = strlen(dup);
        for (int j = 0; j < len; j ++){
            if(dup[j] < 'a')
                dup[j] = words[i][j] + 32;  
         }//变成小写
        char sign1 = a[dup[0] - 'a'];
				int sign2 = 1;
				printf(" sign1:%c\n",sign1);
        for (int j = 1; j < len; j ++){
				        printf(" dup:%c\n",dup[j]);
							 printf(" dup;%d\n",dup[i] - 'a');	
            if (a[dup[j] - 'a'] != sign1){
                sign2 = 0;
                break;
             }
         }
         if(sign2){
           // ans[k] = words[i];
            k++;
						printf("k :%d\n",k);
        }
     }    
}
