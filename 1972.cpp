#include <bits/stdc++.h>
using namespace std;

//===============typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef pair< int,pair<int,int>> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;
//=================
const  ll mod=1e9+7;


//=============define
#define inf 10000000
#define cln(a) memset(a,0,sizeof a);
#define clni(a) memset(a,inf,sizeof a);
#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define sp(c,x) ((c).find(x) != (c).end())  // for set,map
#define vp(c,x) (find(all(c),x) != (c).end())  // for vector
#define uu first
#define vv second
#define fr(i,a,b) for(int i=int(a);i<int(b);++i)
#define nfr(i,a,b) for(int i= int(a);i>=int(b);--i)
#define tc cin>>t ; while(t--)
#define pc()  cout<<"Case "<<cs++<<": "
#define mx (int)1e5+10
#define sc2(x,y) int x,y;scanf("%d %d",&x,&y)
#define sc3(x,y,z) int x,y,z;scanf("%d %d %d",&x,&y,&z)
#define sc(x) int x; scanf("%d",&x)
#define pfs(x) printf("%d ",x)
#define pf(x) printf("%d\n",x)
#define el puts("");
#define getcx() getchar()
#define Fi freopen("inp.txt","r",stdin)
#define rt return 0
#define dbg(x) cerr<<x<<endl
//============functions
ll bigmod(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
    if(b&1)
    ans=(ans*a)%mod;
    a=(a*a)%mod;
    b>>=1;
    }
    return ans;
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0}; 
//int vis[505][505];
//int vis[505]
//string s[505];
void dfs(int u,int v)
{

}
bool valid(int i,int y)
{
	return i>=0 && i<y;
}
int n,m;
char g[505][505];
int dis[505][505];
int Int(char c)
{
    return isdigit(c)?c-48:0;
}
void floyd()
{ 
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)

            if(g[i][k]+g[k][j]<g[i][j])
                g[i][j]=g[i][k]+g[k][j];
}
ii s,t;

int  C(char c)
{
	return isdigit(c)? c-48:0;
}
int dijk()
{
	for(int i=0;i<505;i++)
	{
		for(int j=0;j<505;j++)
			dis[i][j]=inf;
	}
	priority_queue< pair< int,pair<int,int>> > pq;
	pq.push({0,{s.uu,s.vv}});
	dis[s.uu][s.vv]=0;
	while(!pq.empty())
	{
		iii tm=pq.top();
		pq.pop();
		for(int i=0;i<4;i++)
		{
			int x=tm.vv.uu+dx[i];
			int y=tm.vv.vv+dy[i];
			if(valid(x,n) && valid(y,m) &&  g[x][y]!='#' && dis[x][y] >dis[tm.vv.uu][tm.vv.vv] + C(g[x][y]))
			{
				dis[x][y]=dis[tm.vv.uu][tm.vv.vv] + C(g[x][y]);
				pq.push({-dis[x][y],{x,y}});
			}
		}
	}
	return dis[t.uu][t.vv];
}
int main()
{
    cin>>n>>m;
    fr(i,0,n)
    {
        fr(j,0,m)
        {
            cin>>g[i][j];
            if(g[i][j]=='H')
                s={i,j};
            else if(g[i][j]=='E')
                t={i,j};
        }
    }
    int ans=dijk();
    if(ans==inf)
        puts("ARTSKJID");
    else cout<<ans<<endl;
}