/* 
Mohit Dhattarwal
*/
#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define gcd(a,b) __gcd(a,b)
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define filewr() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,ll> psl;
typedef pair<ll,string> pls;
 
template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}
 
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
const ld PI = 3.1415926535897932384626433832795;
 
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;

struct edge
{
	ll u, v, w;
};

edge a[500005];
vector<ll> dist(5005);
ll n, m, s;
void bellford()
{
	for(ll i =0; i<=n; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[s] = 0;
	bool flag = false;
	for(ll i =1; i<=n && !flag; i++)
	{
		flag = true;
		for(ll j=0; j<m; j++)
		{
			if(dist[a[j].u] + a[j].w < dist[a[j].v])
			{
				dist[a[j].v] = dist[a[j].u] + a[j].w;
				flag = false;
			}
		}
	}
	if(!flag)
	{
		cout<<"-1 \n";
	}
	else
	{
		for(ll i =0; i<n; i++)
		{
			cout<<i<<" "<<dist[i]<<'\n';
		}
	}
}

void solve()
{
	cin>>n>>m>>s;
	ll x,y,z;
	for(ll i =0; i<m; i++)
	{
		cin>>x>>y>>z;
		a[i].u = x;
		a[i].v = y;
		a[i].w = z;
	}
	//s = 1;
	bellford();
}

int main(){
	fastio();
	ll t;
	t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}