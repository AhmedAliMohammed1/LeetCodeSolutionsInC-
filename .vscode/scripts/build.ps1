param([Parameter(Mandatory = $true)][string]$SourceDirectory)
$ErrorActionPreference = 'Stop'
$sourcePath = (Resolve-Path -LiteralPath $SourceDirectory).Path
$sources = @(Get-ChildItem -LiteralPath $sourcePath -Filter '*.cpp' -File | Sort-Object Name | ForEach-Object { $_.FullName })
if ($sources.Count -eq 0) { throw "No .cpp files found in $sourcePath. Open a C++ file in the task folder first." }
# All .cpp files in this folder form one program with exactly one main().
$env:Path = 'C:\msys64\ucrt64\bin;' + $env:Path
& 'C:\msys64\ucrt64\bin\g++.exe' -std=c++17 -g -O0 -Wall -Wextra @sources -o (Join-Path $sourcePath 'main.exe')
exit $LASTEXITCODE
