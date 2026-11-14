#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i =0 ; i<nums.size();i++)
            hash[nums.at((i))] = i;
        for(int i=0;i<nums.size();i++){
            int deduction = target - nums.at(i);
            if(hash.find(deduction) != hash.end() && hash[deduction] != i){
                return {i,hash[deduction]};
            }

        }

          return {};

    }



};

struct TestCase {
    vector<int> nums;
    int target;
    vector<int> expected;
    const char* name;
};

int main() {
    vector<TestCase> tests = {
        {{2, 7, 11, 15}, 9, {0, 1}, "Example 1"},
        {{3, 2, 4}, 6, {1, 2}, "Example 2"},
        {{3, 3}, 6, {0, 1}, "Example 3: equal values, different indices"},
        {{-3, -2, -4, -8}, -6, {1, 2}, "Negative values"},
        {{-5, 2, 8, 0}, 3, {0, 2}, "Mixed signs"},
        {{0, 4, 3, 0}, 0, {0, 3}, "Two zeros"},
        {{0, 5}, 5, {0, 1}, "Minimum array length"},
        {{3, 2, 4}, 6, {1, 2}, "Cannot reuse the single 3"},
        {{9, 1, 2, 8}, 17, {0, 3}, "First and last elements"},
        {{1, 1, 4, 6}, 10, {2, 3}, "Unrelated duplicates"},
        {{1000000000, -1000000000}, 0, {0, 1}, "Value boundaries"},
        {{-1000000000, 0, 5}, -1000000000, {0, 1}, "Target boundary"},
    };
    vector<int> large(10000, 4);
    large[9998] = 1;
    large[9999] = 2;
    tests.push_back({large, 3, {9998, 9999}, "Maximum array length"});

    int passed = 0;
    for (const auto& test : tests) {
        auto nums = test.nums;
        try {
            auto actual = Solution().twoSum(nums, test.target);
            auto expected = test.expected;
            // The problem accepts either order of the two indices.
            sort(actual.begin(), actual.end());
            sort(expected.begin(), expected.end());
            if (actual == expected) {
                ++passed;
                cout << "PASS: " << test.name << '\n';
            } else {
                cout << "FAIL: " << test.name << " | expected ["
                     << expected[0] << ", " << expected[1] << "], got [";
                for (size_t i = 0; i < actual.size(); ++i) {
                    if (i) cout << ", ";
                    cout << actual[i];
                }
                cout << "]\n";
            }
        } catch (const exception& error) {
            cout << "FAIL: " << test.name << " | " << error.what() << '\n';
        }
    }
    cout << '\n' << passed << '/' << tests.size() << " tests passed.\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
