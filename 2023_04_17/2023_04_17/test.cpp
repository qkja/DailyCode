#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
//
//
//
//<<<<<<< HEAD
//using std::cin;
//using std::cout;
//using std::endl;
//
//=======
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> arr = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // ��������
//
//    void Dfs(vector<vector<char>>& image, int row, int col,
//        vector<vector<bool>>& book, int x, int y,
//        char newColor, char oldColor)
//    {
//        image[x][y] = newColor;
//        book[x][y] = false;
//
//        for (size_t i = 0; i < 4; i++)
//        {
//            // �ĸ�λ��
//            int newX = x + arr[i][0];
//            int newY = y + arr[i][1];
//
//            if (!(newX >= 0 && newX < row && newY >= 0 && newY < col))
//                continue;
//            if (image[newX][newY] == oldColor && book[newX][newY] == true)
//            {
//                Dfs(image, row, col, book, newX, newY, newColor, oldColor);
//            }
//        }
//    }
//    void solve(vector<vector<char>>& board)
//    {
//        if (board.empty())
//            return;
//        std::unordered_map<int, std::pair<int, int>> s;
//        int row = board.size();
//        int col = board[0].size();
//        int index = 0;
//        for (int i = 0; i < col; i++)
//        {
//            if (board[0][i] == 'O')
//                s[index++] = std::make_pair(0, i);
//            if (board[row - 1][i] == 'O')
//                s[index++] = std::make_pair(row - 1, i);
//        }
//
//        for (int i = 1; i < row - 1; i++)
//        {
//            if (board[i][0] == 'O')
//                s[index++] = std::make_pair(i, 0);
//            if (board[i][col - 1] == 'O')
//                s[index++] = std::make_pair(i, col - 1);
//        }
//
//        vector<vector<bool>> book(row, vector<bool>(col, true));
//        auto it = s.begin();
//        while (it != s.end())
//        {
//            if (board[it->second.first][it->second.second] == 'O')
//                Dfs(board, row, col, book, it->second.first, it->second.second, 'A', 'O');
//            it++;
//        }
//
//        for (int i = 0; i < row; i++)
//        {
//            for (size_t j = 0; j < col; j++)
//            {
//           if (board[i][j] == 'A')
//                    board[i][j] = 'O';
//                else
//                    board[i][j] = 'X';
//            }
//        }
//    }
//};
//
//
//int main()
//{
//    vector<vector<char>> v = { 
//        {'X', 'O', 'X', 'O', 'X', 'O'},
//        {'O', 'X', 'O', 'X', 'O', 'X'},
//        {'X', 'O', 'X', 'O', 'X', 'O'},
//        {'O', 'X', 'O', 'X', 'O', 'X'} };
//    Solution().solve(v);
//    return 0;
//}
//
//
//
//>>>>>>> fa1279b0c55d97d5d00607e0851b37f4d57d1fb3
//class A
//{
//public:
//	void func()const
//	{
//<<<<<<< HEAD
//		std::cout << "a: " << a << std::endl;
//		std::cout << "b: " << b << std::endl;
//=======
//		std::cout << 'a: ' << a << std::endl;
//		std::cout << 'b: ' << b << std::endl;
//>>>>>>> fa1279b0c55d97d5d00607e0851b37f4d57d1fb3
//		
//		a = 20;
//	/*	A* p = const_cast<A*>(this);
//		p->a = 20;
//		p->b = 20;
//*/
//<<<<<<< HEAD
//		std::cout << "a: " << a << std::endl;
//		std::cout << "b: " << b << std::endl;
//=======
//		std::cout << 'a: ' << a << std::endl;
//		std::cout << 'b: ' << b << std::endl;
//>>>>>>> fa1279b0c55d97d5d00607e0851b37f4d57d1fb3
//	}
//private:
//	mutable int a = 10;
//	int b = 10;
//};
//
//int main()
//{
//	A().func();
//	return 0;
//<<<<<<< HEAD
//}
//
//#include <cstring>
//
//char * strcpy(char * destination, const char * source);
//char * my_strcpy(char * destination, const char * source)
//{
//	// ����������ô������ �ò����Ƕ���������,��������ֱ��ȥ�����
//	int len = strlen(source);
//	for (int i = 0; i < len+1; i++)
//	{
//		*(destination + i) = *(source + i);
//	}
//	return destination;
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	const char* p = "abced";
//	p = my_strcpy(arr, p);
//	while (*(p) != '\0')
//	{
//		std::cout << *p << std::endl;
//		p++;
//	}
//	return 0;
//}
//Appends a copy of the source string to the destination string
//int main()
//{
//	char str[80];
//	strcpy(str, "these ");
//	strcat(str, "strings ");
//	strcat(str, "are ");
//	strcat(str, "concatenated.");
//	puts(str);
//	return 0;
//}
//
//////////////////////////////////////////////////////////////////////////////////////
//
//
// C++�е�ģ��  -- Ҳ���Ǿ�̬��̬
//
// ����ģ�� --> ��Ҫ���α���
//template < class T1...>
//T1 func(T1 t)
//
//˵һ��,���Ǻ���ģ��һ���ǲ���Ҫָ�����ǵ�ģ������ľ������͵�,�Ͼ����ǵ��βο����Ƶ�����,
//�����и���������,������ǵ�û���βο����Ƶ�,��ʱ��Ҫ��ʾָ������
//template < class T1...>
//T1 func(int t)             -----> func<double>(1)
//
//
// ��ģ��   --> ��ʾָ�����ǵ�����
// ���Ҹо���ģ��Ĵ�����Ҫ��Ϊ�����ǵ����е����ʹ��ڵ�,�Ͼ����Ǻ����STL,ע��һ�����ǵ���ģ���������ĳ�Ա����
// �����ģ����з���,��ôע��Ҫ������ģ��
//
//
//
// ģ���������ȱʡ,���ô�������,����������ô�������,��Ϊ��������޷�����
//template<class T = int, typename K>
//T func(int n)
//{
//	return n;
//}
//
//int main()
//{
//	int ret = func<double>(10);
//	std::cout << ret << std::endl;
//	return 0;
//}
//
//����
//
// ģ�����  --> 
// ����ģ�����  --> ��֧����ʽ����ת��  --> �ǳ���
// ������ģ�����--> 
//
//
//
//
//
//
//
//
//
//
//
//ģ���ػ�
// ���ػ�
// ȫ�ػ�
//
//template<>
//bool Less<int*>(int* left, int* right)
//  ȫ�ػ�
//template<>
//class Data<int, char>
// ���ػ�
//template <class T2>
//class Data<int, T2>
// ���ػ�
// ���ػ�
//
//#define min(a,b) ((a) < (b) ? (a) : (b))
//const int size = 10;
//int ia[size];
//int main() {
//	int elem_cnt = 0;
//	int *p = &ia[0];
//	// ��������Ԫ�صĸ���
//	//((p++) < (b) ? (p++) : (b))
//	while (min(p++, &ia[size]) != &ia[size])
//		++elem_cnt;
//	cout << "elem_cnt : " << elem_cnt
//		<< "\texpecting: " << size << endl;
//	return 0;
//=======
//>>>>>>> fa1279b0c55d97d5d00607e0851b37f4d57d1fb3
//}
//
//
//template <class Type, int size>
//Type min(const Type(r_array)[size])
//{
//	/* �ҵ�������Ԫ����Сֵ�Ĳ��������� */
//	Type min_val = r_array[0];
//	for (int i = 1; i < size; ++i)
//	if (r_array[i] < min_val)
//		min_val = r_array[i];
//	return min_val;
//}
//int main()
//{
//	int arr[100] = { -10, 1, 2, 3, 4, 5 };
//	int ret = min<int, 100>(arr);
//	cout << ret << endl;
//	return 0;
//}
//class A
//{
//public:
//	int a = 10;
//	static int name;
//};
//
//int A::name = 10;
//template <class Parm>
//int minus(Parm* par)
//{
//   Parm::name * p; // ����һ��ָ���������ǳ˷��˷�
//}
//
//int main()
//{
//	A a;
//	minus(&a);
//	return 0;
//}
//
//template <class T, class U, class V>
//void foo(T, U, V)
//{
//	cout << "��ʱ" << endl;
//}
//
//int main()
//{
//	foo(1, 1, 1);
//	return 0;
//}
int main()
{

	return 0;
}