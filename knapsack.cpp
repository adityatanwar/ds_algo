#include <iostream>
using namespace std;
//This function returns the maximum profit
int knapsack(int weightofgood[],int valueofgood[],int W,int n)
{
	//n denotes size of weightofgood[](no. of items available) and W denotes capacity of sack/bag
	if(n==0 || W==0)
		return 0;
	//We'll try to solve the problem from end
	if(weightofgood[n]<=W)
	{
		int including=valueofgood[n]+knapsack(weightofgood,valueofgood,W-weightofgood[n],n-1);
		int excluding=knapsack(weightofgood,valueofgood,W,n-1);
		return max(including,excluding);
	}
	if(weightofgood[n]>W)
	{
      return knapsack(weightofgood,valueofgood,W,n-1);
	}
}
int knapsackdp(int weightofgood[],int valueofgood[],int W,int n)
{
	//considering W as column and n as row
	int dp[n+1][W+1];
	//if weight of sack is 0
	for(int i=0;i<n+1;i++) 
		dp[i][0]=0;
	//if no. of items available is 0
	for(int i=0;i<W+1;i++) 
		dp[0][i]=0;
	for(int items=1;items<W+1;items++)
	{
		for(int wt=1;wt<n+1;wt++)
		{
			if(weightofgood[items-1]<=wt)
			{
				int including=valueofgood[items-1]+dp[items-1][W-weightofgood[items-1]];
				int excluding=dp[items-1][W];
				dp[items][wt]=max(including,excluding);
			}
			if(weightofgood[items-1]>wt)
			{
				dp[items][wt]=dp[items-1][wt];
			}
		}
	}	
	return dp[n][W];	
}
int main()
{
  int goods[]={15,5,3,2,10};
  int values[]={1000,50,100,10,20};
  cout<<"Items worth Rs "<<knapsack(goods,values,12,5)<<" stolen"<<endl;
  cout<<"Items worth Rs "<<knapsackdp(goods,values,12,5)<<" stolen";
}