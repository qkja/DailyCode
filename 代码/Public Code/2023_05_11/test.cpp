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
//class Solution {
//public:
//    void reverseString(std::string& str, int left, int right) {
//        while (left < right)
//            std::swap(str[left++], str[right--]);
//    }
//    string reverseWords(string s) {
//        if (s.empty())
//            return s;
//        // 这里先清晰空格
//        std::string str;
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            if (s[i] == ' ')
//            {
//                if (str.empty() || str.back() == ' ')
//                    continue;
//                else
//                    str += s[i];
//            }
//            else
//            {
//                str += s[i];
//            }
//        }
//        // 这里最后还是要清晰一下
//        if (str.back() == ' ')
//            str.erase(str.end() - 1);
//        std::size_t begin = 0;
//        std::size_t end = 0;
//        while (true)
//        {
//            end = str.find(' ', begin);
//            if (end == std::string::npos)
//                break;
//            
//            // 这里是找到了
//            reverseString(str, begin, end - 1);
//            begin = end + 1;
//        }
//        reverseString(str, begin, str.size()-1);
//        reverseString(str,0, str.size() - 1);
//        return std::move(str);
//    }
//};

// KMP 算法
// 父串不变,改变字串
// 这里重点是next数组

// https://leetcode.cn/problems/repeated-substring-pattern/
//class Solution {
//public:
//    bool repeatedSubstringPattern(string s) {
//        if (s.empty())
//            return false;
//        std::string str = s;
//        str += s;
//        str.erase(str.begin());
//        str.erase(str.end()-1);
//
//
//        return str.find(s) != std::string::npos;
//    }
//};
// https://leetcode.cn/problems/repeated-substring-pattern/
//class Solution {
//public:
//    void getNext(const std::string& sub, std::vector<int>& next)
//    {
//        if (next.size() == 1)
//            return;
//        next[0] = -1;
//        next[1] = 0;
//        int k = 0;
//        int i = 2;
//        while (i < sub.size())
//        {
//            if (k == -1 || sub[i - 1] == sub[k])
//            {
//                next[i] = k + 1;
//                i++;
//                k++;
//            }
//            else
//            {
//                k = next[k];
//            }
//        }
//    }
//    int kmp(const std::string& str, const std::string& sub, int pos = 0)
//    {
//        if (str.empty() || sub.empty())
//            return -1;
//        int lenStr = str.size();
//        int lenSub = sub.size();
//        if (pos < 0 || pos >= lenStr)
//            return -1;
//        std::vector<int> next(lenStr, -1);
//        getNext(sub, next);
//        int i = pos;
//        int j = 0;
//        while (i < lenStr && j < lenSub)
//        {
//            if (j == -1 || str[i] == sub[j])
//            {
//                i++;
//                j++;
//            }
//            else
//            {
//                j = next[j];
//            }
//        }
//        if (j >= lenSub)
//            return i - j;
//        else
//            return -1;
//    }
//    bool repeatedSubstringPattern(string s) {
//        if (s.empty())
//            return false;
//        std::string str = s;
//        str += s;
//        str.erase(str.begin());
//        str.erase(str.end() - 1);
//
//
//        return kmp(str, s) != -1;
//    }
//};
//https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
//class Solution {
//public:
//    void getNext(const std::string& sub, std::vector<int>& next)
//    {
//        if (next.size() == 1)
//            return;
//        next[0] = -1;
//        next[1] = 0;
//        int k = 0;
//        int i = 2;
//        while (i < sub.size())
//        {
//            if (k == -1 || sub[i - 1] == sub[k])
//            {
//                next[i] = k + 1;
//                i++;
//                k++;
//            }
//            else
//            {
//                k = next[k];
//            }
//        }
//    }
//    int kmp(const std::string& str, const std::string& sub, int pos = 0)
//    {
//        if (str.empty() || sub.empty())
//            return -1;
//        int lenStr = str.size();
//        int lenSub = sub.size();
//        if (pos < 0 || pos >= lenStr)
//            return -1;
//        std::vector<int> next(lenStr, -1);
//        getNext(sub, next);
//        int i = pos;
//        int j = 0;
//        while (i < lenStr && j < lenSub)
//        {
//            if (j == -1 || str[i] == sub[j])
//            {
//                i++;
//                j++;
//            }
//            else
//            {
//                j = next[j];
//            }
//        }
//        if (j >= lenSub)
//            return i - j;
//        else
//            return -1;
//    }
//    int strStr(string haystack, string needle) {
//        if (haystack.size() < needle.size())
//            return -1;
//        return kmp(haystack, needle);
//    }
//};

class Solution {
public:
    int BF(string& haystack, string& needle)
    {
        
        for (size_t i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] != needle[0])
                continue;

            // 此时我们找到第一个相等的
            int begin = i + 1; 
            int j = 1;
            for (; j < needle.size(); j++)
            {
                if (begin < haystack.size() && haystack[begin] != needle[j])
                    break;
                else if (begin < haystack.size() && haystack[begin] == needle[j])
                    begin++;
                else
                    return -1;

            }
            if (j == needle.size())
                return i;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        if (haystack.empty() || needle.empty())
            return -1;
        return BF(haystack, needle);
    }
};

#include <iostream>
int main()
{
    std::cout << Solution().strStr("aaa", "aaaa") << std::endl;
    return 0;
}