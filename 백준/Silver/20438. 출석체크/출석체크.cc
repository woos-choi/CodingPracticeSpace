#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

/*
 * 20438. 출석 체크
 * 출석 코드 보내면 , 학생이 본인의 입장 번호의 배수인 학생들에게 출석 코드를 보낸다
 * 졸고 있는 애들은 안보낸다
 * 무작위로 보내고, 출석 x인 학생
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, q, m; cin >> n >> k >> q >> m;
    vector<int> v(n + 3, 0);

    for (int i=0; i<k; i++) {
        int data; cin >> data;
        v[data] = -1;
    }

    for (int i=0; i<q; i++) {
        int data; cin >> data;
        if (v[data] != -1) {
            for (int j=data; j<n+3; j+= data) {
                if (v[j] != -1) v[j] = 1;
            }
        }
    }

    vector<int> sum(n + 3, 0);
    for (int i=3; i<n+3;i++) {
        if (i == 3) {
            if (v[i] != 1) sum[i] += 1;
        }

        else {
            sum[i] += sum[i - 1];
            if (v[i] != 1) sum[i]++;
        }
    }

    for (int i=0; i<m; i++) {
        int s, e; cin >> s >> e;
        if (s != 3) cout << sum[e] - sum[s - 1] << '\n';
        else cout << sum[e] << '\n';
    }
}