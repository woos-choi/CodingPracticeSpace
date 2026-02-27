#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);

    int index;
    int result;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        if (v[i] == -1) index = i;
    }

    int min_left = v.front();
    int min_index_left = 0;
    int min_right =v.back();
    int min_index_right = v.size() - 1;
    for (int i=1; i<index; i++) {
        if (min_left > v[i]) {
            min_left = v[i];
            min_index_left = i;
        }

    }

    for (int i=index + 1; i<v.size() - 1; i++) {
        if (min_right > v[i]) {
            min_right = v[i];
            min_index_right = i;
        }
    }
    
    result = min_right + min_left;

    cout << result;
}

