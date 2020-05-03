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



int main(){
	fastio();
	ll n;
	cin>>n;
	ll a[n+1];
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	if(n==1)
	{
		cout<<0<<endl;
		cout<<1<<endl;
		return 0;
	}

	if(n==2)
	{
		cout<<1<<endl;
		cout<<"1 2"<<endl;
		return 0;
	}

	if(n==3)
	{
		cout<<1<<endl;
		cout<<"1 3"<<endl;
		return 0;
	}
	
	for(ll i=4; i<=n; i++)
	{
		if(i%2==0 && i%3==0)
		{
			a[i] = 1+ min(a[i/2], min(a[i/3],a[i-1]));
		}
		else if(i%3==0)
		{
			a[i] = 1+min(a[i/3], a[i-1]);
		}
		else if(i%2==0)
		{
			a[i] = 1+min(a[i/2], a[i-1]);
		}
		else
		{
			a[i] = 1+a[i-1];
		}
	}
	ll num = a[n];
	vector<ll> v(num);
	//v.pb(1);
	//v.pb(n);
	ll count = 0;
	ll i = n;
	while(i>1)
	{
		//tr(i);
		v[count] = i;
		count++;
		if(i%2==0 && i%3==0)
		{
			ll y = a[i/2];
			ll z = a[i-1];
			ll x = a[i/3];

			if(y<min(x,z))
			{
				//v.pb(i/2);
				i/=2;
			}
			if(z<min(x,y))
			{
				//v.pb(i-1);
				i-=1;
			}
			else
			{
				//v.pb(i/3);
				i/=3;
			}
		}
		else if(i%3==0)
		{
			if(a[i/3]<=a[i-1])
			{
				//v.pb(i/3);
				i/=3;
			}
			else
			{
				//v.pb(i-1);
				i-=1;
			}
			
		}
		else if(i%2==0)
		{
			if(a[i/2]<=a[i-1])
			{
				//v.pb(i/2);
				i/=2;
			}
			else
			{
				//v.pb(i-1);
				i-=1;
			}
			
		}
		else
		{
			//v.pb(i-1);
			i-=1;
		}
	}
	cout<<a[n]<<endl;
	cout<<1<<" ";
	sort(v.begin(), v.end());
	for(ll i =0; i<a[n]; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}