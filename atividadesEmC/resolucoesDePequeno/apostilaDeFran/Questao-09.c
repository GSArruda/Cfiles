#include  <stdio.h>
#include  <stdlib.h>
#include  <locale.h>
#define print() as printf()



main(){

setlocale(LC_ALL,"Portuguese");

int x;


printf("Digite o valor do n�mero : ");
scanf("%d",&x);

if (x % 2 == 0){
    printf("O n�mero digitado � par.\n");
}else{
    printf("O n�mero digitado � �mpar.\n");
}

print("Ola");














system("pause");

}
