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

void explore(ll u, vector<ll> v[], vector<bool> &visited)
{
	visited[u] = true;
	for(ll i =0; i<v[u].size(); i++)
	{
		if(visited[v[u][i]]==false)
		{
			explore(v[u][i],v,visited);
		}
	}
}

void dfs(vector<ll> v[], ll n, ll u, ll x)
{
	vector<bool> visited(n+1,false);
	explore(u,v,visited);
	if(visited[x])
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}

void solve()
{
	ll n, m, u, x;
	cin>>n>>m;
	vector<ll> v[n+1];
	for(ll i =0; i<m; i++)
	{
		cin>>u>>x;
		v[u].pb(x);
		v[x].pb(u);
	}
	//bool a[n] = {false};
	cin>>u>>x;
	dfs(v,n,u,x);
}

int main(){
	fastio();
	ll t;
	t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}