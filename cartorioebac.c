#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaÃ§o em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string
int registro() //Funcao responsavel por cadastrar os usuarios no sistema
{
	//Inicio das variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variaveis/string
    printf("Digite o CPF a ser cadastrado: "); //Coletando informacao do usuario
    scanf("%s", cpf); //%s refere se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever
    fprintf(file,cpf); //Salva o arquivo da variavel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s" ,nome);
    
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
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}
    

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a alocacao de texto por regiao
	
	//Inicio das variaveis string
	char cpf[40];
	char conteudo[200];
	//Final da ciacao de variaveis string
	
	printf("Digite o CPF a ser consultado: "); // Consultando informaçoes para consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao lacalizado!.\n"); //Aviso que o cpf nao consta no arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas sao as informacoes do usuario: ");// Mostrando informacoes do usuario
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: "); //Pedindo ao usuario qual usuario quer deeletar
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!\n");//Aviso que o cpf nao consta no arquivo
		system("pause");
	}
	
}


int main()
{
    int opcao=0; //Definindo variavel
    int laco=1;
	
    for(laco=1;laco=1;)
	{


	setlocale(LC_ALL, "Portuguese"); //Definindo a alocacao de texto por regiao
	
	system("cls");
    
    printf("### cartorio da EBAC ###\n\n"); //inicio do menu
    printf("Escolha a operacao desejada no menu:\n\n");
    printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n\n");
    printf("opcao:"); //Fim do menu
    
    scanf("%d", &opcao); //armazenamento a escolha do usuario
    
    system("cls"); //Responsavel por limpar a tela
    
    switch(opcao)//Inicio da selecao do menu
    {
    	case 1:
        registro(); //Chamada de funcoes
    	break;
    	
    	case 2:
        consulta();
    	break;
    	
    	case 3:
        deletar();
    	break;
    	
    	default:
    	printf("Essa opcao nao esta disponivel!\n"); //Fim da selecao
    	system("pause");
    	break;
	}
}
}
