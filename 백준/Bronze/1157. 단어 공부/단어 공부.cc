#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    vector<int> v(26,0);
    for (int i=0; i<str.length(); i++) {
        v[toupper(str[i]) - 'A']++;
    }

    int max_result = -1;
    for (int i=0; i<26; i++) max_result = max(max_result,v[i]);

    int cnt = 0;
    int index;
    for (int i=0; i<26; i++) {
        if (v[i] == max_result) cnt++, index = i;
    }

    if (cnt > 1) cout << "?";
    else {
        cout << char(index + 'A');
    }
}

