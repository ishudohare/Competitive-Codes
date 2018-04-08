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
typedef vector<pli> vpli;o
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define tests int t; cin>>t; while(t--)
#define loopeq(i,p,n) for(i=p;i<=n;i++)
#define loop(i,p,n) for(i=p;i<n;i++)
#define begen(a) a.begin(),a.end()
 
 
//ALCATRAZIAN_CODE

 
//********whosoever_is_reading_this_go_fuck_urself*********

//segment tree problem....HELP MoNA of hackerearth practice!!
ll A[2000005], tree[4000015], ind[4000015];

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
        ind[node]=start;
    }
    else
    {
        ll mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // llernal node will have the sum of both of its children
        //tree[node] = min(tree[2*node],tree[2*node+1]);
        
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update(ll node, ll start, ll end,ll idx)
{
    if(start == end)
    {
        // Leaf node
        A[idx] = 1-A[idx];
        tree[node] = 1-tree[node];
    }
    else
    {
        ll mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx);
        }
        // llernal node will have the sum of both of its children
        tree[node] = tree[2*node]+tree[2*node+1];
		// the sum results in the number of the odd numbers as 1 denotes a odd numbr ...so if a parent node is 
		//3 , then it has 3 odd numbers in it..therefore we substract k by tree[2*node] to check for the left od ones
    }
}

ll query(ll node, ll start, ll end, ll k)
{
    if(tree[node]<k)
    { // total odd nos. are less than k
        // range represented by a node is completely outside the given range
        return -1;
    }
    if(start==end)
    {
        // range represented by a node is completely inside the given range
        return ind[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    ll mid = (start + end) / 2;
    
    if(tree[2*node]>=k)
    query(2*node,start,mid,k);
    else
    query(2*node+1,mid+1,end,k-tree[2*node]);//  the
   
   
}

 void solvus()
{

ll n,q;
cin>>n>>q;
ll i;
loop(i,0,2000005)
A[i]=0,tree[i]=0;

ll elem;
loop(i,1,n+1)
{
	cin>>elem;
	A[i]=elem%2;;
}

build(1,1,n);

while(q--)
{
	int qu;
	cin>>qu;
	if(qu==2)
	{
		ll k;
		cin>>k;
		cout<<query(1,1,n,k)<<endl;
	}
	else 
	{ ll index;
	cin>>index;
	update(1,1,n,index);
		
	}
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
 
 

