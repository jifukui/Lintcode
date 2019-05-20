#include <stdio.h>
int transform[10]={0,1,2,3,4,5,6,7,8,9};
int cout(int key,int value);
int main(int argc ,char **argv)
{
    if(argc==3)
    {
        int key,value,num;
        key=atoi(argv[1]);
        value=atoi(argv[2]);
        printf("输入的键值为%d\n",key);
        printf("输入的数据为%d\n",value);
        num=count(key,value);
        printf("数字%d 在从0~%d 出现的次数为%d\n",key,value,num);
    }
    else
    {
        printf("输入参数错误\n");
    }
    return 0;
}
int cout(int key,int value)
{
    int data[10];
    int i=0,n,num=0,j;
    while (value)
    {
        data[i]=value%10;
        value/=10;
    }
    for(n=0;n<i;n++)
    {
        if(0==n)
        {
            num=key>data[n]?0:1;
        }
        else
        {
            if(key>=data[n])
            {
                num+=transform[n]+data[n]-key;
            }
            else
            {
                num+=key-data[n];
            }    
        }
        
    }
    if(key==0&&i>1)
    {
        num-=10;
    }
    return num;
}