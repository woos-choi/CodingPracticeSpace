#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n + 1);

    for (int i=1; i<=n; i++) cin >> v[i];
    int m; cin >> m;

    for (int i=0; i<m; i++) {
        int gender, index;
        cin >> gender >> index;

        if (gender == 1) {
            for (int j=1; j<=n; j++) {
                if (j % index == 0) {
                    if (v[j] == 1) v[j] = 0;
                    else v[j] = 1;
                }
            }
        }

        else if (gender == 2) {
            int cnt = 0;
            while (true) {
                if (index - cnt < 1 || index + cnt > n) break;
                if (cnt != 0 && v[index + cnt] != v[index - cnt]) break;

                if (cnt == 0) {
                    if (v[index] == 1) v[index] = 0;
                    else v[index] = 1;
                }

                else {
                    if (v[index + cnt] == v[index - cnt]) {
                        if (v[index + cnt] == 1) {
                            v[index + cnt] = 0;
                            v[index-cnt] = 0;
                        }

                        else {
                            v[index + cnt] = 1;
                            v[index - cnt] = 1;
                        }
                    }
                }

                cnt++;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << v[i] << " ";
        if (i % 20 == 0) cout << '\n';
    }

}