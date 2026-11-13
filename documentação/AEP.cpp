#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include<unistd.h>
bool sair = false;
int opcao;
int prox = 0;
int planejada = 0;
int realizadas = 0;

struct ca_cadastro{
char escola [100];
char profissionais [100];
char acoes [100];
int datas;
int status;
int dataacao;
char NomeAcao[100];
int codigoacao;
int codigoescola;
int codigoprofissional;
char descricaodata [100];
};

struct ca_cadastro cadastro [100];

void menu (){
	printf("1 - Cadastrar\n");
	printf("2 - Consultar\n");
	printf("3 - Listar datas ocupadas\n");
	printf("4 - Gerar relatório\n");
	printf("5 - Alterar Cadastro\n");
	printf("6 - Remover Cadastro\n");
	printf("7 - Sair do sistema\n");
	printf("\nSelecione uma opção: ");
}

void cadastrar_escola(){
		system("CLS");
            if (prox < 100) {

                printf("\nDigite o código da Escola: ");
                scanf("%i", &cadastro[prox].codigoescola);

                for(int i = 0; i < prox; i++){
                    if(cadastro[i].codigoescola == cadastro[prox].codigoescola){
                        printf("\nEsse codigo ja esta cadastrado!\n");
                        system("pause");
                        return;
                    }
                }
                
                printf("\nDigite o Nome da Escola: ");
                fflush(stdin);
                fgets(cadastro[prox].escola, 100, stdin);
                
                prox++;
                
                printf("\nEscola registrada com sucesso.\n\n");
                system("pause");

            } else {
                printf("Limite de cadastros atingido.");
                system("pause");
            }
}
void cadastrar_profissional(){
			system("CLS");
            if (prox < 100) {

                printf("\nDigite o código do Profissional: ");
                scanf("%i", &cadastro[prox].codigoprofissional);

                for(int i = 0; i < prox; i++){
                    if(cadastro[i].codigoprofissional == cadastro[prox].codigoprofissional){
                        printf("\nEsse codigo ja esta cadastrado!\n");
                        system("pause");
                        return;
                    }
                }
                
                printf("\nDigite o Nome do Profissional: ");
                fflush(stdin);
                fgets(cadastro[prox].profissionais, 100, stdin);
                
                prox++;
                
                printf("\nProfissional registrado com sucesso.\n\n");
                system("pause");

            } else {
                printf("Limite de cadastros atingido.");
                system("pause");
            }
}
void cadastrar_data(){
	system("CLS");
                if(prox < 100) {
            	printf("Quem estará ocupado? \n[1] Escola [2] Profissional\n");
            	scanf("%i", &opcao);
            	
            	if(opcao==1){
            	system("CLS");
				printf("Digite a Data sem Espaços ou Barras. DIAMÊSANO (ex: 31122008)");
                printf("\n\nDigite a Data: ");
                scanf("%i", &cadastro[prox].datas);
               
               for(int i = 0; i < prox; i++){
                    if(cadastro[i].datas == cadastro[prox].datas){
                        printf("\nEssa data ja esta ocupada!\n");
                        system("pause");
                        return;
                    }
                }
               
			    printf("\nDigite o Codigo da Escola que estará Ocupada nessa Data: ");
               	scanf("%i", &cadastro[prox].codigoescola);
               
			   int existe = 0;

				for(int i = 0; i < prox; i++){
   				 
				if(cadastro[i].codigoescola == cadastro[prox].codigoescola && cadastro[i].escola[0] != '\0'){

        		existe = 1;
        		
       			strcpy(cadastro[prox].escola, cadastro[i].escola);
       			 
				break;
    }
}
		
				if(existe == 0){
					
  			    do{
  			    system ("CLS");
  			    printf("\nEssa Escola Não foi Cadastrada! Deseja Cadastrar essa Escola? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_escola();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{
   				printf("\nBreve Descrição da Ocupação do Dia: ");
                fflush(stdin);
                fgets(cadastro[prox].descricaodata, 100, stdin);
				
				cadastro[prox].dataacao = 0;
				
				prox++;
                
                printf("\nData registrada com sucesso.\n\n");
                system("pause");
                
				}
    
				}
			
				else if(opcao==2){
					
				system("CLS");
				
				printf("Digite a Data sem Espaços ou Barras. DIAMÊSANO (ex: 31122008)");
                printf("\nDigite a Data: ");
                scanf("%i", &cadastro[prox].datas);
                
                for(int i = 0; i < prox; i++){
                    if(cadastro[i].datas == cadastro[prox].datas){
                        printf("\nEssa data ja esta ocupada!\n");
                        system("pause");
                        return;
                    }
                }
				
				printf("\nDigite o  do Profissional que estará Ocupado nessa Data: ");
                scanf("%i", &cadastro[prox].codigoprofissional);
				
				int existe = 0;

				for(int i = 0; i < prox; i++){
   				
				if(cadastro[i].codigoprofissional == cadastro[prox].codigoprofissional && cadastro[i].profissionais[0] != '\0'){

        		existe = 1;
        		
        		strcpy(cadastro[prox].profissionais, cadastro[i].profissionais);
        		
        		break;
    }
}
				
				if(existe==0){
				do{
  			    system ("CLS");
  			    printf("\nEsse Profissional Não foi Cadastrado! Deseja Cadastrar esse Profissional? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_profissional();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{     
			   	printf("\nBreve Descrição da Ocupação do Dia: ");
                fflush(stdin);
                fgets(cadastro[prox].descricaodata, 100, stdin);
				
				cadastro[prox].dataacao = 2;
				
				prox++;
				
                
                printf("\nData registrada com sucesso.\n\n");
                system("pause");
            } 
            
				}else{
				printf("Opção Invalida !\n\n");
				system("pause");
				}
				
			}else{
                printf("Limite de cadastros atingido.\n\n");
                system("pause");
            }                            
}
void cadastrar_acao(){
		system("CLS");
            if (prox < 100) {

                printf("\nDigite o código da ação: ");
                scanf("%i", &cadastro[prox].codigoacao);

                for(int i = 0; i < prox; i++){
                    if(cadastro[i].codigoacao == cadastro[prox].codigoacao){
                        printf("\nEsse codigo ja esta cadastrado!\n");
                        system("pause");
                        return;
                    }
                }

                printf("\nData a registrar: ");
                scanf("%i", &cadastro[prox].datas);

                for(int i = 0; i < prox; i++){
                    if(cadastro[i].datas == cadastro[prox].datas){
                        printf("\nEssa data ja esta ocupada!\n");
                        system("pause");
                        return;
                    }
                }

                printf("\nNome da ação: ");
                fflush(stdin);
                fgets(cadastro[prox].NomeAcao, 100, stdin);

                printf("\nDescrição da ação: ");
                fflush(stdin);
                fgets(cadastro[prox].acoes, 100, stdin);

                printf("\nCodigo da escola: ");
                scanf("%i", &cadastro[prox].codigoescola);
 				
				int existe = 0;

				for(int i = 0; i < prox; i++){
   				if(cadastro[i].codigoescola == cadastro[prox].codigoescola &&
      			cadastro[i].escola[0] != '\0'){

        		existe = 1;
        		strcpy(cadastro[prox].escola, cadastro[i].escola);
       			break;
    }
}
		
				if(existe == 0){
					
  			    do{
  			    system ("CLS");
  			    printf("\nEssa Escola Não foi Cadastrada! Deseja Cadastrar essa Escola? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_escola();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{
                printf("\nCodigo do profissional: ");
                scanf("%i", &cadastro[prox].codigoprofissional);

				int existe = 0;

				for(int i = 0; i < prox; i++){
   			
			   	if(cadastro[i].codigoprofissional == cadastro[prox].codigoprofissional && cadastro[i].profissionais[0] != '\0'){

      			existe = 1;
      			
        		strcpy(cadastro[prox].profissionais, cadastro[i].profissionais);
        		
       			break;
    }
}
				
				if(existe==0){
				do{
  			    system ("CLS");
  			    printf("\nEsse Profissional Não foi Cadastrado! Deseja Cadastrar esse Profissional? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_profissional();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{    
				cadastro[prox].status = 0;
				cadastro[prox].dataacao = 1;
				planejada++;
				prox++;
                printf("\nAção registrada com sucesso.\n\n");
               
                system("pause");
            }
}
            } else {
                printf("Limite de cadastros atingido.");
                system("pause");
            }
}





void cadastrar(){
	do{
    system("CLS");
    printf("1. CADASTRO DE AÇÃO\n");
    printf("2. CADASTRO DE ESCOLA");
    printf("\n3. CADASTRO DE PROFISSIONAIS");
    printf("\n4. CADASTRO DE DATAS OCUPADAS\n");
    printf("5. VOLTAR\n");
    printf("\nDigite uma Opção de Cadastro: ");
    scanf("%i", &opcao);

    switch(opcao){

        case 1:
			cadastrar_acao();
            break;

        case 2:
        	cadastrar_escola();
            break;

        case 3:
        	cadastrar_profissional();
            break;

        case 4:
        	cadastrar_data();
            break;
            
        case 5:
        	return;
        	break;
        
		default:
            printf("Escolha Invalida");
            sleep(1);
			break;
    }
 }
 
 while(opcao < 1 || opcao > 4);

}

void consultar_acoes(){
	int codigo;
    int encontrar = 0;

    system ("CLS");

    printf("CONSULTAR AÇÕES\n");

    printf("Digite o codigo da ação: ");
    scanf("%i", &codigo);

    for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo && cadastro[i].dataacao == 1){

            printf("\nAÇÃO:\n");
            printf("\n===================");
            printf("\nCodigo: %i", cadastro[i].codigoacao);
            printf("\nNome da ação: %s", cadastro[i].NomeAcao);
            printf("Data da ação: %i", cadastro[i].datas);
            printf("\nDescrição da ação: %s", cadastro[i].acoes);
            printf("Escola: %s", cadastro[i].escola);
            printf("Profissional: %s", cadastro[i].profissionais);
            if(cadastro[i].status==0){
            printf("Status: Planejada");
			}if(cadastro[i].status!=0){
			printf("Status: Realizada");
			}
            printf("\n===================\n");
            encontrar = 1;
            break;
        }
    }
    if (encontrar == 0) {
          printf("\nCadastro Não Localizado.\n\n");
    }
    system ("pause");
}
 
void consultar_escola(){
	int codigo;
    int encontrar = 0;

    system ("CLS");

    printf("CONSULTAR ESCOLA\n");

    printf("Digite o Codigo da Escola: ");
    scanf("%i", &codigo);

    for(int i = 0; i < prox; i++){

        if (cadastro[i].codigoescola == codigo) {

            printf("\nESCOLA:\n");
            printf("\n===================");
            printf("\nCodigo: %i", cadastro[i].codigoescola);
            printf("\nNome da Escola: %s", cadastro[i].escola);
            printf("\n===================\n");

            encontrar = 1;
            break;
        }
    }
    if (encontrar == 0) {
        printf("\nCadastro Não Localizado.\n\n");
    }
    system ("pause");
}

void consultar_profissionais(){
	int codigo;
    int encontrar = 0;

    system ("CLS");

    printf("CONSULTAR PROFISSIONAL\n");

    printf("Digite o Codigo do Profissional: ");
    scanf("%i", &codigo);

    for(int i = 0; i < prox; i++){

        if (cadastro[i].codigoprofissional == codigo) {

            printf("\nPROFISSIONAL:\n");
            printf("\n===================");
            printf("\nCodigo: %i", cadastro[i].codigoprofissional);
            printf("\nNome do Profissional: %s", cadastro[i].profissionais);
            printf("\n===================\n");

            encontrar = 1;
            break;
        }
    }
    if (encontrar == 0) {
        printf("\nCadastro Não Localizado.\n\n");
    }
    system ("pause");
}



void consultar(){
	do{
	system("CLS");
	printf("O que você deseja consultar?\n [1] Ações. \n [2] Escolas.\n [3] Profissionais.\n [4] Voltar");
	scanf("%i", &opcao);

	switch(opcao){
		case 1:
			consultar_acoes();
			break;
		case 2:
			consultar_escola();
			break;
		case 3:
			consultar_profissionais();
			break;
		case 4:
			return;
			break;
		default:
			printf("Opção Invalida!");
			sleep(1);
			break;
	}
	}while(opcao < 1 || opcao > 3);
}
void ListarDatasOcupadas(){
	int encontrar=0;
	
	system("CLS");
	
    printf("DATAS OCUPADAS\n");
    
    int i;
    
    for(i = 0; i < prox; i++){
        if(cadastro[i].datas != 0){
            break;
        }
    }

    if(i == prox){

        printf("\nNenhuma Data Cadastrada!\n\n");

    }else{
    
   for(int i = 0; i < prox; i++){
   	
    if(cadastro[i].datas != 0){
    	printf("\n===================");
			encontrar=1;
            printf("\nData: %i", cadastro[i].datas);
            
            if(cadastro[i].dataacao == 1){

                printf("\nCodigo e Nome da ação: Cod. %i: %s", cadastro[i].codigoacao, cadastro[i].NomeAcao);
                printf("Descrição: %s", cadastro[i].acoes);

            }else if(cadastro[i].dataacao == 0){

                printf("\nCodigo e Nome da Escola: Cod. %i: %s", cadastro[i].codigoescola, cadastro[i].escola);
                printf("Descrição: %s", cadastro[i].descricaodata);

            }else if(cadastro[i].dataacao == 2){

                printf("\nCodigo e Nome do Profissional: Cod. %i: %s", cadastro[i].codigoprofissional, cadastro[i].profissionais);
                printf("Descrição: %s", cadastro[i].descricaodata);

            }

            printf("\n===================\n");
	} 	
    }
}
    system("pause");
}
void listar_acoes(){
	
	system ("CLS");
	printf("\nLISTA DAS AÇÕES\n");
		
		for(int i = 0; i < prox; i++){
			if(cadastro[i].dataacao == 1){
		
		printf("\n===================");
		printf("\nCodigo: %i", cadastro[i].codigoacao);
        printf("\nNome da ação: %s", cadastro[i].NomeAcao);
        printf("Data da ação: %i", cadastro[i].datas);
        printf("\nDescrição da ação: %s", cadastro[i].acoes);
        printf("Escola: %s", cadastro[i].escola);
        printf("Profissional: %s", cadastro[i].profissionais);
        if(cadastro[i].status==0){
        printf("Status: Planejada");
		}if(cadastro[i].status!=0){
		printf("Status: Realizada");
		}
		printf("\n===================\n");
	}}
	system("pause");
}

void GerarRelatorios(){
	do{
	system ("CLS");
	printf("\nRELATORIOS DAS AÇÕES\n");
	
	printf("\n===================");
	printf("\nNumero de Ações Planejadas: %i", planejada);
	printf("\nNumero de Ações Realizadas: %i", realizadas);
	printf("\n===================");
	
	printf("\n\nDeseja ver uma lista de todas as ações? [1] Sim [2] Não\n");
	scanf("%i", &opcao);
	
	switch(opcao){
		case 1:
			listar_acoes();
			break;
		case 2:
			system("pause");
			break;
		default:
			printf("Opção Invalida!");
			break;
	}
}	while(opcao < 1 || opcao > 2);
	
}

void status_acao(){
	system("CLS");
	
	int codigo;
	int encontrar=0;
	
	printf("Digite o Codigo da Ação que Deseja Colocar como Finalizada: ");
	scanf("%i", &codigo);
	
	  for (int i = 0; i < prox; i++) {

        if (cadastro[i].codigoacao == codigo) {
		
		if(cadastro[i].status == 0){

    	planejada--;
    	realizadas++;

    	cadastro[i].status = 1;

   		 printf("Mudança Confirmada!\n\n");
		break;
		
		}else{
    	printf("Essa ação já foi realizada!\n");
} 
            
        }system("pause");
    }
	
	if (encontrar == 0) {

        printf("\nCodigo Não Localizado.\n");

    }
    system("pause");
}
void informacoes_acao(){
	int codigo;
    int encontrar = 0;

    system("CLS");

    printf("ALTERAR CADASTRO\n");

    printf("Digite o Codigo da Ação: "); 
    scanf("%i", &codigo);

	for(int i = 0; i < prox; i++){

        if (cadastro[i].codigoacao == codigo) {
	
	encontrar++;
	
	printf("Você Deseja Alterar: \n [1] Tudo. \n [2] Data. \n [3] Nome da Ação. \n [4] Descrição da Ação. \n [5] Escola. \n [6] Profissional. \n [7] Sair.\n");
    scanf("%i", &opcao);
    
    do{
    
	switch(opcao){
		
		case 1:
			
		system("CLS");
		
		for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo){

            printf("\nDigite a nova Data: ");
            scanf("%i", &cadastro[i].datas);

			for(int j = 0; j < prox; j++){
                    if(cadastro[j].datas == cadastro[i].datas){
                        printf("\nEssa data ja esta ocupada!\n");
                        system("pause");
                    }
                }

            printf("\nDigite o novo nome da Ação: ");
            fflush(stdin);
            fgets(cadastro[i].NomeAcao, 100, stdin);

            printf("\nDigite a nova Descriçao: ");
            fflush(stdin);
            fgets(cadastro[i].acoes, 100, stdin);

            printf("\nDigite o novo Codigo da Escola: ");
            scanf("%i", &cadastro[i].codigoescola);

			int existe = 0;

				for(int i = 0; i < prox; i++){
    			if(cadastro[i].codigoescola, cadastro[prox].codigoescola){
       			 existe = 1;
  					 }
							}
		
				if(existe == 0){
					
  			    do{
  			    system ("CLS");
  			    printf("\nEssa Escola Não foi Cadastrada! Deseja Cadastrar essa Escola? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_escola();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{

            printf("\nDigite o novo Codigo do Profissional: ");
            scanf("%i", &cadastro[prox].codigoprofissional);
			
				int existe = 0;

				for(int i = 0; i < prox; i++){
    			if(cadastro[i].codigoprofissional, cadastro[prox].codigoprofissional){
       			 existe = 1;
  					 }
							}
				
				if(existe==0){
				do{
  			    system ("CLS");
  			    printf("\nEsse Profissional Não foi Cadastrado! Deseja Cadastrar esse Profissional? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_profissional();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{ 

            printf("\nCadastro alterado com sucesso!\n");
			system("pause");
            break;
        }}}}
			break;
			
		case 2:
			
			system("CLS");
				for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo){
			
			printf("\nDigite a nova Data: ");
            scanf("%i", &cadastro[prox].datas);

			for(int i = 0; i < prox; i++){
                    if(cadastro[i].datas == cadastro[prox].datas){
                        printf("\nEssa data ja esta ocupada!\n");
                        system("pause");
                    }
                }
			
		}}
			break;
			
		case 3:
			
			system("CLS");
			
			for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo){
        	
			printf("\nDigite o novo nome da Ação: ");
            fflush(stdin);
            fgets(cadastro[i].NomeAcao, 100, stdin);
            
            printf("\nCadastro alterado com sucesso!\n");
            
            system("pause");
            
			break;
		}}
		
		case 4:
			
			system("CLS");
			
			for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo){
			
			printf("\nDigite a nova Descriçao: ");
            fflush(stdin);
            fgets(cadastro[i].acoes, 100, stdin);
			
			printf("\nCadastro alterado com sucesso!\n");
            
            system("pause");
            
        }}
			break;
			
		case 5:
			
			system("CLS");
			
				for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo){
        	
			printf("\nDigite o novo Codigo da Escola: ");
            scanf("%i", &cadastro[prox].codigoescola);

			int existe = 0;

				for(int i = 0; i < prox; i++){
    			if(cadastro[i].codigoescola, cadastro[prox].codigoescola){
       			 existe = 1;
  					 }
							}
		
				if(existe == 0){
					
  			    do{
  			    system ("CLS");
  			    printf("\nEssa Escola Não foi Cadastrada! Deseja Cadastrar essa Escola? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_escola();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{
					
				printf("\nCadastro alterado com sucesso!\n");
            
            	system("pause");
            }}}
			break;
			
		case 6:
			
			system("CLS");
			
				for(int i = 0; i < prox; i++){

        if(cadastro[i].codigoacao == codigo){
			
			printf("\nDigite o novo Codigo do Profissional: ");
            scanf("%i", &cadastro[prox].codigoprofissional);
			
				int existe = 0;

				for(int i = 0; i < prox; i++){
    			if(cadastro[i].codigoprofissional, cadastro[prox].codigoprofissional){
       			 existe = 1;
  					 }
							}
				
				if(existe==0){
				do{
  			    system ("CLS");
  			    printf("\nEsse Profissional Não foi Cadastrado! Deseja Cadastrar esse Profissional? [1] Sim [2] Não\n");
  			    scanf("%i", &opcao);
  			    
				switch(opcao){
					case 1:
						cadastrar_profissional();
						break;
					case 2:
						system("pause");
						break;
					default:
						printf("Escolha Invalida");
            			sleep(1);
						break;
				}
  			   		 }while(opcao < 1 || opcao > 2);
  			   		 
				}else{ 
				
				printf("\nCadastro alterado com sucesso!\n");
            
            	system("pause");
		}}}
			break;
			
		case 7:
			
			return;
			
			break;
			
		default:
				
		printf("Opção Invalida!");	
		sleep(1);
			break;
	}

}while(opcao < 1 || opcao > 7);
    system("pause");	
}}
    if(encontrar == 0){

        printf("\nCadastro Não Localizado.\n\n");
		
		system("pause");
    }
}

void AlterarCadastro(){
	
	do{
	system("CLS");
	printf("Você Deseja: [1] Mudar o Status da Ação ou [2] Mudar Informações da Ação ou [3] Para Voltar\n");
	scanf("%i", &opcao);
	
	switch(opcao){
		case 1:
			status_acao();
			break;
		case 2:
			informacoes_acao();
			break;
		case 3:
			return;
			break;
		default:
			printf("Opção Invalida!");
			sleep(1);
			break;	
	}

}
	while(opcao < 1 || opcao > 3);
}
void remover_escola(){
	int codigo;
    int encontrar = 0;

    system("CLS");

    printf("REMOVER CADASTRO\n");

    printf("Digite o Codigo do Cadastro da Escola que Deseja Remover: ");
    scanf("%i", &codigo);

    for (int i = 0; i < prox; i++) {

        if (cadastro[i].codigoescola == codigo) {

            cadastro[i] = cadastro[prox - 1];
			prox--;

            encontrar = 1;

            printf("\nCadastro removido.\n");

            break;
        }
    }

    if (encontrar == 0) {

        printf("\nCadastro Não Localizado.\n");
    }
    system("pause");
}
void remover_acao(){
	int codigo;
    int encontrar = 0;

    system("CLS");

    printf("REMOVER CADASTRO\n");

    printf("Digite o Codigo do Cadastro da Ação que Deseja Remover: ");
    scanf("%i", &codigo);

    for (int i = 0; i < prox; i++) {

        if (cadastro[i].codigoacao == codigo) {

            cadastro[i] = cadastro[prox - 1];

            prox--;

            encontrar = 1;

            printf("\nCadastro removido.\n");

            break;
        }
    }

    if (encontrar == 0) {

        printf("\nCadastro nao localizado.\n");

    }
system("pause");
}
void remover_data(){
	int codigo;	
    int encontrar = 0;

    system("CLS");

    printf("REMOVER CADASTRO\n");

    printf("Digite a Data que Deseja Remover: ");
    scanf("%i", &codigo);

    for (int i = 0; i < prox; i++) {

        if (cadastro[i].datas == codigo) {
			encontrar = 1;
			if(cadastro[i].dataacao == 1){
				
				printf("\nEssa data pertence a uma ação! Remova a Ação Correspondente\n");
				
				system("pause");
                
			}else{
			
            cadastro[i] = cadastro[prox - 1];
			prox--;

            printf("\nCadastro removido.\n");

            break;
        }
    }

    if (encontrar == 0) {

        printf("\nCadastro Não Localizado.\n");

    }
system("pause");
}
}
void remover_profissional(){
	int codigo;
    int encontrar = 0;

    system("CLS");

    printf("REMOVER CADASTRO\n");

    printf("Digite o Codigo do Cadastro do Profissional que Deseja Remover: ");
    scanf("%i", &codigo);

    for (int i = 0; i < prox; i++) {

        if (cadastro[i].codigoprofissional == codigo) {

            cadastro[i] = cadastro[prox - 1];
			prox--;

            encontrar = 1;

            printf("\nCadastro removido.\n");

            break;
        }
    }

    if (encontrar == 0) {

        printf("\nCadastro nao localizado.\n");

    }
system("pause");	
}
void RemoverCadastro(){
		do{
	system("CLS");
	printf("Você Deseja Remover o Cadastro de: \n [1] Ação \n [2] Escola \n [3] Profissional \n [4] Data Ocupada \n [5] Sair\n");
	scanf("%i", &opcao);
	
	switch(opcao){
		case 1:
			remover_acao();
			break;
		case 2:
			remover_escola();
			break;
		case 3:
			remover_profissional();
			break;
		case 4:
			remover_data();
			break;
		case 5:
			return;
			break;
		default:
			printf("Opção Invalida!");
			sleep(1);
			break;	
	}

}
	while(opcao < 1 || opcao > 5);
    
}
void SairSistema(){
	printf("\nSaindo do sistema.\n\n");
	sair = true;
}

main (){
	setlocale(LC_ALL, "Portuguese");
	
	while (sair == false){
		system("CLS");
		
		menu();
		scanf("%i", &opcao);
		switch (opcao){
			case 1:
				cadastrar();
				break;
			case 2:
				consultar();
				break;
			case 3:
				ListarDatasOcupadas();
				break;
			case 4:
				GerarRelatorios();
				break;
			case 5:
				AlterarCadastro();
				break;
			case 6:
				RemoverCadastro();
				break;
			case 7:
				SairSistema();
				break;	
			default:
				printf("\nOpção Invalida!");
				sleep(1);
				break;													
		}	
	}
	return 0;
	}

