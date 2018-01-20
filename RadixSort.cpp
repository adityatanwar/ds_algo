#include <bits/stdc++.h>
using namespace std;
//During First Call to radixsort(),elements are sorted acc. to their units digit
//During Second Call to radixsort(),elements are sorted acc. to their tens digit as q is increased to 10
//This goes on until sorting acc. to the most significant digit of the max. no in given array is done
//This gives us the sorted array
void radixsort(int a[],int n,int q){
    //Creating an array of size 10 and initialising it with zero
    int b[10]={};
	//Now inserting elements from array a to b according to logic
	for(int i=0;i<n;i++)
	{
      b[(a[i]/q)%10]++;
	}
    //Now finding Cumulative Sum
	for(int i=0;i<10;i++)
	{
		if(i!=0)
		{
          b[i]=b[i]+b[i-1];
		}
	}
	//Now right shifting the array b by 1 and initialising 1st element by zero
	for(int i=9;i>=0;i--)
	{
       b[i+1]=b[i];
	}
    b[0]=0;
	//Now inserting elements in array c according to logic
	int c[1000];
	for(int i=0;i<n;i++)
	{
      c[b[(a[i]/q)%10]]=a[i];
      b[(a[i]/q)%10]++;
	}
	//Copying elements from array c to array a 
	for(int i=0;i<n;i++)
	{
		a[i]=c[i];
	}
}
int main()
{
	int ar[1000],n,max=-100000,m=10,q=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		if(ar[i]>max)
		{
			max=ar[i];
		}
	}
    while(max>0)
    {   
        radixsort(ar,n,q);
        q=q*10;
    	max=max/10;
    }
    for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
}