#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,bool> check;
	for(int i=0;i<n;i++)
	{
		check[a[i]]=true;
	}
	map<int,bool>::iterator it;
    int i=0;
	for(it=check.begin();it!=check.end();it++,i++)
	{
     a[i]=it->first; 
	}
	cout<<"*"<<i<<"*";
	for(int j=0;j<i;j++)
	{
		cout<<a[j];
	}
}