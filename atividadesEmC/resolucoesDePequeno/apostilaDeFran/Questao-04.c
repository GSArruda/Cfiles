#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Quarta quest�o :
int main (){
setlocale(LC_ALL,"portuguese");

float base;
float altura;
float area;

printf("Digite o valor da base do ret�ngulo(cm) : ");
scanf("%f",&base);
printf("Digite o valor da altura do ret�ntangulo(cm) : ");
scanf("%f",&altura);
area = base * altura;
printf("O valor da �rea do ret�ngulo � %.2f cent�metros. ",area);



return 0;

}
