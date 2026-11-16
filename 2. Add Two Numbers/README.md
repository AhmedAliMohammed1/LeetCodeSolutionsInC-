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

## My implementations

- [Pointers](pointers/main.cpp): my LeetCode-compatible implementation using raw pointers and 14 tests.
- [Smart pointers](smart_pointers/main.cpp): my local `std::shared_ptr` version with the same 14 tests. See its [notes](smart_pointers/README.md); its signature differs from LeetCode's.

Each variant is an independent program with its own `main()`. Open the chosen variant's C++ file in VS Code and press **Ctrl+Shift+B** to build or **F5** to debug.

From the repository root, build and run the pointer version:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .vscode/scripts/build.ps1 -SourceDirectory "2. Add Two Numbers/pointers"
$env:Path = 'C:/msys64/ucrt64/bin;' + $env:Path
& './2. Add Two Numbers/pointers/main.exe'
```

For the smart-pointer version, replace `pointers` with `smart_pointers` in both paths.

The task description above is paraphrased from LeetCode.
