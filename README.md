# Caesar Cipher
A simple console encryption tool written in **modern C++**. Encrypts and decrypts text using the classic Caesar cipher — a substitution cipher that shifts each letter of the alphabet by a fixed number of positions.

## How It Works
- Each letter is shifted forward (encrypt) or backward (decrypt) by a user-defined amount.
- **Uppercase and lowercase** letters are handled independently and keep their case.
- **Non-letter characters** (spaces, punctuation, digits) pass through unchanged.
- Shift values can be **any integer** — negative shifts and values larger than 26 are handled safely via modular arithmetic.

### Example
Input:  Hello, World!
Shift:  3
Output: Khoor, Zruog!


## Download & Run (Windows)
The easiest way to try it — no build tools required:

1. Go to the [Releases](../../releases) page of this repo.
2. Download `caesar-cipher.exe` from the latest release.
3. Double-click the `.exe`, or run it from a terminal:
.\caesar-cipher.exe
> **Note:** Windows SmartScreen may warn you about an unsigned executable. Click **More info → Run anyway** if you trust the source. Smart App Control (Windows 11) may block it entirely — if so, run from PowerShell or build from source.

**Requirements:** 64-bit Windows 10/11.

## Usage
The program runs interactively:
Would you like to Encrypt or Decrypt? Encrypt
Enter text: Hello, World!
Enter shift amount: 3
Encrypted text: Khoor, Zruog!

To decrypt, run again with the same shift value and "Decrypt" mode.

## Project Structure
| File | Purpose |
|------|---------|
| `main.c++` | Cipher logic (`encryptChar`, `decryptChar`) and interactive prompt loop |
| `CMakeLists.txt` | CMake build configuration |
| `.gitignore` | Excludes build artifacts and IDE files |

The cipher functions are pure (no state) and operate on one character at a time. The main loop iterates the input string by reference, so transformations happen in place.

## Build From Source
### Requirements
- **C++20-capable compiler** (GCC 10+, Clang 10+, MSVC 2019+)
- **CMake 3.15 or later**

Tested with **MinGW g++ (bundled with CLion)** on Windows.

### Steps
1. Clone the repo:
git clone [https://github.com/Seamus-Hennigan/caesar-cipher.git](https://github.com/Seamus-Hennigan/ceasar-cipher)
cd caesar-cipher
2. Configure and build with CMake:
cmake -B build
cmake --build build
3. Run the resulting executable from the `build/` directory:
.\build\caesar-cipher.exe

Alternatively, open the project folder in **CLion** and use the built-in build/run buttons.

## Security Disclaimer
This is a **learning project**. The Caesar cipher is one of the oldest and weakest known ciphers — it can be broken by hand in seconds with frequency analysis or simple brute force (there are only 25 possible keys). **Do not use this for anything that needs to actually stay secret.** It's here as an exercise in C++ fundamentals: character arithmetic, modular math, string manipulation, and basic I/O.

## Author
Seamus Hennigan
