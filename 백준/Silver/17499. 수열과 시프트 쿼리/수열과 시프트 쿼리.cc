#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    int index = 0;

    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    for (int i=0; i<q; i++) {
        int type; cin >> type;

        if (type == 1) {
            int where, what;
            cin >> where >> what;
            where -= 1;

            v[(where + index) % n] += what;
        }

        else if (type == 3) {
            int what; cin >> what;
            index += what;
            index %= n;
        }

        else if (type == 2) {
            int what; cin >> what;
            index -= what;
            if (index < 0) index += n;
        }
    }

    for (int i=0; i<n; i++) cout << v[(index + i) % n] << " ";


}