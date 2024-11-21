#include <stdio.h>
#include <string.h>
#include <conio.h> //para o getch no final do programa

int cadastroLivros();
int excluirLivros();
int solicitarEmprestimo();
int pesquisarLivro();
int gerarRelatorio();

typedef struct
{
    char nome[100];
    int anoPublicacao;
    int edicao;
    int reservado; //1 ou 0, para caso estiver reservado ou não, respectivamente
    int emprestado; //1 ou 0, para caso estiver emprestado ou não, respectivamente
    
}livro;


int main()
{
    FILE *ptrArq; //variavel ponteiro para o arquivo
    ptrArq = fopen("livros-cadastrados.txt", "a"); //abre o arquivo, o "a" é para gravação de dados ao final do arquivo

    int esc;
    int *ptrFunc; //ponteiro de função para a escolha

    if(ptrArq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    char titulo[] = "Harry Potter";
    fprintf(ptrArq, "Título: %s\n", titulo); 
    fclose(ptrArq);
    //teste do arquivo

    while(esc !=6)
    {
        printf("Escolha uma opção: \n 1. Cadastro de livro \n 2. Exclusao de livro \n 3. Pesquisar livro \n 4. Solicitar emprestimo \n 5. Gerar relatorio \n 6. Fechar programa\n");
        scanf(" %d", &esc);
        /* switch (esc)
        {
        case 1:
            cadastroLivros();
            break;
        case 2:
            excluirLivros();
            break;
        case 3:
            pesquisarLivro();
            break;
        case 4:
            solicitarEmprestimo();
            break;
        case 5:
            gerarRelatorio();
            break;
        case 6:
            printf("Fim do programa");
            break;
        
        default:
            printf("Digite uma opção válida");
            system("cls");
            break;
        } */
        if(esc==1) ptrFunc = cadastroLivros();
        else if(esc==2) ptrFunc = excluirLivros();
        else if(esc==3) ptrFunc = pesquisarLivro();
        else if(esc==4) ptrFunc = solicitarEmprestimo();
        else if(esc==5) ptrFunc = gerarRelatorio();
        else if(esc==6) {printf("Fim do programa");}
        ptrFunc;
        
    }
    
    
    
    getch(); //faz com que o programa aguarde alguma tecla para fechar
}

int cadastroLivros()
{
    // usar ao inves do scanf: fgets(variavel, sizeof(variavel), stdin); para não dar erro no cadastro
    
    return 0;
}

int excluirLivros()
{
    
    return 0;
}

int pesquisarLivro()
{
    
    return 0;
}

int solicitarEmprestimo()
{
    
    return 0;
}

int gerarRelatorio()
{
    
    return 0;
}
