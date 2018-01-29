#include<bits/stdc++.h>
using namespace std;

vector<int> g[1005];
int vis[1005];
int dis[1005];
int n,m,s,t,mid;
void bfs(int st,int en,int md)
{
	queue<int>q;
	memset(dis,0,sizeof dis);
	q.push(s);
	vis[s]=1;
	memset(vis,0,sizeof vis);
	while(!q.empty())
	{
		int tm=q.front();
		q.pop();

		for(int i=0;i<g[tm].size() && tm!=mid;i++)
		{
			int v=g[tm][i];
			if(!vis[v] && v!=md)
			{
			    vis[v]=1;
				dis[v]=1+dis[tm];
				q.push(v);
			}
		}
	}
}
int main()
{

	while(cin>>n>>m)
	{
		memset(g,0,sizeof g);

		while(m--)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);

		}
		cin>>s>>t>>mid;
		bfs(s,t,mid);

		cout<<dis[t];
		printf("\n");

	}
}
