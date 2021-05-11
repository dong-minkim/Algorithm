#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[32001];
queue<int> q;
int len[32001] = { 0, };

int main()
{
	int N, M; int A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		len[B]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (len[i] == 0) q.push(i);
	}
	
	//�������� point
	//�� ���� ����� len����(���� ����)�� 0�̾�� �ٸ� ����� �켱����
	//�񱳿��� ����Ƿ� len==0�϶� q�� push�� �Ѵ�.
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';

		for (int i = 0; i < v[now].size(); i++) { //��� now�� ����Ǿ��ִ� ����
			int next = v[now][i];   //now��忡 ����� ���� ���
			len[next]--;            //now���� next ��� ����� ������ ����
			if (len[next] == 0) q.push(next); //����� ������ ������ q�� push
		}
	}



}