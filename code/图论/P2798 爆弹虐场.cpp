#include <bits/stdc++.h>
const int N = 10005;
const int M =  2e4+10;

using namespace std;
struct edge{
	int u, v,a,b;
	int val;
}e[M];
int n,k,m;
int fa[N];
bool cmp1(edge x, edge y){
	return x.a < y.a;
}
int cnt = 0;
int get1(int x){
	return fa[x] == x ? x : fa[x] = get1(fa[x]);
}
int f[N];
int get(int x){
	return f[x] == x ? x : f[x] = get(f[x]);
}
bool cmp2(edge x, edge y){
	return x.val < y.val;
}
bool check(int mid){
	int cnt1 = cnt;
	for(int i = 1;i <= n; i++) f[i] = fa[i];
	for(int i = 1; i <= m && e[i].val <= mid; i++){
		int fu = get(e[i].u),fv = get(e[i].v);
		if(fu != fv){
			f[fu] = fv;
			cnt1++;
		}
	}
	return cnt1 >= n-1;
}
int main(){
	cin >> n >> k >> m;
	for(int i = 1; i <= m; i++){
		cin>> e[i].u >> e[i].v >> e[i].a >> e[i].b; 
	}
	for(int i = 1;i <= n; i++) fa[i] = i;
	sort(e+1,e+m+1,cmp1);
	int ans = 0;
	for(int i = 1; i <= k; i++){
		int fu=get1(e[i].u) ,fv=get1(e[i].v);
		if(fu != fv){
			cnt++;
			fa[fu] = fv;
		}
		ans = max(ans,e[i].a);
		e[i].val = 1e9;
	}
	for(int i = k+1; i <= m; i++) e[i].val = min(e[i].a,e[i].b);
	sort(e+1,e+1+m,cmp2);
	int l = ans, r = 1e6+1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else l = mid+1;
	}
	cout << ans << endl;
	return 0;
}
