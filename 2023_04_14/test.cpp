#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int reuslt = 0;
        if (prices.empty())
            return reuslt;
        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i-1])
            {
                reuslt += (prices[i] - prices[i - 1]);
            }
        }
        return reuslt;
    }
};
//class Solution {
//public:
//    int balancedStringSplit(string s) {
//        if (s.empty())
//            return 0;
//        int count = 0;
//        int balance = 0;
//        for (size_t i = 0; i < s.size(); i++)
//        {
//            if (s[i] == 'R')
//                balance++;
//            else
//                balance--;
//            if (0 == balance)
//                count++;
//        }
//        return count;
//    }
//};