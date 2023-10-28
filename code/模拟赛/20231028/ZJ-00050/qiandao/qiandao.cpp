#include <bits/stdc++.h>
const int N = 2e6+10;

using namespace std;
int n;
int a[N];
int ans = 0;
namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

int main(){
	freopen("qiandao.in","r",stdin);
	freopen("qiandao.out","w",stdout);
	//cin >> n;
	scan(n);
	for(int i = 1; i <= n; i++) scan(a[i]);
	for(int l = 1; l <= n; l++){
		int mi = 1e9;
		deque<int> q;
		#define mid (((l+r)>>1)+1)
		for(int r = l; r <= n; r++){
			mi = min(mi,a[r]);
			while(!q.empty() && q.front() < mid) q.pop_front();
			while(!q.empty() && a[q.back()] >= a[r]) q.pop_back();
			q.push_back(r);
			if(a[q.front()] <= mi) ans++;
		}
	}
	putint(ans - n,'\n'); 
	flush();
	return 0;
}

