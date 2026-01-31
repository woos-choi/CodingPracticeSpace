#include <string>
#include <climits>
#include <memory.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

class Room {
public:
	int type;
	long long int atk;
	long long int hp;

	
	Room(int type, long long int atk, long long int hp) {
		this->type = type;
		this->atk = atk;
		this->hp = hp;
	}
};

int main() {
	
	int n;
	long long int init_atk;
	cin >> n >> init_atk;

	vector<Room> v;

	unsigned long long int left = 1, right = 0;

	for (int i = 0; i < n; i++) {
		int t;
		long long int a, h;
		cin >> t >> a >> h;
		v.push_back(Room(t, a, h));

		right += a * h;
	}

	//cout << left << " " << right << '\n';
	long long int result = LLONG_MAX, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		long long int temp = mid;
		long long int h_atk = init_atk;

		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			long long int m_hp = v[i].hp, m_atk = v[i].atk;
			if (v[i].type == 1) {

				/*
				* 실수 포인트
				* 1. 여기를 while로 구현하면 시간 초과가 생길 수 있음 -> 나눗셈으로 가능할지 안할지 계산이 가능함
				* 2. 몬스터와 싸운 이후에 내 체력을 계산할 때 몬스터가 때릴 수 있는 횟수가 아니라 내가 몬스터를 때린 횟수보다 1 작은 값으로 떄리는게 맞음
				* 3. result의 initial 값이 매우 커야함 -> #include<climits>에 있는 LLONG_MAX를 사용하면 됨
				*/

				long long int t_1;
				if (m_hp % h_atk == 0) t_1 = m_hp / h_atk;
				else t_1 = (m_hp / h_atk) + 1;

				long long int t_2;
				if (temp % m_atk == 0) t_2 = temp / m_atk;
				else t_2 = (temp / m_atk) + 1;

				if (t_1 <= t_2) {
					temp -= (t_1 - 1) * m_atk;
				}

				else {
					flag = 1;
					break;
				}
			}

			else if (v[i].type == 2) {
				h_atk += m_atk;
				if (temp + m_hp > mid) temp = mid;
				else temp += m_hp;
			}

		}

		if (flag == 0) {
			right = mid - 1;
			result = min(result, mid);
		}

		else {
			left = mid + 1;
		}
	}
	
	cout << result;
}

