#include <string>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

/*
현우는 용돈을 효율적으로 활용하고 돈을 펑펑 쓰지 않기 위해서 앞으로 N일 동안 자신이 매일 사용할 금액을 계산하고, 정확히 통장에서 M번, K원 씩 출금해서 사용하기로 결정했습니다. 
현재 수중에 있는 금액으로 하루를 보낼 수 있다면 그대로 소비합니다. 
부족하다면, 수중에 있는 금액은 통장에 넣은 뒤 K원을 인출해서 하루를 생활합니다. 이때, 현우가 매번 출금할 금액 K원의 최솟값을 구하는 프로그램을 작성해주세요.
*
*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	

	int init_left,init_right;
	int n, m; cin >> n >> m;
	vector<int> v;

	int left = -1, right = 0;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v.push_back(temp);
		left = max(left, temp);
		right += temp;
	}

	init_left = left;
	init_right = right;
	long mid;
	long result = 1000000001;
	while (left <= right) {
		mid = (left + right) / 2;
		//cout << "left : " << left << "/ right : " << right << "/ mid : " << mid << '\n';

		long temp = mid;
		int cnt = 1;
		for (int i = 0; i < v.size(); i++) {
			if (temp - v[i] > 0) temp -= v[i];
			else if (temp - v[i] < 0) {
				cnt++;
				temp = mid;
				temp -= v[i];
			}

			else {
				if (i != v.size() - 1)
				{
					cnt++;
					temp = mid;
				}
			}
		}

		//if (temp >= 0 && temp != mid) cnt++;

		//cout << "cnt : " <<  cnt << " ";
		if (cnt <= m) {
			//if (cnt == m) cout << "cnt가 m과 동일합니다" << '\n';
			//else cout << "cnt가 m보다 작습니다" << '\n';
			right = mid - 1;
			if (result > mid) result = mid;
		}

		else if(cnt > m) {
			//cout << "cnt가 m보다 큽니다" << '\n';
			left = mid + 1;
		}
	}
	
	cout << result;

}