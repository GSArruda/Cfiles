
#include "../string.variavel.h"
#include <unistd.h> /* Biblioteca para incuir função sleep */
#include "cores.h"
#define __limparComando "clear screen"
#define limparTela ( system( __limparComando ) , printf( KWHT ) )

#define SN ( KGRN"S"KWHT"/"KRED"N"KWHT )

/*#define tam( __x ) ( ( __x != NULL ) ? ( sizeof( __x ) / sizeof( __typeof__( __x ) ) ) : 0 )*/

char x;

typedef struct{
	char *nomeAtv;
	short status;
	unsigned int horasGast;
	unsigned short int final;
} afazeres;

afazeres *atividades;

short cadastrar( unsigned int qtd );
void editar( unsigned int qtd );
short excluir( unsigned int qtd );

char verificaResp( );

short printaTudo( unsigned int qtd , short estado );

short limpaVet( unsigned int pos , unsigned int qtd );

unsigned int tam( afazeres *ptr );

int main( void ){

	unsigned int opcao;

	atividades = (afazeres *) calloc( 2 , sizeof( afazeres ) );
	atividades[1].final = 1;
	printf( "DEBUG %s %d %d %d\n" , atividades[0].nomeAtv , atividades[0].status , atividades[0].horasGast , atividades[0].final );
	printf( "DEBUG %s %d %d %d\n" , atividades[1].nomeAtv , atividades[1].status , atividades[1].horasGast , atividades[1].final );

	limparTela;

	do{

		printf( "\n----------------------------------------------\n" );
		printf( "Menu:\n" );
		printf( "\tOpcao 1 : Cadastrar\n" );
		printf( "\tOpcao 2 : Consultar todas as tarefas (Editar)\n" );
		printf( "\tOpcao 3 : Excluir\n" );
		printf( "\tOpcao 4 : Relatorio\n" );
		printf( "\n## Para sair digite 0: \n" );
		printf( "----------------------------------------------\n" );

		printf( "\nEscolha a opcao: " );
		scanf( "%u" , &opcao );

		while( opcao < 0 || opcao > 4 ) ( printf( "\nOpção inválida!\nDigite novamente: " ) , scanf( " %u" , &opcao ) );

		limparTela;

		switch( opcao ){
			case 1:
				while( cadastrar( tam( atividades ) ) ){

					printf( "\nDEBUG: %d\n" , tam( atividades ) );
					atividades = (afazeres *) realloc( atividades , ( tam( atividades ) + 1 ) * sizeof( afazeres ) );
					/*printf( "\nDEBUG: %d\n" , tam( atividades ) );*/
					if( atividades == NULL ) { fprintf( stderr , "\n%sPROBLEMA NA ALOCAÇÂO DAS ATIVIDADES!%s" , KRED , KWHT ); exit( 1 ); }
				}
				break;
			case 2:
				editar( tam( atividades ) );
				break;
			case 3:
				while( excluir( tam( atividades ) ) );
				break;
			case 4:
				printf( "\n\n\nRelatório --------------------------------------------------------- " );
				printaTudo( tam( atividades ) , 1 );
				break;
		}

	}while( opcao != 0 );

	return 0;
}

short cadastrar( unsigned int qtd ){

	char resp;

	/* if( qtd > 1 ){ atividades[qtd-2].final = 0; atividades[qtd-1].final = 1; } */

	printf( "\nCriação de atividade: -----------------------------------------------\n" );
	printf( "\nDigite o nome da nova atividade: " );
	pegastr( &atividades[qtd-1].nomeAtv );

	printf( "\nAtividade concluída? (%s) " , SN );
	resp = verificaResp();
	atividades[qtd-1].status = ( resp == 's' || resp == 'S' ) ? 1 : 0 ;

	printf( "\nQuantas horas foram gastas para a atividade? " );
	scanf( " %u" , &atividades[qtd-1].horasGast );
	
	printf( "\nDeseja cadastrar outra atividade? (%s) " , SN );
	resp = verificaResp();

	limparTela;

	atividades[qtd - 1].final = 0;
	atividades[qtd].final = 1;

	printf( "\nAtividades existentes -----------------------------------------------\n" );
	printaTudo( tam( atividades ) , 0 );
	printf( "\n\n\n" );


	
	if( resp == 's' || resp == 'S' ) return 1 ;
	else return 0;

}

