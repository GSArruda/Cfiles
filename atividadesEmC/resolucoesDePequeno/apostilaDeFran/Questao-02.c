#include <stdio.h>
#include <locale.h>
#include <math.h>

int main (){
setlocale(LC_ALL,"portuguese");
int a = 10;
int b = 20;
b = a;
a = b;
printf("O valor de A � %d e o valor de B � %d .",a,b);

return 0;

}
