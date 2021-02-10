#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//��
bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int n;
	vector<string> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		//�ߺ��Ǵ� �ܾ �����ϰ� push�Ѵ�.
		//find�Լ��� �ش��ϴ� ���� ������ vector.end()��ȯ
		if (find(v.begin(), v.end(), s) == v.end()) {
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}