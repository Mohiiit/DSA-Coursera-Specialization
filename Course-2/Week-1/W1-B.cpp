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

vector<ll> a[100005];
ll ans = -1;

void dfs(ll u, ll depth, vector<bool>&visit)
{
	visit[u] = true;
	ans = max(ans,depth);
	for(auto i:a[u])
	{
		if(!visit[i])
		{
			dfs(i,1+depth,visit);
		}
	}
}

void solve()
{
	ll n,x;
	cin>>n;
	vector<ll> v;
	for(ll i =0; i<n; i++)
	{
		cin>>x;
		if(x==-1)
		{
			v.pb(i);
		}
		else
		{
			a[x].pb(i);
			a[i].pb(x);
		}
	}
	vector<bool>visit(100005,false);
	for(ll i =0; i<v.size(); i++)
	{
		if(!visit[v[i]])
		{
			dfs(v[i],1,visit);
		}
	}
	cout<<ans<<'\n';
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