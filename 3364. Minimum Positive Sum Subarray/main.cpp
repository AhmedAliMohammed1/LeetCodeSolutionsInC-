#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

// Problem: https://leetcode.com/problems/minimum-positive-sum-subarray/
// Find the minimum strictly positive sum of a contiguous subarray
// with length in [l, r]. Return -1 if none exists.
// Constraints: 1 <= l <= r <= nums.size() <= 100;
//              -1000 <= nums[i] <= 1000.
class Solution
{
public:
    int minimumSumSubarray(vector<int> &nums, int l, int r)
    {
        int sum{}, min{-1};
        if (nums.size() <= 100)
        {
            for (int i = 0; i <nums.size(); i++)
            {
                sum=0;
                for(int j=i; j < nums.size() && j-i +1 <= r;j++ ){
                    sum +=nums.at(j);
                    int len = j-i+1;
                    if((  len >= l &&sum > 0 ) && (sum < min || min == -1)){
                        min = sum;
                    }


                }
            }


        }
             return min;

    }
};
struct TestCase
{
    vector<int> nums;
    int l;
    int r;
    int expected;
    const char *name;
};

int main()
{
    const vector<TestCase> tests = {
        {{3, -2, 1, 4}, 2, 3, 1, "Example 1"},
        {{-2, 2, -3, 1}, 2, 3, -1, "Example 2"},
        {{1, 2, 3, 4}, 2, 4, 3, "Example 3"},
        {{5}, 1, 1, 5, "Single positive element"},
        {{0}, 1, 1, -1, "Zero is not positive"},
        {{-5}, 1, 1, -1, "Single negative element"},
        {{0, 0, 0}, 1, 3, -1, "All zeros"},
        {{-3, -2, -1}, 1, 3, -1, "All negative"},
        {{-2, 3, -1}, 3, 3, -1, "Only allowed sum is zero"},
        {{-2, 3, 1}, 3, 3, 2, "Whole array required"},
        {{4, -3, 2}, 1, 1, 2, "Only single elements allowed"},
        {{5, -4, 2}, 2, 2, 1, "Fixed length"},
        {{8, -5, -2}, 2, 3, 1, "Best length equals r"},
        {{2, -10, 3, 4}, 2, 2, 7, "Ignore positive shorter subarrays"},
        {{-10, 5, -4}, 2, 2, 1, "Best subarray ends at last element"},
        {vector<int>(100, 1000), 100, 100, 100000, "Maximum total sum"},
    };

    int passed = 0;
    for (const auto &test : tests)
    {
        auto nums = test.nums;
        try
        {
            int actual = Solution().minimumSumSubarray(nums, test.l, test.r);
            if (actual == test.expected)
            {
                ++passed;
                cout << "PASS: " << test.name << '\n';
            }
            else
            {
                cout << "FAIL: " << test.name << " | expected "
                     << test.expected << ", got " << actual << '\n';
            }
        }
        catch (const exception &error)
        {
            cout << "FAIL: " << test.name << " | " << error.what() << '\n';
        }
    }
    cout << '\n'
         << passed << '/' << tests.size() << " tests passed.\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
