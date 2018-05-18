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
#define mod 1000000007

 
 
//ALCATRAZIAN_CODE

 
//********whosoever_is_reading_this_go_fuck_urself*********

//since the intput is too large for a dp solution so matrix exponentiation which finds fibo in O(logn)

void multi(lli F[2][2], lli M[2][2])
{
	lli x = ((F[0][0])%mod *(M[0][0])%mod + (F[0][1])%mod*(M[1][0])%mod )%mod;
	lli y = ((F[0][0])%mod *(M[0][1])%mod + (F[0][1])%mod*(M[1][1])%mod )%mod;
	lli z = ((F[1][0])%mod *(M[0][0])%mod + (F[1][1])%mod*(M[1][0])%mod )%mod;
	lli w = ((F[1][0])%mod *(M[0][1])%mod + (F[1][1])%mod*(M[1][1])%mod )%mod;
 
	F[0][0] = (int)(x%mod);
	F[0][1] = (int)(y%mod);
	F[1][0] = (int)(z%mod);
	F[1][1] = (int)(w%mod);
}


void power(lli F[2][2], lli n)
{
	if(n == 0 || n == 1)
		return;
 
	lli M[2][2] = {{1,1}, {1,0}};
 
	power(F, n/2);
	multi(F, F);
 
	if( n%2 != 0)
		multi(F, M);
 
}


lli fib(lli n)
{
	lli F[2][2]  = {{1,1},{1,0}};
	if(n == 0)
		return 0;
	power(F, n-1);
 
	return F[0][0];
}
 

 

 

 void solvus()
{
	
	
	
tests{

lli n;
cin>>n;

cout<<fib(n+2)%mod<<endl;






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
 
 
