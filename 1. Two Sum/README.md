# 1. Two Sum

**Difficulty:** Easy

**Source:** [LeetCode](https://leetcode.com/problems/two-sum/)

## Task

Find two different positions in `nums` whose values total `target`. Return their zero-based indices in either order. Every input guarantees exactly one valid pair. Equal values can be used if they occupy different positions, but one position cannot be used twice.

## Examples

| `nums` | `target` | Indices |
| --- | --- | --- |
| `[2, 7, 11, 15]` | 9 | `[0, 1]` |
| `[3, 2, 4]` | 6 | `[1, 2]` |
| `[3, 3]` | 6 | `[0, 1]` |

The first pair selects `2` and `7`. The second selects `2` and `4`. The third uses the two separate occurrences of `3`.

## Constraints

- `2 <= nums.length <= 10000`
- `-1000000000 <= nums[i] <= 1000000000`
- `-1000000000 <= target <= 1000000000`
- There is exactly one valid pair.

**Follow-up:** Can you solve it in better than O(n squared) time?

## Local practice

[main.cpp](main.cpp) contains a TODO method and 13 tests. The runner accepts either index order and covers duplicates, zeros, negative numbers, boundary values, and the maximum array length.

Open `main.cpp` in VS Code and press **Ctrl+Shift+B** to build or **F5** to debug. Run `main.exe` in this folder to see test results. Tests initially report `Not implemented yet` until I complete the method.

This task description is paraphrased from the linked LeetCode page.
