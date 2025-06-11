#include <bits/stdc++.h>
typedef long long ll;
ll INF=1e18;
using namespace std;

class Solution{
  
public:
  
  ll minimizingCoins(ll n,ll x,vector<ll> &a){
    vector<ll> next(x+1,0),curr(x+1,0);
    next[0]=0;
    for(ll sum=1 ; sum <= x ; sum++)next[sum]=INF;
    for(ll ind = n-1 ; ind >= 0 ; ind--){
      for(ll sum= 0 ; sum <= x ; sum++){
         ll notTake=next[sum];
         ll take=INF;
         if(a[ind]<=sum){
          take=1+curr[sum-a[ind]];
         }
         curr[sum]=min(take,notTake);
      }
      next=curr;
    }

    if(next[x]>=INF)return -1;
    return next[x];
  }
};

void solve()
{
  ll n,x;
  cin >> n >> x;
  vector<ll> c(n);
  for(ll i = 0 ; i < n ; i++)cin>>c[i];
  Solution obj;
  cout<<obj.minimizingCoins(n,x,c)<<endl;
  
}




signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
  
    while(t--)
    {
        solve();
    }
	return 0;
}
