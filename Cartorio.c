#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaço de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings
 
 	int registro() //Função responsável por cadastrar os usuários no sistema
 	{
 	//início criação de variáveis/string
 	char arquivo[40]; //Variável aue representa caracter tipo texto
 	char cpf[40];
 	char nome[40];
 	char sobrenome[40];
 	char cargo[40];
 	//final de criação de variáveis/string
 	
 	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
 	scanf("%s", cpf); //%s refere-se a string
 	
 	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
 	
 	FILE *file; //cria o arquivo
 	file = fopen(arquivo, "w"); //cria o arquivo e "w" significa escrever
 	fprintf(file,cpf); //salvo valor da variável
 	fclose(file); //fecha o arquivo
 	
 	file = fopen(arquivo, "a"); //"a" atualiza arquivo já existente.
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
  
 	int consulta() //Função responsável por consultar usuários no sistema.
{	
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //recebendo qual usuário vai ser consultado
	scanf("%s",cpf);
	
	FILE  *file;
	file = fopen(cpf, "r"); // "r" significa ler o arquivo
	
	if(file==NULL) //Função utilizada para verificar se uma dada condição é verdadeira ou falsa
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //Função é utilizada quando for preciso repetir um codigo ou validação várias vezes
{
	printf("\nEssas são as informações do usuário");
	printf("%s", conteudo);
	printf("\n\n");
}
	
	system("pause");
	
	
}
 
 	int deletar() //Função responsável por deletar usuários do sistema.
	{
 		char cpf[40];
 		
 		printf("Digite o CPF a ser deletato: ");
 		scanf("%s",cpf); //comando vai varrer tudo aue o usuário digitar e salvar onde for pedido.
 		
 		remove(cpf);
 		
 		FILE *file;
 		file = fopen(cpf,"r");
 		
 		if(file == NULL) ////Função utilizada para verificar se uma dada condição é verdadeira ou falsa
 		{
 		printf("Usuário deletado com sucesso!\n");
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
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
			}
		}
	fclose(file);
 	}
 
	int main() //Função responsável pelo menu principal do programa.
	{
		int opcao=0; //Definindo varariaveis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;
		
		printf("### Cartório da EBAC ###\n\n");
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
	
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Opção: "); //fim do menu
	
			scanf("%d",&opcao); //armazenando a escolha do usuario
	
			system("cls"); //responsável por limpar a tela
	
				switch(opcao) //inicio da seleção do menu
				{
				case 1:
				registro(); //chamada de funções
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
				printf("Essa opção não está dosponível\n");
				system("pause");
				break;
				} //fim da seleção
			}
		}
		
		else
			printf("Senha incorreta!");
			
}

