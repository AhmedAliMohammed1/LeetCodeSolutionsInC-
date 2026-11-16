#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::string substring{};
        int  maxCounter{};
        for (const auto &oneChar : s)
        {
            std::string::size_type n = substring.find(oneChar);
            if (n == std::string::npos)
            {
                substring.push_back(oneChar);
                if (maxCounter < substring.size())
                {
                    maxCounter = substring.size();
                }
            }
            else
            {
                substring = substring.substr((n+1));
                substring.push_back(oneChar);
            }
        }
        return maxCounter;
    }
};

struct TestCase
{
    std::string input;
    int expected;
    const char *name;
};

int main()
{
    const std::vector<TestCase> tests = {
        {"abcabcbb", 3, "Example 1"},
        {"bbbbb", 1, "Example 2"},
        {"pwwkew", 3, "Example 3"},
        {"", 0, "Empty string"},
        {"a", 1, "Single character"},
        {"abcdef", 6, "All characters distinct"},
        {"abba", 2, "Repeated characters in the middle"},
        {"dvdf", 3, "Longest substring ends at the last character"},
        {"abcdd", 4, "Longest substring starts at the first character"},
        {"abccdefg", 5, "Longest substring after a repetition"},
        {" ", 1, "Single space"},
        {"   ", 1, "Repeated spaces"},
        {"a b!a", 4, "Spaces and punctuation"},
        {"aA1!", 4, "Case-sensitive letters, digit and symbol"},
        {"01234567890", 10, "Repeated digit"},
        {std::string(100000, 'a'), 1, "Maximum length, identical characters"},
        {std::string(99997, 'a') + "bcd", 4, "Maximum length, distinct suffix"},
    };

    int passed = 0;
    for (const auto &test : tests)
    {
        try
        {
            const int actual = Solution().lengthOfLongestSubstring(test.input);
            if (actual == test.expected)
            {
                ++passed;
                std::cout << "PASS: " << test.name << '\n';
            }
            else
            {
                std::cout << "FAIL: " << test.name << " | expected "
                          << test.expected << ", got " << actual << '\n';
            }
        }
        catch (const std::exception &error)
        {
            std::cout << "FAIL: " << test.name << " | " << error.what() << '\n';
        }
    }
    std::cout << '\n'
              << passed << '/' << tests.size() << " tests passed.\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
