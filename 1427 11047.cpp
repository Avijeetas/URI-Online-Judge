#include <bits/stdc++.h>
using namespace std;

//===============typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef map<string, int> msi;
//=================
const  ll mod=1e9+7;


//=============define
#define inf 1e9
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
#define tc sc(t) ; while(t--)
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

int g[105][105],pa[105][105];
void floyd(int n)
{ 
	fr(i,0,n)
	{
		fr(j,0,n)
			pa[i][j]=j;
	}
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
            if(g[i][k]+g[k][j]<g[i][j])
            {    g[i][j]=g[i][k]+g[k][j];
            	pa[i][j]=pa[i][k];
            }
}
vector<string>v;
msi mp;

void path(int x,int y)
{
 	do
 	{
 		cout<<v[x].c_str()<<" ";
 		x=pa[x][y];
 	}while(x!=y);
 	cout<<v[x].c_str()<<endl; 	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		v.clear();
		mp.clear();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			mp[s]=i;
			v.pb(s);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
				if(g[i][j]==-1) g[i][j]=inf;
			//	pa[i][j]=j;
			}
		}
		floyd(n);
		int q;
		cin>>q;
		cin.ignore();

		while(q--)
		{
			string a,b,s;
			cin>>s>>a>>b;
			int x=mp[a];
			int y=mp[b];
			if(g[x][y]==inf)
			cout<<"Sorry Mr "<<s<<" you can not go from "<<a<<" to "<<b<<endl;
			else{
				cout<<"Mr "<<s<<" to go from "<<a<<" to "<<b<<", you will receive "<<g[x][y]<<" euros"<<endl;
				cout<<"Path:";path(x,y);
			}
		}
	}
}
