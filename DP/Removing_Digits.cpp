#include <bits/stdc++.h>
typedef long long ll;
int M=1e9+7;
using namespace std;



  int maxDigit(int n) {
    int mx = 0;
    while (n > 0) {
        mx = max(mx, n % 10);
        n /= 10;
    }
    return mx;
   }
    
  

void solve()
{
  int n;
  cin>>n;
  vector<int> dp(n+1,0);
  dp[0]=0;
  for(int i = 1 ; i <= n ; i++){
     dp[i] = 1+dp[i-maxDigit(i)];
  }
  cout<< dp[n] <<endl;
  
  
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
