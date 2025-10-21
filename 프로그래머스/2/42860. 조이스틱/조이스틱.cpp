#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();

    // 알파벳 변경 비용 계산
    for (char c : name)
        answer += min(c - 'A', 'Z' - c + 1);

    // 커서 이동 최소 계산
    int move = len - 1; // 일단 한쪽 끝까지 가는 경우
    for (int i = 0; i < len; i++) {
        int next = i + 1;
        while (next < len && name[next] == 'A')
            next++;
        // i까지 갔다가 뒤로 돌아가는 경우와 비교
        move = min(move, i + len - next + min(i, len - next));
    }

    answer += move;
    return answer;
}