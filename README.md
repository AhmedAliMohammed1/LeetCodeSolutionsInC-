# My LeetCode Journey in C++

This repository is where I share my journey while practicing on LeetCode. I'm working toward solving all the problems, improving my C++ skills, and learning how to write clearer, more efficient solutions along the way.

Each problem has its own folder containing a description, my implementation, and local test cases. This is a learning journal: solutions may change as I discover mistakes, understand new approaches, and improve my code.

## Problems

| Problem | Difficulty | Files |
| --- | --- | --- |
| [1. Two Sum](https://leetcode.com/problems/two-sum/) | Easy | [Description and code](1.%20Two%20Sum/) |
| [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | Medium | [Description](2.%20Add%20Two%20Numbers/) / [Pointers](2.%20Add%20Two%20Numbers/pointers/) / [Smart pointers](2.%20Add%20Two%20Numbers/smart_pointers/) |
| [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Medium | [Description](3.%20Longest%20Substring%20Without%20Repeating%20Characters/) / [Strings](3.%20Longest%20Substring%20Without%20Repeating%20Characters/strings/) / [Map](3.%20Longest%20Substring%20Without%20Repeating%20Characters/map/) |
| [3364. Minimum Positive Sum Subarray](https://leetcode.com/problems/minimum-positive-sum-subarray/) | Easy | [Description and code](3364.%20Minimum%20Positive%20Sum%20Subarray/) |

## Build and debug

Open this repository folder in VS Code with the Microsoft C/C++ extension installed. Open a `.cpp` file inside a problem folder, then use:

- **Ctrl+Shift+B** to build every `.cpp` file in that folder.
- **F5** to build and debug with GDB.

When I practice multiple implementations of a problem, each variant lives in its own subfolder. Each folder containing C++ source files forms one program and should contain exactly one `main()` function. Additional `.cpp` and header files can live alongside it. The test runner is included in `main.cpp`; run the generated `main.exe` to see the results.

The included Windows configuration uses C++17, MSYS2 GCC/G++ at `C:/msys64/ucrt64/bin`, and GDB at `C:/msys64/mingw64/bin/gdb.exe`. Update the paths in `.vscode` if your tools are installed elsewhere.

Problem descriptions are summarized from and linked to LeetCode. My code and notes document my own practice and learning.
