#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1 || numRows >= len)
        {
            return s;
        }

        std::string result;
        result.resize(len);
        int t = 2 * numRows - 2; // ����������
        int index = 0;
        for (int i = 0; i < numRows; i++)
        {
            // i ��ǰ������i ��
            for (int j = i, nextColTop = t; j < len;  nextColTop += t,j+= t)
            {
                result[index++] = s[j];
                if (i >= 1 && i <= numRows - 2 && nextColTop - i < len)
                {
                    result[index++] = s[nextColTop-i];
                }
            }
        }
        return result;
    }
};