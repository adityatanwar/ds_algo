#include <iostream>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
int main()
{
	unordered_map<int,bool> mymap;
	unordered_map<int,bool>::iterator it;
	int a[6]={1,2,3,4,5,6};
	int b[6]={5,4,5,9,7,8};
	//insert in hashmap
	for(int i=0;i<6;i++)
	{
		pair<int,bool> p;
		p.first=a[i];
		p.second=true;
		//mymap[a[i]]=true;
		mymap.insert(p);
	}
	//search
	for(int i=0;i<6;i++)
	{
		if(mymap.count(b[i])==1) //this function checks if b[i] exists or not,if it does then it gives 1 otherwise 0
			cout<<b[i]<<" ";
	}
	//Now logic for finding union,insert all the elements in unordered_map,keys should be unique so duplicate elements get 
	//removed and we are left with the union of the two sets.
	for(int i=0;i<6;i++)
	{
		pair<int,bool> p;
		p.first=b[i];
		p.second=true;
		//mymap[a[i]]=true;
		mymap.insert(p);
	}
	it=mymap.begin();
	while(it!=mymap.end())
	{
        cout<<it->first;
		it++;
	}

}