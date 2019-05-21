#include <stdio.h>
int transform[10]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int val[10];
int cout(int key,int value);
int sun();
int main(int argc ,char **argv)
{
    if(argc==3)
    {
        int key,value,num;
        key=atoi(argv[1]);
        value=atoi(argv[2]);
        printf("输入的键值为%d\n",key);
        printf("输入的数据为%d\n",value);
        sum();
        num=cout(key,value);
        printf("数字%d 在从0~%d 出现的次数为%d\n",key,value,num);
    }
    else
    {
        printf("输入参数错误\n");
    }
    return 0;
}
int sum()
{
    int i=0;
    for(i;i<10;i++)
    {
        if(i==0)
        {
            val[i]=1;
        }
        else
        {
            val[i]=val[i-1]*9+transform[i];
        }
        
    }
}
int cout(int key,int value)
{
    int data[10];
    int i=0,n,num=0,j,ori;
    ori=value;
    while (value)
    {
        data[i]=value%10;
        value/=10;
        i++;
    }
    for(n=0;n<i;n++)
    {
        if(0==n)
        {
            num=key>data[n]?0:1;
        }
        else if((n+1)==i)
        {
            if(data[n]>key)
            {
                num=2*num+transform[n]+val[n-1]*(data[n]-key-1);
            }
            else
            {
                num=num+ori-data[n]*transform[n]+1;
            }    
        }
        else
        { 
            num=num+val[n]; 
        }
        
    }
    if(key==0&&i>1)
    {
        num-=10;
    }
    return num;
}