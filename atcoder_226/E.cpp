#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef DEBUGGER
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define deb(...)
#endif

static const int mod = 998244353;
const int N = 2e5+10;
vector<int>g[N];
vector<bool>vis(N,false);
int nodes,edges;

void dfs(int node){
	nodes+=1;
	edges+=(g[node]).size();
	vis[node]=true;
	for(auto child : g[node]){
		if(vis[child]) continue;
		dfs(child);
	}
	return;
}

void solve(){
	int n,m;
	cin>>n>>m;

	while(m--){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 1;
     
    for(int i=1;i<=n;i++){
    	if(!vis[i]){
    		dfs(i);
    		if((2*nodes) == edges) ans = (2*ans)%mod;
    		else ans = 0;
    	}
    }
    cout<< ans <<"\n";
    return;
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef DEBUGGER
    freopen("error.txt", "w", stderr);
    #endif
    
    solve();
  cerr<<"[Time elapsed : "<<(double)clock()/CLOCKS_PER_SEC<<"]\n";
}