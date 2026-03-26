#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 1059. 좋은 구간
 * left, right
 * 1 7 10 14 / 2를 포함해라
 * left = 2, n = 2, right = 6
 * (2 - 2 + 1) * (4 + 1) - 1 = 4
 *
 * 4 8 13 24 30 / 10를 포함해라
 * left = 9, right = 12 n = 10
 * (10 - 9 + 1) * (12 - 10  + 1)  - 1 = 2 * 3 - 1 = 5
 *
 * 만약 1 10 / 2
 * left = 2, n = 2, right = 9
 * 1 * 8 - 1 = 7
 *
 * (n - left + 1) * (right - n + 1) - 1
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    int flag = 0;

    int l; cin >> l;
    vector<int> v(l);

    for (int i=0; i<l; i++) cin >> v[i];
    sort(v.begin(),v.end());

    int n; cin >> n;
    int left = 1, right = v.back();

    //vector가 1개만 나온 경우
    if (l == 1) {
        if (v.front() > n) {
            left = 1;
            right = v.front() - 1;
        }

        else {
            flag = 1;
            cnt = 0;
        }
    }

    else {
        if (v.front() > n) {
            left = 1;
            right = v.front() - 1;
        }

        else {
            for (int i=1; i<l; i++) {
                if (v[i-1] < n && n < v[i]) {
                    left = v[i - 1] + 1;
                    right = v[i] - 1;
                    break;
                }

                if (v[i-1] == n) {
                    flag = 1;
                    break;
                }
            }
        }
    }

    //cout << left << " " << right << '\n';
    if (flag == 0) cnt  = (n - left + 1) * (right - n + 1) - 1;

    cout << cnt;
}