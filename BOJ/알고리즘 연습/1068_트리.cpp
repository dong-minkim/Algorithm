#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> edge[51];


int delNode;

int DFS(int now) {
	
	int sub = 0;
	for (int i = 0; i < edge[now].size(); i++) {
		int next = edge[now][i];
		if (next == delNode) continue;
		sub += DFS(next); //���� ��尡 ���� �ִ� ���� ��� ������ ���Ѵ�.
	}

	if (sub!=0) { //sub��� ������ 0�̶�� ���� ����̱� ������ 1�� �����ش�.
		return sub;
	}
	else { //���ܳ�尡 �ƴ϶��
		return 1;
	}
}

int main()
{
	int N, rootNode;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			rootNode = i;
		}
		else edge[parent].push_back(i);
	}

	cin >> delNode;

	if (rootNode == delNode) cout << 0 << '\n';
	else cout << DFS(rootNode) << '\n';


	return 0;
}