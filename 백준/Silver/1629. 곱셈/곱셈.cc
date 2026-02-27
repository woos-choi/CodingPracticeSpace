#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 1629. 곱셈
 * 분할정복을 쓰는 알고리즘
 * a의 b승의 c로 나눈 나머지를 구해야하는 문제 -> a의 b승의 값이 너무 커져 중간중간 나머지를 구해줘야함
 * 하지만, 이걸 b번 반복하는 건 시간 제한을 넘어버림
 * 그래서 분할정복을 쓴다는데..
 *
 */

long long func(long long a, long long b, long long c) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    long long half = func(a, b/2, c);

    long long result = (half * half) % c;

    if (b % 2 == 1) {
        result = (result * (a % c)) % c;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << func(a,b,c);

}

