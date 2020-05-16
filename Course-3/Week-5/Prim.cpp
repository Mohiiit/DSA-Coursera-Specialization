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
typedef pair<ll,ld> pld;
 
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

struct node {
  int parent;
  int rank;
  int x;
  int y;
	
  node(int a, int b, int c = -1, int d = 0) {
    x = a;
    y = b;
    parent = c;
    rank = d;
  }
};

struct edge {
  int u;
  int v;
  double weight;
  
  edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};

bool cmp(edge a, edge b) {
  return a.weight < b.weight;
}

void make_set(int i, vector<node> &nodes, vector<int> &x, vector<int> &y) {
  nodes.push_back(node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Find(int i, vector<node> &nodes) {
  if (i != nodes[i].parent) {
    nodes[i].parent = Find(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}

void Union(int u, int v, vector<node> &nodes) {
  int r1 = Find(u, nodes);
  int r2 = Find(v, nodes);
  if (r1 != r2) {
    if (nodes[r1].rank > nodes[r2].rank) {
      nodes[r2].parent = r1;
    } else {
      nodes[r1].parent = r2;
      if (nodes[r1].rank == nodes[r2].rank) {
        nodes[r2].rank++;
      }
    }
  }
}

void mindis(vector<int> x, vector<int> y) {
  double result = 0.;
  //write y code here
  int n = x.size();
  vector<node> nodes;
  for (int i = 0; i < n; i++) {
	make_set(i, nodes, x, y);
  }
  vector<edge> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges.push_back(edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 0; i < edges.size(); i++) {
    edge current_edge = edges[i];
    int u = current_edge.u;
    int v = current_edge.v;
    if (Find(u, nodes) != Find(v, nodes)) {
      result += current_edge.weight;
      Union(u, v, nodes);
    }
  }
  cout<<fixed<<setprecision(10)<<result<<'\n';
}

void solve()
{
	int n;
	cin>>n;
	vector<int> t(n);
	vector<int> b(n);

	for(int i =0; i<n; i++)
	{
		cin>>t[i]>>b[i];
	}
	mindis(t,b);
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