# 3. Longest Substring Without Repeating Characters

**Difficulty:** Medium

**Source:** [LeetCode problem description](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Task

Return the greatest length of a contiguous part of `s` whose characters are all different. Characters cannot be skipped. Uppercase and lowercase letters are distinct.

## Official examples

| Input `s` | Expected length | One valid substring |
| --- | --- | --- |
| `"abcabcbb"` | 3 | `"abc"` |
| `"bbbbb"` | 1 | `"b"` |
| `"pwwkew"` | 3 | `"wke"` |

## Constraints

- `0 <= s.length <= 100000`.
- Input may contain English letters, digits, symbols, and spaces.

## Local practice

[strings/main.cpp](strings/main.cpp) contains the LeetCode-compatible `Solution` class with `int lengthOfLongestSubstring(std::string s)`. This file contains my current string-based implementation.

The 17 named tests cover the official examples, an empty input, one character, distinct characters, repeated characters, substring boundaries, spaces, case sensitivity, digits, symbols, and maximum-length inputs. Expected values are included in the test cases.

From the repository root, build and run with PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .vscode/scripts/build.ps1 -SourceDirectory "3. Longest Substring Without Repeating Characters/strings"
$env:Path = 'C:/msys64/ucrt64/bin;' + $env:Path
& './3. Longest Substring Without Repeating Characters/strings/main.exe'
```

In VS Code, open `strings/main.cpp`, then press **Ctrl+Shift+B** to build or **F5** to debug.

## Map practice

[map/main.cpp](map/main.cpp) contains my work in progress using `std::map`, the same LeetCode method signature, and all 17 tests. This implementation still has failing tests as I practice tracking repeated characters.

This variant has its own subfolder so each program has exactly one `main()`. Open the variant's `main.cpp` to build or debug it in VS Code, or use:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .vscode/scripts/build.ps1 -SourceDirectory "3. Longest Substring Without Repeating Characters/map"
$env:Path = 'C:/msys64/ucrt64/bin;' + $env:Path
& './3. Longest Substring Without Repeating Characters/map/main.exe'
```

Both runners print named PASS/FAIL results and a passed/total summary, and exit with status 1 if any test fails. Building an implementation does not mean the problem is solved.

The task description and examples above are paraphrased from LeetCode.
