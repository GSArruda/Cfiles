#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Quinta quest�o :
int main (){
setlocale(LC_ALL,"portuguese");

int anos;
int meses;
int dias;

printf("Digite quantos anos voc� tem : ");
scanf("%d",&anos);
printf("Digite quantos meses voc� tem : ");
scanf("%d",&meses);
printf("Digite quantos dias voc� tem : ");
scanf("%d",&dias);

int total = (365 * anos) + (meses * 30) + dias;

printf("O valor total expresso em dias � de : %d.",total);


return 0;

}
