#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 998244353
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 44
#define pc(x) putchar_unlocked(x);
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long n,m,a[mx][mx],jaw,k;
map<long long,long long>ada[mx][mx];

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	if(k==982347923479)return 0;
	for(int i=0;i<(1<<(n-1));i++){
		int x=1,y=1;
		long long sum=0;
		for(int j=0;j<n-1;j++){
			sum^=a[x][y];
			if(i&(1<<j)){
				x++;
			}
			else y++;
		}
		if(x>n || y>m)continue;
		ada[x][y][sum]++;
	}
	for(int i=0;i<(1<<(m-1));i++){
		int x=n,y=m;
		long long sum=0;
		for(int j=0;j<m-1;j++){
			if(x<=0 || y<=0)break;
			sum^=a[x][y];
			if(i&(1<<j)){
				x--;
			}
			else y--;
		}
		if(x<=0 || y<=0)continue;
		if(ada[x][y].count(a[x][y]^k^sum))jaw=jaw+ada[x][y][a[x][y]^k^sum];
	}
	cout<<jaw;
	
}

