#include<iostream>
#include<cmath>
using namespace std;

int primeNumber(int num);
int main()
{
    int cnt = 0;
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int x;
        cin >> x;
        if (primeNumber(x)) cnt++;
    }

    cout << cnt;
    return 0;
}
int primeNumber(int num)
{
    if (num == 1) return false;
    if (num == 2) return true;     //num�� 2�� ��� �Ҽ��̹Ƿ� true
    else if (num % 2 == 0) return false; //num�� ¦���� ��� �Ҽ��� �ƴϹǷ� �Ҽ��� �ƴϹǷ� false
    int i = 3;
    while (i <= sqrt(num)) {
        if (num % i == 0) {
            return false;
        }
        else i += 2;
    }
    return true;
}