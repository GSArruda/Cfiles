#include  <stdio.h>
#include  <stdlib.h>
#include  <locale.h>



main(){

setlocale(LC_ALL,"Portuguese");

int x,y;

printf("Digite o primeiro n�mero : ");
scanf("%d",&x);
printf("Digite o segundo n�mero : ");
scanf("%d",&y);


if (x>y){
    printf("O maior n�mero digitado � : %d.\n",x);
}else{
    printf("O maior n�mero digitado � : %d.\n",y);
}














system("pause");

}
