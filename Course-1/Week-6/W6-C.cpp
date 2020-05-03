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

ll cal(ll a, ll b, char op)
{
	if(op=='*')
	{
		return a*b;
	}
	else if(op=='+')
	{
		return a+b;
	}
	else
	{
		return a-b;
	}
}

ll maxi(const string &exp)
{
	ll len = exp.size();
	ll num = (len+1)/2;
	ll minArr[num][num];
	ll maxArr[num][num];
	memset(minArr,0,sizeof(minArr));
	memset(maxArr,0,sizeof(maxArr));

	for(ll i =0; i<num; i++)
	{
		minArr[i][i] = stoll(exp.substr(2*i,1));
		maxArr[i][i] = stoll(exp.substr(2*i,1));
	}

	for(ll i =0; i<num-1; i++)
	{
		for(ll j =0; j<num-i-1; j++)
		{
			ll k = i+j+1;
			ll minval = LLONG_MAX;
			ll maxval = LLONG_MIN;

			for(ll l = j; l<k; l++)
			{

				ll a = cal(minArr[j][l],minArr[l + 1][k],exp[2 * l + 1]);
				ll b = cal(minArr[j][l],maxArr[l + 1][k],exp[2 * l + 1]);
				ll c = cal(maxArr[j][l],minArr[l + 1][k],exp[2 * l + 1]);
				ll d = cal(maxArr[j][l],maxArr[l + 1][k],exp[2 * l + 1]);
				minval = min(minval,min(a,min(b,min(c,d))));
				maxval = max(maxval,max(a,max(b,max(c,d))));
			}

			minArr[j][k] = minval;
			maxArr[j][k] = maxval;
		}
	}

	return maxArr[0][num-1];
}

int main(){
	fastio();
	string s;
	cin>>s;
	cout<<maxi(s)<<endl;
	return 0;
}