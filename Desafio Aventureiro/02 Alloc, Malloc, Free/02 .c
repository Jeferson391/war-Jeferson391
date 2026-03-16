#include <stdio.h>

int main() {

int  *a, b;

b = 10;
a = (int*) malloc(sizeof(int));
*a = 20;
a = &b;
free(a);

return 0;
}
