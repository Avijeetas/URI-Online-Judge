#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct mst
{
	ll u,v,w;	
};
bool cmp1(mst a,mst b)
{
	return a.w<b.w;
}
bool cmp2(mst a,mst b)
{
	return a.w>b.w;
}
const ll N=1000006;
ll pr[N];
void init()
{
	for(ll i=0;i<N;i++)
		pr[i]=i;
}
vector<mst> p;

ll Find(ll r)
{
	if(pr[r]!=r)
		return pr[r]=Find(pr[r]);
	return r;
}
	ll n;
ll kru()
{
	ll cst=0;
	for(ll i=0;i<n;i++)
	{
		ll x=p[i].u;
		ll y=p[i].v;
		x=Find(x);
		y=Find(y);
		if(x!=y)
		{
			pr[y]=x;
			cst+=p[i].w;
		}
	}
	return cst;
}
int main()
{
	init();

	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		mst vt;
		vt.u=x;
		vt.v=y;
		vt.w=w;
		p.push_back(vt);
	}
	sort(p.begin(),p.end(),cmp2);
	ll mx=kru();
	init();
	sort(p.begin(),p.end(),cmp1);
	ll mn=kru();
	cout<<mx<<endl<<mn<<endl;
}