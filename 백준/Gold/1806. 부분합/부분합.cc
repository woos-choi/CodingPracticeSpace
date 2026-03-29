#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 * 1806. 부분합
 * 투포인터 전략을 사용하면 좋을것 같다
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s; cin >> n >> s;

    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    int start = 0, end = 0;
    int min_result = 100001;
    long long temp = v[start];

    //1. 부분합이 s를 넘는지 체크할 떄 다 순회하면 안될것 같음 ( 시간 초과 가능성 )
    //2.
    while (end < n) {
        if (start == end) {
            if (temp >= s) {
                min_result = min(min_result,end - start + 1);
                start++, end++;
                temp = v[start];

            }
            else {
                end++;
                temp += v[end];
            }
        }

        else {
            if (temp >= s) {
                min_result = min(min_result,end-start + 1);
                temp -= v[start];
                start++;
            }

            else {
                end++;
                temp += v[end];
            }
        }

        //cout << "start :" << start << " end : " << end << " min_result :  " << min_result << '\n';
    }

    if (min_result == 100001) min_result = 0;
    cout << min_result;
}