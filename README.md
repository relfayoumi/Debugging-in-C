# Debugging in C

A small collection of examples, exercises, and notes focused on debugging C programs. This repository aims to teach practical debugging techniques (gdb, valgrind, lldb, printf), common pitfalls in C (undefined behavior, memory leaks, buffer overflows), and how to compile and inspect programs for easy troubleshooting.

## Contents
- Short explanations of common C bugs and how to spot them
- Small example programs and exercises to practice debugging
- Recommended workflows and command snippets for gdb, valgrind, and clang/ gcc

(Adjust paths below to match the repo layout — e.g. `examples/`, `src/`, or `exercises/`.)

## Prerequisites
- A C compiler: gcc or clang
- Make (optional)
- gdb or lldb for interactive debugging
- valgrind for memory checking (Linux / WSL / macOS with alternatives)

## Build (recommended)
If a Makefile exists:
```bash
make
```

Or compile a single file with debugging symbols:
```bash
gcc -g -O0 -Wall -Wextra -std=c11 src/example.c -o bin/example
```
- -g: include debug symbols
- -O0: disable optimizations (easier debugging)
- -Wall -Wextra: enable helpful warnings

## Run
```bash
./bin/example
```

## Quick gdb primer
Compile with -g and no optimizations. Then:
```bash
gdb ./bin/example
# inside gdb
(gdb) break main
(gdb) run
(gdb) next       # step over
(gdb) step       # step into
(gdb) print var
(gdb) backtrace  # see call stack
(gdb) info locals
```

For core dumps:
```bash
ulimit -c unlimited
./bin/example    # lets it crash and produce core
gdb ./bin/example core
```

## Memory debugging with valgrind
Valgrind helps find leaks and invalid memory access:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./bin/example
```

Note: valgrind works best with glibc/linux; use sanitizer options with clang/gcc on other platforms (AddressSanitizer).

## Useful compiler sanitizers
Compile and run with AddressSanitizer and UndefinedBehaviorSanitizer:
```bash
gcc -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer src/example.c -o bin/example-sanitized
./bin/example-sanitized
```

These catch many memory and UB issues at runtime and are faster than valgrind for iterative testing.

## Troubleshooting checklist
- Did you compile with `-g` and without `-O2`/`-O3` for step-by-step debugging?
- Check compiler warnings and fix them before running.
- Use gdb to inspect variables and stack traces.
- Use valgrind or ASan for memory bugs.
- If behavior differs between builds, check optimization flags and undefined behavior.

## Examples & Exercises
Include small isolated examples that reproduce:
- Buffer overflow
- Use-after-free
- Double-free
- Uninitialized memory
- Integer overflow
- Off-by-one errors

For each example, provide:
- A problem statement
- Expected behavior
- A minimal failing program
- Hints and a solution branch/file

## Contributing
- Open issues describing exercises or broken examples
- Submit PRs with improved explanations, test cases, or CI for static checks
- Add platform notes if examples require Linux/macOS/Windows-specific tools

## License
Add a LICENSE file (e.g. MIT) to clarify usage.
