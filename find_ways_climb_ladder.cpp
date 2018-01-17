//As This problem can be broken into a similar subproblem which involves solving a subproblem that was solved
//earlier again,hence it can be solved with DP
#include <iostream>
using namespace std;
int topdowndp(int n,int ans[])
{
  if(ans[n]!=-1)
  	return ans[n];
  if(n==1)
  {
    ans[1]=1;
    return 1;
  }	
  if(n==2)
  {
    ans[2]=2;
    return 2;
  }
  if(n==3)
  {
  	ans[3]=4;
  	return 4;
  }	
  else
  	return (topdowndp(n-1,ans)+topdowndp(n-2,ans)+topdowndp(n-3,ans));
}
int bottomupdp(int n,int ans[])
{
	ans[1]=1;
	ans[2]=2;
	ans[3]=4;
	for(int i=4;i<=n;i++)
	{
		ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
	}

	return ans[n];
}
int findways(int n)
{
  if(n==1)
  	return 1;
  if(n==2)
  	return 2;
  if(n==3)
  	return 4;
  else
  	return findways(n-1)+findways(n-2)+findways(n-3);
}
int main()
{
   int n,ans[1000];
   for(int i=1;i<1000;i++)
   {
   	ans[i]=-1;
   }
   cin>>n;
   cout<<findways(n)<<endl;
   cout<<topdowndp(n,ans)<<endl;
   cout<<bottomupdp(n,ans)<<endl;
   return 0;
}