#include <bits/stdc++.h>
using namespace std;
#define  endl '\n'
typedef long long ll;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pli> vpli;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define tests int t; cin>>t; while(t--)
#define loopeq(i,p,n) for(i=p;i<=n;i++)
#define loop(i,p,n) for(i=p;i<n;i++)
#define begen(a) a.begin(),a.end()
 
 
//ALCATRAZIAN_CODE

 
//********whosoever_is_reading_this_go_fuck_urself*********







//basic recursive fx for finding all different levels of arrays and returning the maximum one;
//lli ans(vector<lli> a,int n)
//{
//	if(n==1)
//	return a[0];
//	
//	vector<lli> yo(n-1);
//	
//	int i,j=0;
//	 for(i=0;i<n-1;i++)
//	 {
//	 	yo[j]=a[i]^a[i+1];
//	 	j++;
//	 }
//	 
//	 return ans(yo,n-1);
//	 
//	
//}

// it can be done similarly using dp where different levels of array are stored in dp and then we max out the ans.
int dp[5000][5000];
void solvus()
{
int n;
cin>>n;
vi a(n);

int i,j;


loop(i,0,n)
{
cin>>a[i];
dp[0][i]=a[i];
}

loop(i,1,n)
{
	loop(j,0,n-i)
	{
		dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
	}
}

loop(i,1,n)
{
	loop(j,0,n-i)
	{
		dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i-1][j+1]});
	}
}
int q;
cin>>q;

while(q--)
{
	
	int l,r;
	cin>>l>>r;
	l--;
	
	int len=r-l-1;
	
	cout<<dp[len][l]<<endl;
//	cout<<maxi<<endl;
	
	
}


    
}


 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   // solve();
  solvus();
   
   
    return 0;
}
 
 
