#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int i = n / 2;
    while (i--) {
        answer += "����";
    }
    if (n % 2 == 1) {
        answer += "��";
    }
    return answer;
}