void editar( unsigned int qtd ){
	
	unsigned int id = 0; char resp;

	do{

		printf( "\n\nConsulta -------------------------------------------------------\n" );
		if( printaTudo( qtd , 0 ) ) return;

		printf( "\n\nDeseja mudar o estado ou tempo gasto de alguma atividade? (%s) " , SN );
		resp = verificaResp();

		if( resp == 's' || resp == 'S' ){

			printf( "\nDigite qual o ID da atividade que deseja editar: " );
			scanf( " %u" , &id  );

			limparTela;

			printf( "\n---------------------------------------------------------------------" );
			printf( "\n\tID selecionado: %u" , id );
			printf( "\n\tNome: %s" , atividades[id-1].nomeAtv );
			printf( "\n\tStatus: %s" , ( atividades[id-1].status == 0 ) ? "TO-DO" : "DONE" );
			printf( "\n\tTempo gasto: %uh" , atividades[id-1].horasGast );
			printf( "\n---------------------------------------------------------------------" );

			printf( "\n\nDeseja torná-la %s? (%s) " , ( atividades[id-1].status ) ? "Incompleta" : "Completa" , SN );
			resp = verificaResp();
			if( resp == 's' || resp == 'S' ) atividades[id-1].status = !atividades[id-1].status;

			printf( "\n\nDeseja alterar a carga horária da atividade? (%s) " , SN );
			resp = verificaResp();
			if( resp == 's' || resp == 'S' ){
				printf( "\nQuantas horas foram gastas até %s? " , ( atividades[id-1].status ) ? "sua conclusão" : "o momento" );
				scanf( " %u" , &atividades[id-1].horasGast );
			}

			printf( "\n\nConfigurações alteradas!\n\n\n\tAguarde um momento...\n" );
		 	sleep( 3 );

			limparTela;
			continue;

		}

		limparTela;

	}while( resp == 's' || resp == 'S' );

}

short excluir( unsigned int qtd ){

	unsigned int id = 0; char resp;

	printf( "\n\nExcluir -------------------------------------------------------\n" );
	if( printaTudo( qtd , 0 ) ) return 0;

	printf( "\n\n\nDigite qual o ID da atividade deseja excluir: " );
	do{ scanf( " %u" , &id  ); }while( id < 1 || id > qtd );

	printf( "\n\n\nTem certeza da exclusão? (%s) " , SN );
	resp = verificaResp();

	limparTela;

	if( resp == 's' || resp == 'S' ) ( printf( "\nAtividade %u %s!\n" , id , ( limpaVet( id - 1 , qtd ) ) ? KRED"não foi excluída! :(" : KGRN"excluída!" ) , sleep( 2 ) , limparTela );
	if( atividades == NULL && qtd - 1 != 0 ) exit( 1 );

	if( printaTudo( qtd - ( resp == 's' || resp == 'S' ) ? 1 : 0 , 0 ) ) return 0;

	printf( "\n\n%sDeseja excluir outra atividade? (%s) " , KWHT , SN );
	resp = verificaResp();

	limparTela;
	
	if( resp == 's' || resp == 'S' ) return 1;
	return 0;
}

short printaTudo( unsigned int qtd , short estado ){

	unsigned int j = 0 , jTot = 0 , jY = 0;

	if( qtd <= 0 ){ printf( "\n\n%s####### NÂO EXISTEM TAREFAS CADASTRADAS! #######%s\n\n" , KRED , KWHT ); sleep( 2 ); return 1; }

	while( j < qtd ){
		printf( "\n---------------------------------------------------------------------" );
		printf( "\n\tID: %u" , j + 1 );
		printf( "\n\tNome: %s" , atividades[j].nomeAtv );
		printf( "\n\tStatus: %s" , ( atividades[j].status == 0 ) ? "TO-DO" : "DONE" );
		printf( "\n\tTempo gasto: %uh" , atividades[j].horasGast );
		printf( "\n---------------------------------------------------------------------" );
		++j;
	}

	if( estado ){
		j = 0;
		while( j < qtd ){ if( atividades[j].status ) jTot += atividades[j].horasGast , ++jY; ++j; }
		printf("\n\n****Foram feitas %u atividades! (%sParabéns%s!) ****\n\n\tExistem %u atividades pendentes! (%sQue pena%s!)\n\n\tQuantidade total de horas gastas: %u\n\n", jY , KGRN , KWHT , qtd - jY , KRED , KWHT , jTot ); getchar();
		printf( "\nPressione enter para sair..." );	getchar(); limparTela;
	}
	
	return 0;
}

short limpaVet( unsigned int pos , unsigned int qtd ){
	
	int i = 0;

	for( i = pos ; i < qtd ; ++i) if( i != qtd - 1) atividades[i] = atividades[i+1];

	atividades = (afazeres *) realloc( atividades , (qtd - 1 ) * sizeof( afazeres ) );

	if( atividades == NULL && qtd - 1 != 0 ){ fprintf( stderr , "\n%sPROBLEMA NA ALOCAÇÂO DAS ATIVIDADES!%s" , KRED , KWHT ); return 1; }
	return 0;
}

char verificaResp( ){
	char respAct;
	do{ scanf( " %c" , &respAct ); } while( respAct != 's' && respAct != 'S' && respAct != 'n' && respAct != 'N' );
	return respAct;
}

unsigned int tam( afazeres *ptr ){
	static unsigned int pos = 1 , posFin;
	if( ptr->final ){ posFin = pos; pos = 1; return posFin; }
	++pos;	return tam( ++ptr );
}