#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n,k;
int ok[3000];
int dp[20][200][3000];
int cnt[3000];
vector<int> num;
signed main(){
	cin >> n >> k;
	for(int i = 0; i < (1<< n);i++){//����Ҫ��0��ʼ,��Ȼ���濼�ǵ�ʱ�򲻻����һ��һ�������ŵ�������ǽ�ȥ 
		cnt[i] = __builtin_popcount(i);
		if(!(i & (i << 1)) && !(i & (i >> 1))) num.push_back(i); 
	}
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int s1 : num){
			for(int s2 : num){
				if(!((s2 | ( s2 << 1) | (s2 >> 1)) & s1)){
					for(int j = 0; j <= k; j++){
						if(j - cnt[s1] >= 0){
							dp[i][j][s1] += dp[i-1][j-cnt[s1]][s2];
						}
					}
				}
			}
		}
	}
	int  ans = 0;
	for(int i : num) ans += dp[n][k][i];
	cout <<ans ;
	return 0;
}
