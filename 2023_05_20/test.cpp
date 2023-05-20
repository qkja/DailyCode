#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

// https://leetcode.cn/problems/largest-rectangle-in-histogram/submissions/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int result = 0;
        heights.push_back(0);
        heights.insert(heights.begin(), 1);
        stack<int> s;
        s.push(0);
        for (int i = 1; i < heights.size(); i++)
        {
            while (!s.empty()&& heights[i] < heights[s.top()])
            {
                int mid = s.top();
                s.pop();
                if (!s.empty())
                {
                    int left = s.top();
                    int right = i;
                    int h = heights[mid];
                    int w = right - left - 1;
                    result = std::max(h * w, result);
                }
            }
            s.push(i);
        }
        return result;
    }
};