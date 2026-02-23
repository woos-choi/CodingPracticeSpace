#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;
// TIP 코드를 <b>Run</b>하려면 <shortcut actionId="Run"/>을(를) 누르거나 여백에서 <icon src="AllIcons.Actions.Execute"/> 아이콘을 클릭하세요.
int main() {

    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        if (n == 1) {
            cout << "Jolly" << '\n';
            continue;
        }

        set<int> s;
        for (int i=1; i<=n - 1; i++) s.insert(i);
        for (int i=0; i<n-1; i++) {
            s.erase(abs(v[i] - v[i + 1]));
        }

        if (s.empty() == true) cout << "Jolly" << '\n';
        else cout << "Not jolly" << '\n';
    }

    return 0;
    // TIP <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>에서 CLion 도움말을 참조하세요. 또한, 메인 메뉴의 '도움말 | IDE 기능 알아보기'를 선택하여 CLion에 관한 대화형 강의를 이용할 수도 있습니다.
}