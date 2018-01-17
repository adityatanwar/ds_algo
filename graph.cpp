#include <iostream>
#include <queue>
#include <list>
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
  void addedge(int u,int v,bool bidirectional=true) //default value of bidirectional has been kept true,so if nothing is passed
  {                                                 //it takes true
  	if(bidirectional==true)
  	{
  		adjlist[u].push_back(v);
  		adjlist[v].push_back(u);
  		e=e+2;  //2 edges have been added
  	}
  	else if(bidirectional==false)
  	{
       adjlist[u].push_back(v);
       e++;     //only 1 edge has been added
  	}
  }
  void bfsprint()
  {
  	queue<int> q;
  	bool *visited=new bool[v];
  	for(int i=0;i<v;i++)
  	{
  		visited[i]=false;
  	}
  	q.push(0);
  	visited[0]=true;
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
  		q.pop();
  	}
  }
  void shortestpath(int src,int des)
  {
  	int *dist=new int[v];
  	int *parents=new int[v];
  	for(int i=0;i<v;i++)
  	{
  		dist[i]=-1;
  		parents[i]=-1;
  	}
  	queue<int> q;
  	q.push(src);
  	dist[src]=0;
  	while(!q.empty())
  	{
  		int parent=q.front();
  		for(list<int>::iterator it=adjlist[parent].begin();it!=adjlist[parent].end();it++)
  		{
          if(dist[*it]==-1)
          {
          	dist[*it]=dist[parent]+1;
          	parents[*it]=parent;
          	q.push(*it);
          }

  		}
  		q.pop();
  	}
  	cout<<"Distance of "<<src<<" from "<<des<<" is:"<<dist[des];
    int i=des;
  	while(i!=-1)
  	{
  		cout<<i<<"<--";
  		i=parents[i];
  	}
  }
  void dfshelper(int src,bool* visited)
  {
  	cout<<src<<" ";
  	visited[src]=true;
  	for(list<int>::iterator it=adjlist[src].begin();it!=adjlist[src].end();it++)
  	{
  		if(visited[*it]==false)
  			dfshelper(*it,visited);
  	}
  }
  void dfsprint(int src)
  {
    bool* visited=new bool[v];
    for(int i=0;i<v;i++)
    {
    	visited[i]=false;
    }
    dfshelper(src,visited);
  }
  bool isconnected(int src)
  {
  	bool *visited=new bool[v];
  	for(int i=0;i<v;i++)
  	{
  		visited[i]=false;
  	}
  	dfshelper(src,visited);
  	for(int i=0;i<v;i++)
  	{
  		if(visited[i]==false)
  		{	
  			cout<<"Not Connected";
  			return false;
  		}
  	}
  	cout<<"Connected";
  	return true;
  }
  void printcomponents()
  {
  	bool *visited=new bool[v];
  	for(int i=0;i<v;i++)
  		visited[i]=false;
  	int component=0;  //to count no. of components
  	for(int i=0;i<v;i++)
  	{
  		if(visited[i]==false)
  		{
  			component++;
  			cout<<"Currently Printing Component "<<component<<" : ";
  			dfshelper(i,visited);
  			cout<<"\n";
  		}
  	}
  }
  void topologicalSort()
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
      int task=q.front();//it into the queue else do nothing.
      cout<<task<<" ";
      q.pop();
      for(list<int>::iterator it=adjlist[task].begin();it!=adjlist[task].end();it++)
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
	// g.bfsprint();
	// int src,des;
	// cin>>src>>des;
	// g.shortestpath(src,des);
	// graph g(7);
	// g.addedge(1,2);
	// g.addedge(1,3);
	// g.addedge(0,4);
	// g.addedge(0,3);
	// g.addedge(2,5);
	// g.addedge(3,5);
	// g.addedge(4,5);
	// g.addedge(4,6);
	// g.addedge(1,2,false);
	// g.addedge(1,3,false);
	// g.addedge(0,4,false);
	// g.addedge(0,3,false);
	// g.addedge(2,5,false);
	// g.addedge(3,5,false);
	// g.addedge(4,5,false);
	// g.addedge(4,6,false);
	int v=3;
	graph g(v);
	g.addedge(0,1,false);
	g.addedge(1,2,false);
	g.topologicalSort();

}
 