#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * 17128. 소가 정보섬에 올라온 이유
 * 시간초과? -> dp로 풀어볼까?
 */
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    vector<int> dp(n,0);
    int sum = 0;

    for (int i=0; i<n; i++) {
        int temp = 1;
        for (int j=0; j<4; j++) {
            temp *= v[(i + j) % n];
        }
        dp[i] = temp;
        sum += dp[i];
    }

    //for (int i=0; i<n; i++) cout << dp[i] << ' ';
    //cout << '\n';

    while (q--) {
        int data; cin >> data;
        for (int i=0; i<4; i++) sum -= dp[( n + data - 1 - i) %n];
        for (int i=0; i<4; i++) {
            dp[(n + data -1 - i) % n] *= -1;
            sum += dp[(n + data - 1 - i) % n];
        }

        //for (int i=0; i<n; i++) cout << dp[i] << ' ';
        //cout << '\n';

        cout << sum << '\n';
    }
}



