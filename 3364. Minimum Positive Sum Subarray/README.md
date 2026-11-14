# 3364. Minimum Positive Sum Subarray

**Difficulty:** Easy
**Source:** [LeetCode problem description](https://leetcode.com/problems/minimum-positive-sum-subarray/)

## Task

Given an integer array `nums` and length limits `l` and `r`, examine contiguous portions of the array containing between `l` and `r` elements, including both limits.

Among the portions with a strictly positive sum, return the smallest sum. Return `-1` when no portion qualifies. Elements must be adjacent; you cannot skip elements. A sum of zero does not qualify.

## Examples

| `nums` | `l` | `r` | Result |
| --- | --- | --- | --- |
| `[3, -2, 1, 4]` | 2 | 3 | 1 |
| `[-2, 2, -3, 1]` | 2 | 3 | -1 |
| `[1, 2, 3, 4]` | 2 | 4 | 3 |

In the first example, `[3, -2]` has sum `1`, the smallest eligible positive sum. In the second, no allowed subarray has a positive sum. In the third, `[1, 2]` gives the minimum, `3`.

## Constraints

- `1 <= nums.length <= 100`
- `1 <= l <= r <= nums.length`
- `-1000 <= nums[i] <= 1000`

## Local practice

[main.cpp](main.cpp) contains my implementation and a test runner with 16 cases, including the examples, zero and negative sums, fixed lengths, array boundaries, and the maximum total sum.

Build with **Ctrl+Shift+B** while this folder's C++ file is active. Run `main.exe` from this folder to check the test results, or press **F5** to debug.
