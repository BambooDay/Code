#include <bits/stdc++.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;
	
int main(){
	while(true){
		system("cls");
		cout << "\n\n					��ӭ���� 1A2B Game \n\n";
		cout << "��Ϸ����\n	ϵͳ���������һ�� N ���� M λ ÿһλ������ͬ ������ \n        (���ܻ����ǰ����)\n";
		cout << "	��������� M λ�����������²⣬ÿ��ϵͳ�᷵��һ������ \"xAyB\" ���ַ���\n";
		cout << "	��ʾ���� x ��������λ�������־���ȷ���� y ��������ȷ����λ�ò���ȷ\n        ����Ҫ��ϵͳ��������Ϣ���з������ղ³��������\n\n";
		cout << "    ������ 1 ����\n    û������ 0 ������������\n    ������� 1 �������˽���ȥ��������\n";
		int op;
		cin >> op;
		if(!op) return 0;
		system("cls"); 
		cout <<"\n��ѡ����Ϸ�Ѷȣ�\n    easy: N = 10 M = 2\n    medium: N = 10 M = 4 \n    hard: N = 16 M = 6 \n";
		string s;
		cin >> s;
		int cnt = 0;
		while(s != "easy" && s != "medium" && s !="hard" ){
			if(cnt == 1){
				cout << "���ǲ��ǰ� 1 ��������...\n\n";
			}
			if(cnt == 2){
				cout << "���ǲ��������Ͻ�����Ǹ�����...\n\n";
			}
			if(cnt == 3){
				cout << "�ش��֣����˻�û�����\n\n";
			}
			if(cnt == 4){
				cout << "��Ҫ�����Ǳ����˰�...\n\n";
			}
			if(cnt == 5){
				cout << "����һ��Ȱ����ȥ��������\n\n";
			}
			if(cnt == 6){
				cout << "��֪�������������޷�����Ѫ�쵰�׵ģ�����Ѫ�쵰�׵�����������\n\n";
			}
			if(cnt == 7){
				cout << "���������ľͺ�...\n\n";
			}
			cout << "������ \"easy\" \"medium\" \"hard\" ֮����ַ���:\n";
			cin >> s; 
			cnt++;
		}
		system("cls");	
		bool vis[20] = {0};
		
		if(s == "easy"){
			srand(time(0));
			int _1 = rand() % 10;
			srand(time(0));
			int _2 = rand() % 10;
			vis[_1] = 1;
			while(vis[_2]) _2 = rand() % 10;
			vis[_2] = 1;
			while(true){
				string ans;
				cout << "���������Ĵ𰸣�\n";
				cin >> ans;
				if(ans == "BambooDay"){
					ofstream flie("res.txt", ios_base::out);
					flie << _1 << " " << _2 << endl;
					flie.close();
				}
				if(ans.size() != 2){
					cout <<"������������\n\n���������룺\n";
					continue;
				}
				int ans1 = ans[0]-'0',ans2 = ans[1]-'0';
				if(ans1 == ans2){
					cout << "�������λ��ͬ��ʮ���ƶ�λ��(���Դ���ǰ����):\n\n";
					continue;
				}
				int x,y;
				x = 0,y = 0;
				if(vis[ans1]){
					if(ans1 == _1) x++;
					else y++;
				}
				if(vis[ans2]){
					if(ans2 == _2) x++;
					else y++;
				}
				if(x == 2){
					cout << "��Ӯ�ˣ�����\n�������棬����Ϊ����������\n\n";
					cout << "�� 1 ������Ϸ\n�� 0 ������Ϸ\n";
					cin>> op;
					system("cls");
					if(!op){
						cout << "\n\n\n         �ټ���ף��������죡\n";
						_sleep(3*1000);
						return 0;
					}
					break;
				}
				cout << x << "A" << y << "B" << endl;
			}
		} 
		if(s == "medium"){
			srand(time(0));
			int _1 = rand() % 10;
			srand(time(0));
			int _2 = rand() % 10;
			srand(time(0));
			int _3 = rand() % 10;
			srand(time(0));
			int _4 = rand() % 10;
			vis[_1] = 1;
			while(vis[_2]) _2 = rand() % 10;
			vis[_2] = 1;
			while(vis[_3]) _3 = rand() % 10;
			vis[_3] = 1;
			while(vis[_4]) _4 = rand() % 10;
			vis[_4] = 1;
			while(true){
				string ans;
				cout << "���������Ĵ𰸣�\n";
				cin >> ans;
				if(ans == "BambooDay"){
					ofstream flie("res.txt", ios_base::out);
					flie << _1 << " " << _2  << " " << _3 << " "  << _4 << endl;
					flie.close();
				}
				if(ans.size() != 4){
					cout <<"������������\n\n���������룺\n";
					continue;
				}
				int ans1 = ans[0]-'0',ans2 = ans[1]-'0',ans3 = ans[2] - '0',ans4 = ans[3] - '0';
				if( ans1 == ans2 || ans1 == ans3 || ans1 == ans4 || ans2 == ans3 || ans2 == ans4 || ans3 == ans4 ){
					cout << "�������λ��ͬ��ʮ������λ��(���Դ���ǰ����):\n\n";
					continue;
				}
				int x,y;
				x = 0,y = 0;
				if(vis[ans1]){
					if(ans1 == _1) x++;
					else y++;
				}
				if(vis[ans2]){
					if(ans2 == _2) x++;
					else y++;
				}
				if(vis[ans3]){
					if(ans3 == _3) x++;
					else y++;
				}
				if(vis[ans4]){
					if(ans4 == _4) x++;
					else y++;
				}
				if(x == 4){
					cout << "��Ӯ�ˣ�����\n��ӭ����X�m��������\n\n";
					cout << "�� 1 ������Ϸ\n�� 0 ������Ϸ\n";
					cin>> op;
					system("cls");
					if(!op){
						cout << "\n\n\n         �ټ���ף��������죡\n";
						_sleep(3*1000);
						return 0;
					}
					break;
				}
				cout << x << "A" << y << "B" << endl;
			}
		}
		if(s == "hard"){
			cout << "	��ӭ��ս����ѶȵĴ���\n\n";
			_sleep(1*1000);
			cout << "		��������ʱ����ǰ�� 0 ���磺1 ���� 01, 13 ���ɴ�� 13\n\n";
			cout << "		ף����Ϸ���\n\n";
			srand(time(0));
			int _1 = rand() % 16;
			srand(time(0));
			int _2 = rand() % 16;
			srand(time(0));
			int _3 = rand() % 16;
			srand(time(0));
			int _4 = rand() % 16;
			srand(time(0));
			int _5 = rand() % 16;
			srand(time(0));
			int _6 = rand() % 16;
			vis[_1] = 1;
			while(vis[_2]) _2 = rand() % 16;
			vis[_2] = 1;
			while(vis[_3]) _3 = rand() % 16;
			vis[_3] = 1;
			while(vis[_4]) _4 = rand() % 16;
			vis[_4] = 1;
			while(vis[_5]) _5 = rand() % 16;
			vis[_5] = 1;
			while(vis[_6]) _6 = rand() % 16;
			vis[_6] = 1;
			while(true){
				string ans;
				cout << "���������Ĵ𰸣�\n";
				cin >> ans;
				if(ans == "BambooDay"){
					ofstream flie("res.txt", ios_base::out);
					flie << _1 << " " << _2  << " " << _3 << " "  << _4 << " " << _5 << " " << _6 << endl;
					flie.close();
				}
				if(ans.size() != 12){
					cout <<"�������Ƿ�û�������\n\n���������룺\n";
					continue;
				}
				int ans1 = (ans[0]-'0')* 10 + ans[1] - '0';
				int ans2 = (ans[2]-'0')* 10 + ans[3] - '0';
				int ans3 = (ans[4]-'0')* 10 + ans[5] - '0';
				int ans4 = (ans[6]-'0')* 10 + ans[7] - '0';
				int ans5 = (ans[8]-'0')* 10 + ans[9] - '0';
				int ans6 = (ans[10]-'0')* 10 + ans[11] - '0';
				priority_queue<int> ss;
				ss.push(ans1);
				ss.push(ans2);
				ss.push(ans3);
				ss.push(ans4);
				ss.push(ans5);
				ss.push(ans6);
				if(ss.top() >= 16){
					cout <<"�������Ƿ�û�������\nÿһλ��ҪС�� 16 \n���������룺\n";
					continue;					
				}
				if(ss.size() != 6){
					cout << "�������λ��ͬ��ʮ��������λ��(���Դ���ǰ����):\n";
					cout << "�ǵ�����ռλ 0 \n\n"; 
					continue;
				}
				int x,y;
				x = 0,y = 0;
				if(vis[ans1]){
					if(ans1 == _1) x++;
					else y++;
				}
				if(vis[ans2]){
					if(ans2 == _2) x++;
					else y++;
				}
				if(vis[ans3]){
					if(ans3 == _3) x++;
					else y++;
				}
				if(vis[ans4]){
					if(ans4 == _4) x++;
					else y++;
				}
				if(vis[ans5]){
					if(ans5 == _5) x++;
					else y++;
				}
				if(vis[ans6]){
					if(ans6 == _6) x++;
					else y++;
				}
				if(x == 6){
					cout << "��Ӯ�ˣ�����\n��ӭ����X�m��������\n\n";
					cout << "�� 1 ������Ϸ\n�� 0 ������Ϸ\n";
					cin>> op;
					system("cls");
					if(!op){
						cout << "\n\n\n         �ټ���ף��������죡\n";
						_sleep(3*1000);
						return 0;
					}
					break;
				}
				cout << x << "A" << y << "B" << endl;
			}		
		}
	}
	return 0;
}
