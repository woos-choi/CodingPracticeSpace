#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

/*
 * 20922. 겹치는 건 싫어
 */

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    int start = 0, end = 0;
    int max_result = -1;

    map<int,int> m;
    while (end < n) {
        if (start == end) {
            max_result = max(max_result,end - start + 1);
            m.insert({v[start],1});
            end++;
        }

        else {
            if (m.find(v[end]) == m.end()) {
                max_result = max(max_result,end - start + 1);
                m.insert({v[end],1});
                end++;
            }

            else {
                if (m.find(v[end])->second + 1 <= k) {
                    max_result = max(max_result,end - start + 1);
                    m.find(v[end])->second++;
                    end++;
                }

                else {
                    m.find(v[start])->second--;
                    start++;
                }
            }
        }
    }

    cout << max_result;

}