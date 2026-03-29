#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * 2467. 용액
 * 특성값이 0에 가까운 용액을 만들고 싶음
 * 특성값은 혼합에 사용된 용액의 특성값의 합으로 정의
 * 투포인터가 정확히 무슨 알고리즘인지는 잘 모르곘는데 투 포인터의 냄새가 남
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<long long> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    int left = 0, right = n - 1;
    int left_result = 0, right_result = n - 1;
    //cout << v[left_result] << " " << v[right_result] << '\n';
    long long min = LLONG_MAX;
    while (left < right) {
        if (min >= llabs((v[left] + v[right]))) {
            min = llabs(v[left] + v[right]);
            left_result = left;
            right_result = right;
        }

        if (v[left] + v[right] > 0) right--;
        else left++;


    }
    cout << v[left_result] << " " << v[right_result];
}