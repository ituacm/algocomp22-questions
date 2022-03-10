#include "bits/stdc++.h"
#define MAXN 1000009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;
 
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int n,p[MAXN],k[MAXN],ans;
ll t[MAXN];
void upd(int x,int v){
	for(;x;x-=(x&-x)) 
		t[x]+=v,k[x]++;
}
ll get(int x,int y){
	ll ans=0; 
	for(;x<=n;x+=(x&-x)) 
		ans+=t[x]-1ll*k[x]*y; 
	return ans;
}

int mod(ll y){
	return y%INF;
}
int main(){
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		ans=mod(ans+get(p[i],p[i]));
		upd(p[i],p[i]);
	}
	printf("%d\n",ans);
	return 0;
}
