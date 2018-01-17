#include <bits/stdc++.h>
using namespace std;
class graph
{
	int v;
	int e;
	list<int> *adjlist;
	public:
	graph(int vertices)
	{
		v=vertices;
		e=0;
		adjlist=new list<int>[v];
	}
	void addedge(int u,int v,bool bidirectional=true)
	{
      if(bidirectional==true)
      {	
      	adjlist[u].push_back(v);
      	adjlist[v].push_back(u);
      	e=e+2;
      }
      else if(bidirectional==false)
      {
      	adjlist[u].push_back(v);
      	e++;
      }
	}
	void bfsprint(int src)
	{
		bool* visited=new bool[v];
		for(int i=0;i<v;i++)
		{
			visited[i]=false;
		}
		queue<int> q;
		q.push(src);
		visited[src]=true;
		while(!q.empty())
		{
			int f=q.front();
			cout<<f<<" ";
			for(list<int>::iterator it=adjlist[f].begin();it!=adjlist[f].end();it++)
			{
				if(visited[*it]==false)
					{
						visited[*it]=true;
						q.push(*it);
					}
			}
     	}
    }
    void shortespath(int src,int des)
    {
    	int *dist=new int[v];
    	int *parent=new int[v];
    	for(int i=0;i<v;i++)
    	{
    		dist[i]=-1;
    		parent[i]=-1;
    	}
    	dist[src]=0;
    	queue<int> q;
    	q.push(src);
    	while(!q.empty())
    	{
    		int f=q.front();
    		for(list<int>::iterator it=adjlist[f].begin();it!=adjlist[f].end();it++)
    		{
    			if(dist[*it]==-1)
    			{	
    				dist[*it]=dist[f]+1;
    				parent[*it]=f;
    				q.push(*it);
    			}
    		}
    		q.pop();
    	}
    	cout<<"Distance is "<<dist[des]<<" units";
    	cout<<"\nPath is:\n";
    	int i=des;
    	while(i!=-1)
    	{
    		cout<<i<<"<--";
    		i=parent[i];
    	}
    }
     void topologicalsort()
  {
    int *indegree=new int[v];
    for(int i=0;i<v;i++)
    {
      indegree[i]=0;
    }
    for(int i=0;i<v;i++) //traversing the whole adjacency list and setting the degrees
    {
      for(list<int>::iterator it=adjlist[i].begin();it!=adjlist[i].end();i++)
      {
        indegree[*it]++;
      }
    }
    queue<int> q; //pushing elements having zero indegree in queue
    for(int i=0;i<v;i++)
    {
      if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty()) //now pick the front element of queue,traverse its adjacency list and decrement indegree of elements in its 
    {                 //adjacency list by 1.Now check of the element whose degree has been reduced has indegree==0.if yes then,push
      int f=q.front();//it into the queue else do nothing.
      cout<<f<<" ";
      q.pop();
      for(list<int>::iterator it=adjlist[f].begin();it!=adjlist[f].end();it++)
      {
        indegree[*it]--;
        if(indegree[*it]==0)
          q.push(*it);
      }
    }
  }	
};
int main()
{
  // int v=37;
  // graph g(v);
  // int board[v]={0}; //Important to initalise the whole board with zero.
  // board[2]=13;
  // board[5]=2;
  // board[9]=18;
  // board[18]=11;
  // board[17]=-13;
  // board[20]=-14;
  // board[24]=-8;
  // board[25]=10;
  // board[32]=-2;
  // board[34]=-22;
  // for(int i=1;i<=36;i++)
  // {
  // 	for(int dice_throw=1;dice_throw<=6;dice_throw++)
  // 	{
  //    if(i+dice_throw<=36)
  //    	{
  //    		int cur_des=i+dice_throw;
  //    		int final_des=cur_des+board[cur_des];
  //    		g.addedge(i,final_des,false);
  //    	}
  // 	}
  // }
  // g.shortespath(1,36);
	// int v,e;
	// cin>>v>>e;
	// graph g(v);
	// int x,y;
	// for(int i=0;i<e;i++)
	// {
	// 	cout<<"\nAdd "<<i+1<<"th Edge:";
	// 	cin>>x>>y;
	// 	g.addedge(x,y);
	// }
	// int src,des;
	// cin>>src>>des;
	// g.shortespath(src,des);
  graph g(7);
  g.addedge(1,2,false);
  g.addedge(1,3,false);
  g.addedge(0,4,false);
  g.addedge(0,3,false);
  g.addedge(2,5,false);
  g.addedge(3,5,false);
  g.addedge(4,5,false);
  g.addedge(4,6,false);
  //g.dfsprint(1);
  g.bfsprint(0);
}