# 2. Add Two Numbers - Smart Pointers

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

[main.cpp](main.cpp) adapts my existing solution and all 14 tests to `std::shared_ptr<ListNode>`. Nodes are created with `std::make_shared`; ownership and cleanup are automatic, with no explicit `new` or `delete`. The tests retain cycle detection and detach visited output links after checking the result so even a detected cycle can be released.

The method receives smart pointers by value, so advancing its local copies leaves the input lists intact. Result nodes are allocated separately. Shared ownership lets list heads and traversal cursors refer to the same nodes safely. Avoid creating cycles: shared pointers cannot reclaim cycles automatically.

This is a local C++ ownership exercise. LeetCode requires `ListNode* addTwoNumbers(ListNode*, ListNode*)`, so this smart-pointer version cannot be submitted directly. My original implementation remains in [the original folder](../pointers/).

I keep this version alongside my raw-pointer version to practice ownership with smart pointers.

From the repository root, build and run with PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .vscode/scripts/build.ps1 -SourceDirectory "2. Add Two Numbers/smart_pointers"
$env:Path = 'C:/msys64/ucrt64/bin;' + $env:Path
& './2. Add Two Numbers/smart_pointers/main.exe'
```

In VS Code, open this folder's `main.cpp`, then press **Ctrl+Shift+B** to build or **F5** to debug.

The task description above is paraphrased from LeetCode.
