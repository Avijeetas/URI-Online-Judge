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
#define inf 10000000
#define cln(a) memset(a,0,sizeof a);
#define clni(a) memset(a,inf,sizeof a);
#define all(x) x.begin(), x.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define sp(c,x) ((c).find(x) != (c).end())  // for set,map
#define vp(c,x) (find(all(c),x) != (c).end())  // for vector
#define uu first
#define vv second
#define fr(i,a,b) for(int i=int(a);i<int(b);++i)
#define nfr(i,a,b) for(int i= int(a);i>=int(b);--i)
#define tc cin>>t ; while(t--)
#define pc()  cout<<"Case "<<cs++<<": "
#define mx (int)1e5+10
#define sc2(x,y) scanf("%d %d",&x,&y)
#define sc3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sc(x) scanf("%d",&x)
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

vector<pair<ll,pair<ll,ll> > > p;
ll pr[10006];
ll Find(ll r)
{
	if(pr[r]!=r)
		return pr[r]=Find(pr[r]);
	return r;

}


int main()
{
	ll n;
	cin>>n;
	for(int i=0;i<=n;i++)
		pr[i]=i;
	for(ll i=0;i<n-1;i++)
	{	ll m;
		cin>>m;
		for(ll j=0;j<m;j++)
		{
			ll y,w;
			cin>>y>>w;
			--y;	
			p.push_back(mp(w,mp(i,y)));
		}
	}
	ll res=0,m=n-1;;
	sort(p.begin(),p.end());
	for(auto it : p)
	{	
		ll x=it.vv.uu;
		ll y=it.vv.vv;
		x=Find(x);
		y=Find(y);
		if(x!=y)
		{
			pr[x]=y;

			res+=it.uu;
		}
	}

	set<ll> evl;
	for(ll i=0;i<n;i++)
		evl.insert(Find(pr[i]));
	ll fml=evl.size();
	cout<<fml<<" "<<res<<endl;
}           