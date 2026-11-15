#include <exception>
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>
#include <memory>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// https://leetcode.com/problems/add-two-numbers/
class Solution
{
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode dummy;          // Placeholder before the first result node.
    ListNode* tail = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = carry;

        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        tail->next = new ListNode(digit);
        tail = tail->next;
    }

    return dummy.next;
}
};

struct TestCase
{
    vector<int> first, second, expected;
    const char *name;
};

ListNode *makeList(const vector<int> &digits, vector<ListNode *> &allocated)
{
    ListNode dummy;
    ListNode *tail = &dummy;
    for (int digit : digits)
    {
        tail->next = new ListNode(digit);
        tail = tail->next;
        allocated.push_back(tail);
    }
    return dummy.next;
}

void printDigits(const vector<int> &digits)
{
    cout << '[';
    for (size_t i = 0; i < digits.size(); ++i)
    {
        if (i)
            cout << ", ";
        cout << digits[i];
    }
    cout << ']';
}

int main()
{
    vector<TestCase> tests = {
        {{2, 4, 3}, {5, 6, 4}, {7, 0, 8}, "Example 1"},
        {{0}, {0}, {0}, "Example 2"},
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1}, "Example 3"},
        {{2}, {3}, {5}, "Single digits without carry"},
        {{5}, {5}, {0, 1}, "Single digits with carry"},
        {{0}, {7, 3}, {7, 3}, "Zero plus nonzero"},
        {{7, 3}, {0}, {7, 3}, "Nonzero plus zero"},
        {{1}, {9, 9}, {0, 0, 1}, "Second list longer"},
        {{9, 9}, {1}, {0, 0, 1}, "First list longer"},
        {{9, 1}, {1}, {0, 2}, "Carry stops before end"},
        {{0, 0, 1}, {0, 0, 2}, {0, 0, 3}, "Internal zero digits"},
        {{1, 2, 3}, {4, 5, 6}, {5, 7, 9}, "Equal lengths without carry"},
    };
    vector<int> longExpected(100, 0);
    longExpected.push_back(1);
    tests.push_back({vector<int>(100, 9), {1}, longExpected, "100-digit carry chain"});
    tests.push_back({vector<int>(100, 1), vector<int>(100, 2), vector<int>(100, 3), "Both lists at maximum length"});

    int passed = 0;
    for (const auto &test : tests)
    {
        vector<ListNode *> inputs;
        ListNode *l1 = makeList(test.first, inputs);
        ListNode *l2 = makeList(test.second, inputs);
        unordered_set<ListNode *> outputNodes;
        try
        {
            ListNode *result = Solution().addTwoNumbers(l1, l2);
            vector<int> actual;
            bool valid = true;
            while (result)
            {
                if (!outputNodes.insert(result).second)
                {
                    valid = false; // A cycle is not a valid result.
                    break;
                }
                actual.push_back(result->val);
                result = result->next;
            }
            if (valid && actual == test.expected)
            {
                ++passed;
                cout << "PASS: " << test.name << '\n';
            }
            else
            {
                cout << "FAIL: " << test.name << " | expected ";
                printDigits(test.expected);
                cout << ", got ";
                printDigits(actual);
                if (!valid)
                    cout << " (cycle detected)";
                cout << '\n';
            }
        }
        catch (const exception &error)
        {
            cout << "FAIL: " << test.name << " | " << error.what() << '\n';
        }
        // Delete each known node once, including results that reuse input nodes.
        outputNodes.insert(inputs.begin(), inputs.end());
        for (ListNode *node : outputNodes)
            delete node;
    }
    cout << '\n'
         << passed << '/' << tests.size() << " tests passed.\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
