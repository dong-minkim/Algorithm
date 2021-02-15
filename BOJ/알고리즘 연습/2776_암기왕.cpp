#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v;
	int T;
	cin >> T;
	for (int j = 0; j < T; j++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end()); // binary_search �� ����Ϸ��� ���ĵ� �־��Ѵ�.

		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			//�̺� Ž���Ͽ� num�� ������ 1��ȯ ������ 0 ��ȯ
			cout << binary_search(v.begin(), v.end(), num) << '\n';
		}
		v.clear();
	}

	return 0;
}