#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espa�o de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings
 
 	int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
 	{
 	//in�cio cria��o de vari�veis/string
 	char arquivo[40]; //Vari�vel aue representa caracter tipo texto
 	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//final de cria��o de vari�veis/string
 	
 	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
 	scanf("%s", cpf); //%s refere-se a string
 	
 	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
 	
 	FILE *file; //cria o arquivo
 	file = fopen(arquivo, "w"); //cria o arquivo e "w" significa escrever
 	fprintf(file,cpf); //salvo valor da vari�vel
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //"a" atualiza arquivo j� existente.
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("Digite o nome a ser cadastrado: ");
 	scanf("%s",nome);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,nome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("Digite o sobrenome a ser cadastrado: ");
 	scanf("%s",sobrenome);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,sobrenome);
 	fclose(file);
 	
 	file = fopen(arquivo, "a");
 	fprintf(file,",");
 	fclose(file);
 	
 	printf("Digite o cargo a ser cadastrado: ");
 	scanf("%s",cargo);

 	file = fopen(arquivo, "a");
 	fprintf(file,cargo);
 	fclose(file);
 	
 	system("pause");
	}
  
 	int consulta() //Fun��o respons�vel por consultar usu�rios no sistema.
{	
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //recebendo qual usu�rio vai ser consultado
	scanf("%s",cpf);
	
	FILE  *file;
	file = fopen(cpf, "r"); // "r" significa ler o arquivo
	
	if(file==NULL) //Fun��o utilizada para verificar se uma dada condi��o � verdadeira ou falsa
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //Fun��o � utilizada quando for preciso repetir um codigo ou valida��o v�rias vezes
{
	printf("\nEssas s�o as informa��es do usu�rio");
	printf("%s", conteudo);
	printf("\n\n");
}
	
	system("pause");
	
	
}
 
 	int deletar() //Fun��o respons�vel por deletar usu�rios do sistema.
	{
 		char cpf[40];
 		
 		printf("Digite o CPF a ser deletato: ");
 		scanf("%s",cpf); //comando vai varrer tudo aue o usu�rio digitar e salvar onde for pedido.
 		
 		remove(cpf);
 		
 		FILE *file;
 		file = fopen(cpf,"r");
 		
 		if(file == NULL) ////Fun��o utilizada para verificar se uma dada condi��o � verdadeira ou falsa
 		{
 		printf("Usu�rio deletado com sucesso!\n");
 		system("pause");
 		}
 		
 		else
		{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
			if(file == NULL)
			{
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
			}
		}
	fclose(file);
 	}
 
	int main() //Fun��o respons�vel pelo menu principal do programa.
	{
		int opcao=0; //Definindo varariaveis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;
		
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login de administrador!\n\nDigite a sua senha:");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");
		
		if(comparacao == 0)
		{
		    system ("cls");
			for(laco=1;laco=1;)
			{
			system("cls");
	
    		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf("Escolha op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d",&opcao); //armazenando a escolha do usuario
	
			system("cls"); //respons�vel por limpar a tela
	
				switch(opcao) //inicio da sele��o do menu
				{
				case 1:
				registro(); //chamada de fun��es
    			break;
        
    			case 2:
    			consulta();
				break;
		
				case 3:
				deletar();
				break;
		
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
		
		
				default:
				printf("Essa op��o n�o est� dospon�vel\n");
				system("pause");
				break;
				} //fim da sele��o
			}
		}
		
		else
			printf("Senha incorreta!");
			
}

