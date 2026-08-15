#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int findIndex(char symbol);
const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // length 36

int main() {

  printf("|=========================|\n");
  printf("| Number System converter |\n");
  printf("|=========================|\n");
  printf("1: input to decimal\n2: decimal to other\n3: any to any\n4: Quit\n");
  int operation;
  printf("Choose 1,2,3 or 4: ");
  scanf("%d",&operation);

  switch (operation) {
    case 1:
      printf("1: Convert from input to decimal\n");
      char input[30];
      printf("Type in the input number: ");
      scanf("%s", input);
      printf("%d", findIndex('A'));
      break;
    case 2:
      printf("2: Convert from decimal to other\n");
      break;
    case 3:
      printf("3: Convert from any to any\n");
      break;
    case 4:
      printf("4: Quit\n");
      return 0;
      break;
    default:
      printf("Choose a correct operation\n");
  }

  return 0;
}

int findIndex(char symbol) {
  int index ;
  int i;
  symbol = toupper(symbol);

  for (i = 0;i<36;i++) {
    if (symbol == table[i]) {
      return i;
    }
  }
  exit(1);
}
