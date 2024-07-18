/*给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
   for(int i=digitsSize-1;i>=0;i--)
   {
       if(digits[i]+1==10)
       {
           digits[i]=0;//判断进位
       }
       else
       {
           digits[i]=digits[i]+1;
           *returnSize=digitsSize;//不用进位的话直接返回
           return digits;
       }
   }
    *returnSize=digitsSize+1; //这时所有位都要进位
    int *ret=(int*)malloc(sizeof(int)*(digitsSize+1));//开辟空间
    memset(ret,0,sizeof(int)*(digitsSize+1));//将0赋值给所有元素
    ret[0]=1;
    return ret;
}

//参考了别人的思路，其他大差不差
