#include <exception>
#include <iostream>
#include <utility>
#include <unordered_set>
#include <vector>
#include <memory>
using namespace std;

struct ListNode
{
    int val;
    shared_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, shared_ptr<ListNode> next) : val(x), next(std::move(next)) {}
};

// https://leetcode.com/problems/add-two-numbers/
class Solution
{
public:
    // Local smart-pointer variant: inputs are borrowed through shared ownership.
    shared_ptr<ListNode> addTwoNumbers(shared_ptr<ListNode> l1,
                                       shared_ptr<ListNode> l2)
    {
        auto dummy = make_shared<ListNode>();
        auto tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry != 0)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->val = (sum%10);
            if(l1 || l2 || carry != 0){
            tail->next = make_shared<ListNode>();
            tail = tail->next;
            }

        }
        return dummy;
    }
};

struct TestCase
{
    vector<int> first, second, expected;
    const char *name;
};

shared_ptr<ListNode> makeList(const vector<int> &digits)
{
    auto dummy = make_shared<ListNode>();
    auto tail = dummy;
    for (int digit : digits)
    {
        tail->next = make_shared<ListNode>(digit);
        tail = tail->next;
    }
    return dummy->next;
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
    cout << "Smart Pointer Trial." <<endl;
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
        auto l1 = makeList(test.first);
        auto l2 = makeList(test.second);
        unordered_set<shared_ptr<ListNode>> outputNodes;
        try
        {
            auto result = Solution().addTwoNumbers(l1, l2);
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
        // Break any detected output cycle; shared_ptr cannot collect cycles.
        // The set keeps visited nodes alive while links are detached.
        for (const auto &node : outputNodes)
            node->next.reset();
    }
    cout << '\n'
         << passed << '/' << tests.size() << " tests passed.\n";
    return passed == static_cast<int>(tests.size()) ? 0 : 1;
}
