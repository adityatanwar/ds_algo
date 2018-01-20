#include <bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int l,int r,int k) //this gives answer in log(base2)n
{
	if(l>r)
		return -1;
	int mid=(l+r)/2;
	if(a[mid]==k)
		return mid; //returning index of k 
    if(k<a[mid])
    	return binarysearch(a,l,mid-1,k);
    if(k>a[mid])
    	return binarysearch(a,mid+1,r,k);
}
int ternarysearch(int a[],int l,int r,int k) //this gives answer in log(base3)n
{
	if(l>r)
		return -1;
	int mid1=l+(r-l)/3;
	int mid2=r-(r-l)/3;
	if(a[mid1]==k)
		return mid1; //returning index of k,incase both a[mid1] and a[mid2] are equal to k,then we'll return mid1-
    else if(mid2==k) //-that is the first position where k is found
    	return mid2;
    if(k<a[mid1])
    	return ternarysearch(a,l,mid1-1,k);
    if(k>a[mid1] && k<a[mid2])
    	return ternarysearch(a,mid1+1,mid2-1,k);
    if(k>a[mid2])
    	return ternarysearch(a,mid2+1,r,k);
}
int main()
{
	int a[1000],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k; //No. to be searched
	int indext=ternarysearch(a,0,n-1,k);
	cout<<"Answer from Ternary Search "<<indext<<endl;
	int indexb=binarysearch(a,0,n-1,k);
	cout<<"Answer from Binary Search "<<indexb<<endl;
}