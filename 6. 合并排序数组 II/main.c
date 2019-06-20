#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) ;
int main()
{
    int i,len;
    vector <int> a(1);
    vector <int> b(1);
    vector <int> c;
    c=mergeSortedArray(a,b);
    len=c.size();
    for(i=0;i<len;i++)
    {
        cout<<i<<"is"<<c[i]<<endl;
    }
}
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) 
{
        // write your code here
        vector <int> data;
        int val1,val2;
        int len1,len2;
        int i1=0,i2=0;
        int temp;
        int i,length;
        len1=A.size();
        len2=B.size();
        length=len1+len2;
        for(i=0;i<length;)
        {
            if(i1<len1&&i2<len2)
            {
                if(A[i1]>=B[i2])
                {
                    data[i++]=B[i2++];
                }
                else
                {
                    data[i++]=A[i1++];
                }
            }
            else if(i1>=len1)
            {
                for(temp=i2;temp<len2;i2++)
                {
                    data[i++]=B[i2];
                }
            }
            else if(i2>=len2)
            {
                for(temp=i1;temp<len1;i1++)
                {
                    data[i++]=A[i1];
                }
            }
            else
            {
                break;
            }
        }
        return data;
    }