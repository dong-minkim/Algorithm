using namespace std;

//������ ������ ���ϴ� ����.
long long solution(int w, int h) {
    long long answer;
    answer = ((long long)w * (long long)h) - (long long)w - (long long)h;
    while (h != 0) {
        int tmp = w % h;
        w = h;
        h = tmp;
    }
    answer += w;

    return answer;

}