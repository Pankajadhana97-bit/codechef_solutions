#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   int n; cin>>n;
   string s; cin>>s;
   int ans=0;
   for(int i=0;i<n;i++){
    for(int j=i+1;j <= min(9+i,n-1);j++){
      (abs(s[j]-s[i])== j-i ) ? ans+=1 : ans+=0 ;
    }
   } 
   cout<<ans<<"\n";
}
signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;cin>>T;
    while(T--) solve();
  cerr<<"[Time elapsed : "<<(double)clock()/CLOCKS_PER_SEC<<"]\n";
}