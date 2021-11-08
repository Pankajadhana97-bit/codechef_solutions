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

void solve(){
  int n;
  cin>>n;
  vector<int>x(n),y(n);

  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  set<pair<int,int>>st;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      int gcd = __gcd(abs(x[i]-x[j]),abs(y[i]-y[j]));
      st.insert({(x[j]-x[i])/gcd,(y[j]-y[i])/gcd});
    }
  }
  cout<< st.size() <<"\n";
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