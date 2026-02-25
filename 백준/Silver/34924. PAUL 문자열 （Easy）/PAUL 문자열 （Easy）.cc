#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    //1. PAUL을 담아두고 각각의 index를 찾아보자
    vector<int> v(4);
    int len = (int)s.length();
    for (int i=0;i<len; i++) {
        if (s[i] == 'P') v[0] = i;
        else if (s[i] == 'A') v[1] = i;
        else if (s[i] == 'U') v[2] = i;
        else if (s[i] == 'L') v[3] = i;
    }

    int flag = 0;
    if (v[0] % 2 == 0) {
        if ((v[1] - v[0]) % 2 == 1) {
            if ((v[2] - v[1]) %2 == 1) {
                if ((v[3] - v[2]) % 2 == 1) {
                    if ((len - v[3]) % 2 == 1 ) {
                        flag = 2;
                    }
                    else flag = 1;
                }

                else flag = 1;
            }

            else flag = 1;
        }

        else flag = 1;
    }

    else flag = 1;

    if (flag == 2) cout << "YES";
    else cout << "NO";

}