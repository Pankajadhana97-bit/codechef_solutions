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
#define int long long

//atcoder beginner contest 266 question - 3 ( Martial Artist )
const int N = 2e5+10;
vector<int>g[N];
vector<int>timer(N);
vector<bool>vis(N);
int ans;

void dfs(int node){
  ans+=timer[node];
  vis[node]=true;
  for(auto child:g[node]){
    if(vis[child])continue;
    dfs(child);
  }
}

void solve(){
  int n,x;
  cin>>n;
 for(int i=1;i<=n;i++){
      cin>>timer[i];
      cin>>x;
      while(x--){
        int num; cin>>num;
        g[i].push_back(num);
      }
 }
 dfs(n);
 cout<<ans<<"\n";
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
  cerr<<"[timer elapsed : "<<(double)clock()/CLOCKS_PER_SEC<<"]\n";
}