#include <stdio.h>
#include <locale.h>
#include <math.h>

//Apostila de C.
//Terceira quest�o :
int main (){
setlocale(LC_ALL,"portuguese");

int valor;
int ant;
printf("Digite um valor : ");
scanf("%d",&valor);
ant = valor - 1;
printf("O antecessor do valor %d � %d .",valor,ant);





return 0;

}
