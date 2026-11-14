# 2. Add Two Numbers

**Difficulty:** Medium

**Source:** [LeetCode problem description](https://leetcode.com/problems/add-two-numbers/)

## Task

Two nonempty linked lists encode nonnegative integers. Each node holds one decimal digit, with the least significant digit first. Return a linked list encoding their sum in that same order. Inputs have no leading zeros, except for the number zero itself.

For example, `[2, 4, 3]` encodes 342, so adding `[5, 6, 4]` (465) produces `[7, 0, 8]` (807).

## Examples

| First list | Second list | Result |
| --- | --- | --- |
| `[2,4,3]` | `[5,6,4]` | `[7,0,8]` |
| `[0]` | `[0]` | `[0]` |
| `[9,9,9,9,9,9,9]` | `[9,9,9,9]` | `[8,9,9,9,0,0,0,1]` |

## Constraints

- Each input list contains between 1 and 100 nodes.
- Node values range from 0 to 9.
- Each list encodes a number without leading zeros.

## Local practice

[main.cpp](main.cpp) provides the LeetCode-compatible `ListNode`, a TODO `addTwoNumbers` method, and 14 tests. Tests cover the official examples, zeros, unequal lengths, carries, and 100-node inputs.

Open the C++ file in VS Code. Press **Ctrl+Shift+B** to build or **F5** to debug. Run `main.exe` from this folder for test results. The starter reports `Not implemented yet` until I implement the method.

The task description above is paraphrased from LeetCode.
