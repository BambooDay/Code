#include <bits/stdc++.h>
const int N=400005;

using namespace std;

struct node {
	int x,y,nxt;
};
node e[N],way[N<<1];
int st[N],sta[1000010],tt=0,tot=0;
int p[N<<1],num=0;
int ans[N],mxlen,mx,n,lnk[N<<1];

void Add(int u,int w,int z) {
	tt++;
	e[tt].x = u;
	e[tt].y = w;
	e[tt].nxt = sta[z];
	sta[z] = tt;
}

void add(int u,int w) {
	tot++;
	way[tot].x = u;
	way[tot].y = w;
	way[tot].nxt = st[u];
	st[u] = tot;
	lnk[tot] = u;
	tot++;
	way[tot].x = w;
	way[tot].y = u;
	way[tot].nxt = st[w];
	st[w] = tot;
	lnk[tot] = w;
}

int dfs(int now) {
	p[now] = num;
	int mxson = 0;
	for (int i = st[now]; i; i = way[i].nxt)
		if (p[way[i].y] != num) {
			int r = dfs(way[i].y);
			mxlen = max(mxlen,r+mxson+1);
			mxson = max(mxson,r+1);
		}
	return mxson;
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u,w,z;
		cin >> u >> w >> z;
		mx = max(mx,z);
		Add(u,w,z);
	}
	for (int i = 1; i <= mx; i++) {
		for (int j = i; j <= mx; j += i){
			for (int k = sta[j]; k; k = e[k].nxt){
				add(e[k].x,e[k].y);
			}
		}
		mxlen = 0;
		num++;
		for (int k = 1; k <= tot; k++){
			if (p[lnk[k]] != num) dfs(lnk[k]);
		}
		for (int k = 1; k <= tot; k++) st[lnk[k]]=0;
		tot = 0;
		ans[mxlen] = i; 
	}
	for (int i = n-1; i > 0; i--) ans[i] = max(ans[i],ans[i+1]); 
	for (int i = 1; i <= n; i++) printf("%d\n",ans[i]);
	return 0;
}
/*
���һ���˽��Բ������ɣ���������ȴΪ֮�������������������

��������˵������������ʡ�죬������֪�����Σ��������尲�ݹ��Ұ��� 

1.���������Ͽɱ��˵Ĳ��� 
2.�ʾ�����
3.�и������ڣ�������

1.���á����O�ޡ���ʣ��������˵�˼��֮�� 
2.����Ī̾�׷����������˵�Ȱο�͹��� 
*/ 


