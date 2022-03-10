#include "bits/stdc++.h"
#define MAXN 100009
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
int INF,t;
int mul(int a,int b) {
    return (1LL*a*b)%INF;
}
int add(int a,int b) {
	a+=b;
	if(a>=INF)a-=INF;
	return a;
}
int sub(int a,int b){
	a+=INF-b;
	if(a>=INF)a-=INF;
	return a;
}
int Fe(int x,ll y){
	if(!y)return 1;
	int h=Fe(x,y/2);
	h=mul(h,h);
	if(y&1)h=mul(h,x);
	return h;
}
bool check(int L,int R,int span,int goal){
    if(span>=INF)return true;
    if(R<L)R+=INF;
    return ((L<=goal and goal<=R) or (L<=goal+INF and goal+INF<=R));
}
int main(){
	scanf("%d%d",&INF,&t);
    while (t--){		
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int S=add(a,b),T=add(c,d);
		if(S!=T){
			puts("-1");
			continue;
		}
		S=Fe(S,INF-2);
		a=mul(a,S);
		b=mul(b,S);
		c=mul(c,S);
		d=mul(d,S);
		int L=a,R=a,ans=0;
		while(!check(L,R,(1<<ans),c))
			R=add(R,R),L=sub(add(L,L),1),ans++;
		printf("%d\n",ans);
	}
	return 0;
}
