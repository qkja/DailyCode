#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		if (bills.empty() || bills[0] != 5)
			return false;
		std::vector<int> v(3, 0);
		v[0] = 1;
		for (int i = 1; i < bills.size(); ++i)
		{
			switch (bills[i])
			{
			case 5:
				v[0] = v[0] + 1;
				break;
			case 10:
				if (v[0] == 0)
					return false;
				v[0] = v[0] - 1;
				v[1] = v[1] + 1;
				break;
			case 20:
				// ����ѡ�� 10 �� 5Ԫ��
				if (v[1] > 0 && v[0] > 0)
				{
					v[0] -= 1;
					v[1] -= 1;
				}
				else
				{
					if (v[0] > 2)
						v[0] -= 3;
					else
						return false;
				}
				v[2] += 1;
				break;
			default:
				break;
			}
		}
		return true;
	}
};
int main()
{
	std::cout << "f" << std::endl;
	return 0;
}

