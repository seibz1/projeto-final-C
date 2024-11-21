#include <stdio.h>
#include <string.h>
#include <conio.h> //para o getch no final do programa

void cadastroLivros();
void excluirLivros();
void solicitarEmprestimo();
void pesquisarLivro();

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

    if(ptrArq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    char titulo[] = "Harry Potter";
    fprintf(ptrArq, "Título: %s\n", titulo); 
    fclose(ptrArq);
    //teste do arquivo
    
    
    getch(); //faz com que o programa aguarde alguma tecla para fechar
}

void cadastroLivros()
{
    // usar ao inves do scanf: fgets(variavel, sizeof(variavel), stdin); para não dar erro no cadastro
}

void excluirLivros()
{

}

void solicitarEmprestimo()
{

}

void pesquisarLivro()
{

}

void gerarRelatorio()
{

}
