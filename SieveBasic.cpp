#include <bits/stdc++.h>
using namespace std;
//Sieve of Eratosthenes-Basic
//Time Complexity(NloglogN)
int primeupton(int n)
{   
	int size=n;
	size++;
	int a[size]={}; //initialising array to 0
	for(int i=2;i*i<size;i++)
	{
		if(a[i]==0)  
		{
          int j=2;
          while(true)
          {
          	int cur=i*j;
          	if(cur<size)a[cur]=1;
          	if(cur>=size) break;
            j++;
          }
		}
	}
	for(int i=2;i<size;i++)
	{
		if(a[i]==0)
			 cout<<i<<" ";
	}
}
int main()
{
  int n;
  cin>>n;
  primeupton(n);
}