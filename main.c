#include <stdio.h>

int main() {
  printf("|=========================|\n");
  printf("| Number System converter |\n");
  printf("|=========================|\n");
  printf("1: input to decimal\n2: decimal to other\n3: any to any\n4: Quit\n");
  int operation;
  printf("Choose 1,2,3 or 4: ");
  scanf("%d",&operation);

  printf("Chosen operation: %d\n",operation);

  return 0;
}
