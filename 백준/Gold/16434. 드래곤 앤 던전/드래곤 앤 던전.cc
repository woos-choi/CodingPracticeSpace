#include <string>
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
	long long int result = 123456000000000000LL, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		long long int temp = mid;
		long long int h_atk = init_atk;

		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			long long int m_hp = v[i].hp, m_atk = v[i].atk;
			if (v[i].type == 1) {

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

