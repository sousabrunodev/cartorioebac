#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��o de tesxto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings 

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistemo
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string

    printf("digite o cpf a ser cadastrado: ");//coletando inferma��o do usu�rio
    scanf("%s", cpf);//%s referese a string
    
    strcpy(arquivo, cpf);//responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file= fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
    fprintf(file, cpf);//salvo o valor da variavel
    fclose(file);//fecho o arquivo
    
    file= fopen(arquivo, "a");//cria o arquivo e o "a" significa atualizar
    fprintf(file, ",");//salvo o valor da vari�vel 
    fclose(file);//fecho o arquivo
    
    printf("digite o nome a ser cadastrado: ");//coletando informa��es do usu�rio
    scanf("%s",nome);
    
    file= fopen(arquivo, "a");//cria o arquivo
    fprintf(file,nome);//salva o valor da varioavel
    fclose(file);//fecha o arquivo
    
    file= fopen(arquivo, "a");//cria o arquivo
    fprintf(file, ",");//salva o valor da vari�vel
    fclose(file);//fecha o arquivo
    
    printf("digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
    scanf("%s",sobrenome);//%s referese ao string
    
    file= fopen(arquivo, "a");//cria o arquivo e "a" significa atualizar
    fprintf(file,sobrenome);//salva valor vari�vel
    fclose(file);//fecha o arquivo
    
    file= fopen(arquivo, "a");//cria o arquivo e "a" significa atualizar
    fprintf(file, ",");//salva valor vari�vel
    fclose(file);//fecha o arquivo
    
    printf("digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
    scanf("%s", cargo);
    
    file= fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    system("pause");
    
    
}
int consulta()
{
   setlocale(LC_ALL, "portuguese");//definindo a linguagem
		
   char cpf[40];
   char conteudo[200];
   
   printf("digite o CPF a ser consultado: ");
   scanf("%s", cpf);
   
   FILE *file;
   file= fopen(cpf,"r");
   if(file== NULL)
   {
   	printf("n�o foi possivel abrir o arquivo, n�o localizado!\n");
   }
   
   while(fgets(conteudo, 200, file) !=NULL)
   {
   	printf("\nessas s�o as informa��es do us�ario: ");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
    system("pause");
}
int deletar()
{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do us�ario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o us�ario n�o se encontra no sitema! \n");
		system ("pause");
	}
	
	remove(cpf);
	if(file !=NULL)
	
	printf("\nusu�rio deletado com sucesso.\n\n ");
	system("pause");
	
	

   
}
int main()
{
	int opcao=0;//definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;) 
	{
	
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	system("cls");
	
	printf("### cart�rio da Ebac ###\n\n");//inic�o do menu
	printf("escolha a op��o desejada do menu:\n\n");
	printf("\t1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n\n");
	printf("op��o:");//final do menu

    scanf("%d", &opcao);//armazenando a escolha do usuario
    
    system("cls");//respons�vel por limpar a tela
    
    switch(opcao)
    {       
	        case 1:
    	    registro();//chamada de fun��es 
	        break;
	        
	        case 2:
	        consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default:
		    printf("essa op��o n�o est� disponivel!\n");
			system("pause"); 
			break;
		    	
	        	
	}
    
   
}
}
