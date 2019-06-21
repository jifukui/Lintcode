#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) ;
int main()
{
    int i, len;
	vector <int> a(4);
	vector <int> b(4);
	vector <int> c;
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	b[0] = 2;
	b[1] = 4;
	b[2] = 5;
	b[3] = 6;
	c = mergeSortedArray(a, b);
	len = c.size();
	for (i = 0; i<len; i++)
	{
		cout << i << "is" << c[i] << endl;
	}
	return 0;
}
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) 
{
        // write your code here
        vector <int> data;
	int len1, len2;
	int i1 = 0, i2 = 0;
	int temp;
	int i, length;
	len1 = A.size();
	len2 = B.size();
	length = len1 + len2;
	for (i = 0; i<length;)
	{
		if (i1<len1&&i2<len2)
		{
			if (A[i1] >= B[i2])
			{
				data.push_back(B[i2++]);
				i++;
			}
			else
			{
				data.push_back(A[i1++]);
				i++;
			}
		}
		else if (i1 >= len1)
		{
			for (temp = i2; temp<len2; temp++)
			{
				data.push_back(B[i2++]);
				i++;
			}
		}
		else if (i2 >= len2)
		{
			for (temp = i1; temp<len1; temp++)
			{
				data.push_back(A[i1++]);
				i++;
			}
		}
		else
		{
			break;
		}
	}
	return data;
    }