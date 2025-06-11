#include <bits/stdc++.h>
typedef long long ll;
int m=1e9+7;
using namespace std;

class Solution{
  
public:
  
  
  int ways(int n){
     vector<ll> dp(n+1,0);
     dp[0]=1;
  
     for(int i = 1 ; i <= n ; i++){
       for(int dice=1 ; dice<=6 ; dice++){
          if(i-dice>=0)dp[i]+=dp[i-dice]%m;
       }
      }
      return dp[n]%m;
  }
  
};

void solve()
{
  int n;
  cin >> n;
  Solution obj;
  cout<<obj.ways(n)<<endl;
  
}




int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
  
    while(t--)
    {
        solve();
    }
	return 0;
}
