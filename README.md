# C Number Multitool

A little multi-tool for working with numbers in different bases

![An svg recording showcasing the multitool in action](./multitool.cast.svg)

## Features

- Conversion to and from decimal (only non-negative integers)
- Any to any conversion (base between 2 and 36)
- RPN calculator (integer numbers)
- Check-A-Number function

### RPN 101

Contrary to the commonly used infix notation (2 + 2), in the Reverse Polish Notation the operand follows the argument (2 2 +) 
This in turn allows us to type mathematical equations without the use of parenthesis.

| Infix | RPN |
| -------------- | --------------- |
| a + b | a b + |
| a - b | a b - |
| a * b | a b * |
| a / b | a b / |
| a ^ b | a b ^ |
| √a | a v |
| 2 * 3 | 2 3 * |
| (2 - 1) * 3 + 7 | 2 1 - 3 7 + * |
| 16 / 2 * 4 | 16 2 4 * / |

## Installation

### Precompiled Binary

Download it from the releases page: [GitHub Releases](https://github.com/FraI3mega/c-number-converter/releases)

### Nix

You need to have flakes enabled

```bash
nix run github:FraI3mega/c-number-converter
```

### Compile from Source

You just need the GNU C Compiler, no other dependencies needed

```bash
gcc main.c -o c-number-converter
```

## Attributions

- [W3Schools](https://www.w3schools.com/c/index.php) - A great source for learning C
- Out To C - The ysws from [Hack Club](https://hackclub.com/) for which this project was made
