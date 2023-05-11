#include <vector>
#include <string>
using namespace std;
//https://leetcode.cn/problems/reverse-string/submissions/
//class Solution {
//public:
    //void reverseString(vector<char>& s) {
    //    if (s.empty())
    //        return;
    //    int left = 0;
    //    int right = s.size() - 1;
    //    while (left < right)
    //        std::swap(s[left++], s[right--]);
    //    return;
//    }
//};

//https://leetcode.cn/problems/reverse-string-ii/submissions/
//class Solution {
//public:
    //void reverseString(std::string& str, int left, int right) {
    //    while (left < right)
    //        std::swap(str[left++], str[right--]);
    //}
//
//    string reverseStr(string s, int k) {
//        if (s.empty())
//            return s;
//        int left = 0;
//        int right = 0;
//        for (; right < s.size(); right++)
//        {
//            if ((right + 1 - left) % (2 * k) == 0)
//            {
//                reverseString(s, left, left + k - 1);
//                left = right + 1;
//            }
//        }
//        // 这里继续判断我们的长度
//        int len = right - left;
//        if (len < k)
//        {
//            reverseString(s, left, right - 1);
//        }
//        else
//        {
//            reverseString(s, left, left + k - 1);
//        }
//        return s;
//    }
//};
//#include <iostream>
//int main()
//{
//    std::string str = "abcdefg";
//    int k = 2;
//
//    std::cout << Solution().reverseStr(str, k) << std::endl;
//    return 0;
//}


// https://leetcode.cn/problems/reverse-words-in-a-string/
class Solution {
public:
    void reverseString(std::string& str, int left, int right) {
        while (left < right)
            std::swap(str[left++], str[right--]);
    }
    string reverseWords(string s) {
        if (s.empty())
            return s;
        // 这里先清晰空格
        std::string str;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (str.empty() || str.back() == ' ')
                    continue;
                else
                    str += s[i];
            }
            else
            {
                str += s[i];
            }
        }
        // 这里最后还是要清晰一下
        if (str.back() == ' ')
            str.erase(str.end() - 1);
        std::size_t begin = 0;
        std::size_t end = 0;
        while (true)
        {
            end = str.find(' ', begin);
            if (end == std::string::npos)
                break;
            
            // 这里是找到了
            reverseString(str, begin, end - 1);
            begin = end + 1;
        }
        reverseString(str, begin, str.size()-1);
        reverseString(str,0, str.size() - 1);
        return std::move(str);
    }
};