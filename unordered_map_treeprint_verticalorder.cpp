#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;
class node
{
	public:
		int data;
	node* left;
	node* right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
node* maketree()
{
	int d;
	cin>>d;
	if(d==-1)
		return NULL;
	node*root=new node(d);
	root->left=maketree();
	root->right=maketree();
	return root;
} 
void fillmap(unordered_map<int,vector<int> > &mymap,node* root,int d)
{
   if(root==NULL)
   	return;
   mymap[d].push_back(root->data);
   fillmap(mymap,root->left,d-1);
   fillmap(mymap,root->right,d+1);
}
int main()
{
	node* root=maketree();
	unordered_map<int,vector<int> > mymap;
	fillmap(mymap,root,0);
    for(int key=-2;key<=3;key++)
    {
    	for(vector<int>::iterator it=mymap[key].begin();it!=mymap[key].end();it++)
    		cout<<*it;
    	cout<<endl;
    }

}