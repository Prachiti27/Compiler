# Compiler in C

A compiler written in C that translates programs written in a custom programming language into x86-64 assembly and builds native Linux executables.

The project explores the fundamentals of compiler construction, including lexical analysis, parsing, abstract syntax tree (AST) processing, assembly code generation, and native executable generation.

## Features

- **Lexical Analysis:** Converts source code into tokens.
- **Parsing:** Processes tokens and builds a tree representation of the program.
- **Code Generation:** Generates x86-64 assembly from the parsed program.
- **Assembly:** Uses NASM to assemble the generated code into an object file.
- **Executable Generation:** Uses GCC to link the object file into a native executable.
- **Control Flow:** Supports `while` loops and conditional expressions in the custom language.
- **Variables and Expressions:** Supports integer variable declarations, assignments, and arithmetic expressions.
- **Program Termination:** Supports an `exit()` statement.

## Tech Stack

- **Language:** C
- **Assembly:** x86-64 NASM
- **Toolchain:** GCC, NASM
- **Environment:** Linux / WSL
- **Build System:** Shell script

## Project Structure

```text
Compiler/
├── main.c                 # Compiler entry point and build pipeline
├── lexerf.c               # Lexical analysis implementation
├── lexerf.h               # Lexer declarations
├── parserf.c              # Parsing implementation
├── parserf.h              # Parser declarations
├── codegeneratorf.c       # Assembly code generation
├── codegeneratorf.h       # Code generator declarations
├── test.pk                # Example source program
├── build.sh               # Build script
├── build/                 # Compiler build artifacts
└── README.md
```

*Update the file tree if your actual repository structure differs.*

## Prerequisites

Install the required tools on Linux or WSL:

```bash
sudo apt update
sudo apt install gcc nasm make
```

`make` is optional if your build script does not use it.

## Build

Clone the repository and enter the project directory:

```bash
git clone <your-repository-url>
cd <repository-directory>
```

Build the compiler:

```bash
chmod +x build.sh
./build.sh
```

The compiler executable is expected to be available at `build/pk`, depending on your build script.

## Usage

Run the compiler from the project root:

```bash
./build/pk test.pk output
```

The command accepts two arguments:

1. `test.pk` — the source file written in the custom language.
2. `output` — the desired name of the generated executable.

The compilation pipeline is:

```text
Source (.pk)
    |
    v
Lexer
    |
    v
Parser
    |
    v
Syntax Tree
    |
    v
Assembly Generation (.asm)
    |
    v
NASM (.o)
    |
    v
GCC Linker
    |
    v
Native Executable
```

The exact output paths depend on the current working directory and the paths configured in the compiler.

## Example Program

```c
int x = 0;
int y = 0;
int z = 0;

int i = 1;

while(i neq 100) {
    x = y;
    y = z;
    z = y + x;
    i = i + 1;
}

exit(0);
```

This example demonstrates variable declarations, arithmetic assignments, a `while` loop, the `neq` comparison operator, and program termination.

Save the program as `test.pk` and compile it using the command shown above.

## Implementation Overview

### 1. Lexer

The lexer reads the source file and converts its contents into tokens. Tokens represent language elements such as keywords, identifiers, integer literals, operators, and punctuation.

### 2. Parser

The parser consumes the token stream and constructs a tree representation of the program. It processes expressions and statements according to the grammar supported by the language.

### 3. Code Generator

The code generator traverses the parsed tree and emits assembly instructions for the target architecture.

### 4. Native Compilation

The compiler invokes NASM to assemble the generated assembly and GCC to link the resulting object file into a native executable.
