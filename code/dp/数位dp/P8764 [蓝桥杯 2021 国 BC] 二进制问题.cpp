/*
���仯���������λ dp ���⣬���Ƚ������Ͻ���в�λ���浽һ���������棬Ȼ��λ����
������Ҫ���ǵ������Լ��õ���ֵ�����Զ��� dfs �Ĳ������棬Ϊ�˱�֤���Ӷȣ�ʹ�� dp ������м��仯


*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[70],len = 0;//a ���飺��λ len��һ���м�λ 
int dp[70][70];//dp[i][j] : ��ǰ��� i λ��ǰ��һ������ j �� 1
int dfs(/*bool lead0 ���ⲻ�ÿ���ǰ���������*/ int pos, int cnt, int limit){//����Ҫ���ǵĶ������������������� 
	/*pos ��ǰ��ڼ�λ���Ӹ�λ����λ�
	  cnt ǰ���Ѿ����˼��� 1������ֻ�������˼���1����������ʱ��ô��� 
	  limitǰ���λ���Ƿ��Ƕ����Ͻ���ģ�����ǣ���һλ�϶��Ͳ�������� 
	*/
	if(!pos){//�Ѿ�������λ���������� 
//	cout << cnt << endl;
		return (cnt == k);
	}
	int &now = dp[pos][cnt];
	if(now != -1 && !limit){//���û�������ҵ�ǰλ�ñ��ѹ��� 
		return now;
	}
	int res = 0;
	int up = limit ? a[pos]:1;//��ǰ��ö�ٵ����Ͻ� 
	for(int i = 0; i <= up; i++){
		res += dfs(pos-1,cnt+i,limit && i == up); 
	}
	if(!limit){//��¼���仯 
		now = res;
	}
	return res; 
}
void solve(int n){
	while(n){//���в�λ����λ��������֪����ǰλ�������Ͻ磬����dfsʱ��һ������ 
		a[++len] = n &1;
		n >>= 1;
	}
	memset(dp,-1,sizeof dp);//һ��ϰ�߸���-1 
	 cout << dfs(len,0,1);
}
signed main(){
//	int n;
	cin >> n>>k;
	solve(n);	
	return 0;
}
