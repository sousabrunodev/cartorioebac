#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocação de tesxto por região
#include <string.h> //biblioteca responsável por cuidar das strings 

int registro()//função responsável por cadastrar os usuários no sistemo
{
	//inicio da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string

    printf("digite o cpf a ser cadastrado: ");//coletando infermação do usuário
    scanf("%s", cpf);//%s referese a string
    
    strcpy(arquivo, cpf);//responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file= fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
    fprintf(file, cpf);//salvo o valor da variavel
    fclose(file);//fecho o arquivo
    
    file= fopen(arquivo, "a");//cria o arquivo e o "a" significa atualizar
    fprintf(file, ",");//salvo o valor da variável 
    fclose(file);//fecho o arquivo
    
    printf("digite o nome a ser cadastrado: ");//coletando informações do usuário
    scanf("%s",nome);
    
    file= fopen(arquivo, "a");//cria o arquivo
    fprintf(file,nome);//salva o valor da varioavel
    fclose(file);//fecha o arquivo
    
    file= fopen(arquivo, "a");//cria o arquivo
    fprintf(file, ",");//salva o valor da variável
    fclose(file);//fecha o arquivo
    
    printf("digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
    scanf("%s",sobrenome);//%s referese ao string
    
    file= fopen(arquivo, "a");//cria o arquivo e "a" significa atualizar
    fprintf(file,sobrenome);//salva valor variável
    fclose(file);//fecha o arquivo
    
    file= fopen(arquivo, "a");//cria o arquivo e "a" significa atualizar
    fprintf(file, ",");//salva valor variável
    fclose(file);//fecha o arquivo
    
    printf("digite o cargo a ser cadastrado: ");//coletando informação do usuário
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
   	printf("não foi possivel abrir o arquivo, não localizado!\n");
   }
   
   while(fgets(conteudo, 200, file) !=NULL)
   {
   	printf("\nessas são as informações do usúario: ");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
    system("pause");
}
int deletar()
{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usúario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usúario não se encontra no sitema! \n");
		system ("pause");
	}
	
	remove(cpf);
	if(file !=NULL)
	
	printf("\nusuário deletado com sucesso.\n\n ");
	system("pause");
	
	

   
}
int main()
{
	int opcao=0;//definindo variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;) 
	{
	
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	system("cls");
	
	printf("### cartório da Ebac ###\n\n");//inicío do menu
	printf("escolha a opção desejada do menu:\n\n");
	printf("\t1-Registrar nomes\n");
	printf("\t2-Consultar nomes\n");
	printf("\t3-Deletar nomes\n\n");
	printf("opção:");//final do menu

    scanf("%d", &opcao);//armazenando a escolha do usuario
    
    system("cls");//responsável por limpar a tela
    
    switch(opcao)
    {       
	        case 1:
    	    registro();//chamada de funções 
	        break;
	        
	        case 2:
	        consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default:
		    printf("essa opção não está disponivel!\n");
			system("pause"); 
			break;
		    	
	        	
	}
    
   
}
}
