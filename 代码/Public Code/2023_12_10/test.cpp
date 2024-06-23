//#include <iostream>
//#include <math.h>
//int main()
//{
//	const double P = 3.14;
//	double r = 4.2;
//	//std::cin >> r;
//
//	double x = ((double)4) / 3 * P * pow(r, 3.0);
//	double y = 9.1 * pow(10, -2) * ((double)4) / 3 * P * pow(r, 3.0);
//	std::cout << x << " " << y << std::endl;
//	return 0;
//}
//
//
//#include <iostream>
//#include <math.h>
//int main()
//{
//	const double P = 3.14;
//	double r = 0.0;
//	std::cin >> r;
//	double x =  4.0 / 3 * P * pow(r, 3.0);
//	double y = 9.1 * std::pow(10, -2) * 4.0 / 3 * P * std::pow(r, 3.0);
//	std::cout << x << " " << y << std::endl;
//	return 0;
//}


//#include <iostream>
//int main()
//{
//	int a = 0;
//	double b = 0.0;
//	char c = 0;
//	std::cin >> a >> b >> c;
//	auto sum = a + b + c;
//
//	std::cout << sum << std::endl;
//	return 0;
//}

#include<iostream>

using namespace std;

int main()
{
	int num;
	int j = 0;
	int m = 0;
	int k, sum = 0;
	cin >> num;
	while (num != 0)
	{
		m = num % 10;
		cout << m;
		k = num % 10;
		sum += k;
		num /= 10;
		j++;
	}
	cout << endl;
	cout << sum << endl << j;
}