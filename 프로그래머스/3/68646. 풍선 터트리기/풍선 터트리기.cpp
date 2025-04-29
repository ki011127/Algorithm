#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    vector<int> right_min(n);
    int answer = 0;

    right_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_min[i] = min(a[i], right_min[i + 1]);
    }

    int left_min = a[0];
    answer = 1;

    for (int i = 1; i < n - 1; i++) {
        if (a[i] > left_min && a[i] > right_min[i + 1]) {
            continue; 
        }
        answer++;
        left_min = min(left_min, a[i]);
    }

    answer++;
    return answer;
}