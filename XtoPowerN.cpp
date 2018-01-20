#include <bits/stdc++.h>
using namespace std;
int powerofx(int x,int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return powerofx(x*x,n/2);
	else if(n%2!=0)
		return x*powerofx(x*x,(n-1)/2);
}
int main()
{
  int x,n;
  cin>>x>>n;
  cout<<powerofx(x,n);
}