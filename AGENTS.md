# Instructions for AI contributors

This repository shares my journey practicing LeetCode in C++. Help me learn while preserving my own implementations.

## Create a new problem

1. Read the requested LeetCode page to verify the title, number, difficulty, method signature, examples, and constraints. If the page cannot be accessed, explain the limitation and do not invent details.
2. Create a root-level folder named `<number>. <Exact Problem Title>`, following `3364. Minimum Positive Sum Subarray`.
3. Add `README.md` inside the folder with the title, difficulty, direct LeetCode link, a concise paraphrase of the task, examples with expected results, constraints, and local build/run instructions. Attribute the description to LeetCode.
4. Add `main.cpp` with explicit standard-library includes, the LeetCode-compatible `Solution` class and method signature, and a TODO implementation. Unless I ask for a solution, leave the method unimplemented and throw `std::logic_error("Not implemented yet")`; do not reveal the algorithm.
5. Include a local test runner in `main.cpp`: official examples plus meaningful boundary cases, verified expected results, named PASS/FAIL output, a passed/total summary, and nonzero exit status if any test fails. Catch the unimplemented exception so the starter still runs.
6. Update the problem table in the root README with the title, difficulty, LeetCode URL, and relative folder link. Keep its first-person learning-journey tone.

## Preserve my practice

- Read current files before editing. Never overwrite an existing solution or remove my tests without an explicit request.
- When I ask why code fails, inspect the latest code and explain a concrete failing example. Do not change my implementation unless requested.
- Keep changes scoped to the requested problem and necessary documentation/configuration.

## Build and verify

- Use C++17. Every problem folder is an independent program with exactly one `main()`.
- Multiple `.cpp` files are supported in the same folder; headers may live beside them. The build script compiles all `.cpp` files directly in the active file's folder. Do not link different problem folders together.
- VS Code: Ctrl+Shift+B builds; F5 builds and debugs. Keep `.vscode/tasks.json`, `launch.json`, and `c_cpp_properties.json` consistent.
- Windows compiler: `C:/msys64/ucrt64/bin/g++.exe`. Debugger: `C:/msys64/mingw64/bin/gdb.exe`. Use g++ for C++ linking, and keep the UCRT64 bin directory in the program PATH.
- From the repository root, build with:
  `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .vscode/scripts/build.ps1 -SourceDirectory "<problem folder>"`
- Check a new starter compiles; its TODO test failures are expected. For an implemented solution, run its executable and report test results honestly.
- Do not commit executables, object files, or temporary verification artifacts. Respect `.gitignore`.

## Git

- Do not commit or push unless requested. When requested, review the staged changes and never force-push or discard existing work.
- Do not mark problems solved merely because a starter was created or compiled.
