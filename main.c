#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findIndex(char symbol);
int toDecimal(char number[], int base);
char *toOther(int number, int base);
int validate(char input[]);

const char lookup_table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // length 36

/*
 * TODO: list of changes
 * - use dynamic input mem size
 * - error handling
 * - other converters
 * - cli
 * - --help
 * - maybe man page
 */
int main() {

  printf("|=========================|\n");
  printf("| Number System converter |\n");
  printf("|=========================|\n");

  while (1) {
    printf("\nChoose an operation\n");
    printf(
        "1: input to decimal\n2: decimal to other\n3: any to any\n4: Quit\n");
    int operation;
    int base;
    int base_out;
    char input[30];
    char *output;
    int number_dec;

    printf("Choose 1,2,3 or 4: ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
      printf("1: Convert from input to decimal\n");

      do {
        printf("Type in the input base (2-36): ");
        scanf("%d", &base);
      } while (base < 2 || base > 36);

      do {
        printf("Type in the input number: ");
        scanf("%s", input);
      } while (validate(input));

      number_dec = toDecimal(input, base);
      if (number_dec == -1) {
        printf("The input contains characters larger than the base\n");
        break;
      }
      printf("The number in decimal is %d\n", number_dec);
      break;
    case 2:
      printf("2: Convert from decimal to other\n");

      do {
        printf("Type in the output base (2-36): ");
        scanf("%d", &base);
      } while (base < 2 || base > 36);

      int input_int;
      do {
        printf("Type in the input number: ");
        scanf("%s", input);
      } while (validate(input));

      output = toOther(input_int, base);
      printf("The number %d in base %d is %s\n", input_int, base, output);
      break;
    case 3:
      printf("3: Convert from any to any\n");

      do {
        printf("Type in the input base (2-36): ");
        scanf("%d", &base);
      } while (base < 2 || base > 36);

      printf("Type in the input number: ");
      scanf("%d", &input_int);

      do {
        printf("Type in the output base (2-36): ");
        scanf("%d", &base);
      } while (base < 2 || base > 36);

      number_dec = toDecimal(input, base);
      if (number_dec == -1) {
        printf("The input contains characters larger than the base\n");
        break;
      }

      output = toOther(number_dec, base_out);

      printf("The number '%s' in base %d is '%s' in base %d", input, base,
             output, base_out);

      break;
    case 4:
      printf("4: Quit\n");
      return 0;
      break;
    default:
      printf("Choose a correct operation\n");
    }
  }
  return 0;
}

int findIndex(char symbol) {
  int index;
  int i;
  symbol = toupper(symbol);

  for (i = 0; i < 36; i++) {
    if (symbol == lookup_table[i]) {
      return i;
    }
  }
  exit(1);
}

int toDecimal(char number[], int base) {
  int length = strlen(number);
  int i;
  int decimal_number = 0;

  for (i = 0; i < length; ++i) {
    int digit = findIndex(number[i]);
    if (digit > base - 1) {
      return -1;
    }
    decimal_number = (decimal_number * base) + digit;
  }

  return decimal_number;
}

char *toOther(int number, int base) {
  char static other_number[30] = "";
  int symbol_number;
  int len = 0;
  int index;
  for (; number > 0; number = number / base) {
    symbol_number = number % base;
    for (index = len - 1; index >= 0; index--) {
      other_number[index + 1] = other_number[index];
    }
    other_number[0] = lookup_table[symbol_number];
    len++;
  }
  return other_number;
}

int validate(char input[]) {
  int i;
  for (i = 0; i < strlen(input); i++) {
    int symbol = (int)input[i];
    if ((symbol > 47 && symbol < 58) || (symbol > 64 && symbol < 91) ||
        (symbol > 96 && symbol < 123)) {
      continue;
    }
    printf("Invalid character at %d: %c\n", i + 1, input[i]);
    return 1;
  }
  return 0;
}
