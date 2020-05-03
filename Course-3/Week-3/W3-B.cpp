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

bool bfs(vector<ll> a[], ll n)
{
	vector<ll> dist(n+1, -1);
	queue<ll>q;
	q.push(1);
	dist[1] = 0;
	while(!q.empty())
	{
		ll t = q.front();
		for(ll i=0; i<a[t].size(); i++)
		{
			if(dist[a[t][i]]==-1)
			{
				q.push(a[t][i]);
				dist[a[t][i]] = dist[t]+1;
			}
		}
		q.pop();
	}
	for(ll i =1; i<=n; i++)
	{
		if(dist[i]!=-1)
		{
			for(ll j=0; j<a[i].size(); j++)
			{
				//tr(dist[i], dist[a[i][j]]);
				if(dist[i]%2 == dist[a[i][j]]%2)
				{
					return false;
				}
			}
		}
	}
	return true;

}

void solve()
{
	ll n,m,u,v;
	cin>>n>>m;
	vector<ll> a[n+1];
	for(ll i =0; i<m; i++)
	{
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	
	cout<<bfs(a,n)<<'\n';
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