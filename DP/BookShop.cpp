#include <bits/stdc++.h>
#include <climits>
typedef long long ll;
using namespace std;
/* Memoization
int f(int ind,int x,vector<int> &price,vector<int> &pages,int n,vector<vector<int>> &dp){
  if(ind==0){
    if(price[0]<=x)return pages[0];
    return INT_MIN;
  }
  if(dp[ind][x]!=-1)return dp[ind][x];
  int notTake=f(ind-1,x,price,pages,n,dp);
  int take=INT_MIN;
  if(price[ind]<=x){
    take=pages[ind]+f(ind-1,x-price[ind],price,pages,n,dp);
  }
  return dp[ind][x]=max(take,notTake);
}
*/


void solve()
{
  int n,x;
  cin>>n>>x;
  vector<int>price(n),pages(n);
  vector<int>prev(x+1,0),curr(x+1,0);
  for(int i = 0 ; i < n ; i++)cin>>price[i];
  for(int i = 0 ; i < n ; i++)cin>>pages[i];
  
  //Space Optimized 
  for(int sum = 0 ; sum <= x ; sum++){
    if(price[0]<=sum)prev[sum]=pages[0];
    else prev[sum]=0;
  }
  
  for(int ind = 1 ; ind < n ; ind++){
    for(int sum=0 ; sum <= x ; sum++){
      int notTake=prev[sum];
      int take=0;
      if(price[ind]<=sum){
       take=pages[ind]+prev[sum-price[ind]];
      }
      curr[sum]=max(take,notTake);
    }
    prev=curr;
  }
  cout<< prev[x] << endl;
  
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
