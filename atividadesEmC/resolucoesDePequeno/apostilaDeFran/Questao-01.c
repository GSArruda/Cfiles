#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Primeira quest�o :
int main (){
    setlocale(LC_ALL,"portuguese");
    float num;
    printf("Digite um n�mero inteiro : ");
    scanf("%f",&num);
    float calculo = pow(num,2);
    printf("O resultado � : %.0f",calculo);

return 0;

}
