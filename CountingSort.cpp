#include <bits/stdc++.h>
using namespace std;
// Counting Sort-Watch CS Dojo
int main()
{
	int a[1000],n,max=-10000;
	cin>>n;
	//Finding Max and Getting Input
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
	}
    //Creating an array of size max+1 and initializing it with zero
    int b[max+1]={};
	//Now inserting elements from array a to b according to logic
	for(int i=0;i<n;i++)
	{
      b[a[i]]++;
	}
    //Now finding Cumulative Sum
	for(int i=0;i<max+1;i++)
	{
		if(i!=0)
		{
          b[i]=b[i]+b[i-1];
		}
	}
	//Now right shifting the array b by 1 and initialising 1st element by zero
	for(int i=max-1;i>=0;i--)
	{
       b[i+1]=b[i];
	}
    b[0]=0;
	int c[1000];
	//Now inserting elements in array c according to logic
	for(int i=0;i<n;i++)
	{
      c[b[a[i]]]=a[i];
      b[a[i]]++;
	}
	//Output of array
	for(int i=0;i<n;i++)
	{
		cout<<c[i]<<" ";
	}
}