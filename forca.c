#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;


int letraexiste(char letra) { //verifica se a letra esta presente na palavra escolhida

    for(int j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }

    return 0;
}

int chuteserrados() { //contador pro numero de erros
    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }

    return erros;
}

int enforcou() { //fim do jogo, usa o numero de erros
    return chuteserrados() >= 5;
}

int ganhou() { //fim do jogo, verifica se acertou a palavra
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}


void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() { //verifica o chute
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
    chute = toupper(chute); //para colocar a letra escolhida em maiúscula no txt

    if(letraexiste(chute)) {
        printf("Voeê acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVoce errou: a palavra NAO tem a letra %c\n\n", chute);
    }

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) { //usada pra encontrar onde a letra é usada
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() { //desenho da forca

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhepalavra(int *escolha) { //escolha do tema de palavra, ja abre o arquivo e retorna a escolha pra main via ponteiro 
    FILE* f;

    int opcao;
    printf("Escolha um tema para o jogo de forca:\n1. Animais\n2. Cores\n3. Paises ou Cidades\n4. Frutas\n5. Profissoes\nDigite o numero da opcao desejada: ");
    

    
    while (opcao>5 || opcao<1) //para escolher o tema
    {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Voca escolheu o tema: Animais\n");
                f = fopen("animais.txt", "r");
                break;
            case 2:
                printf("Voca escolheu o tema: Cores\n");
                f = fopen("cores.txt", "r");
                break;
            case 3:
                printf("Voca escolheu o tema: Paises ou Cidades\n");
                f = fopen("paisescidades.txt", "r");
                break;
            case 4:
                printf("Voca escolheu o tema: Frutas\n");
                f = fopen("frutas.txt", "r");
                break;
            case 5:
                printf("Voca escolheu o tema: Profissoes\n");
                f = fopen("profissoes.txt", "r");
                break;
            default:
                printf("Opcao invalida! Tente novamente: ");
                break;
                
        }
        *escolha = opcao;
    }
    
    if(f == 0) {
        printf("Banco de dados de palavras nao disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}


void adicionapalavra(int opcao) { //caso queira adicionar uma palavra
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);
    quer = toupper(quer); //para colocar a escolha em maiúscula no txt

    if(quer == 'S') {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiusculas: ");
        scanf("%s", &novapalavra);

        FILE* f;
        if(opcao==1){f = fopen("animais.txt", "r+");}
        else if (opcao==2){f = fopen("cores.txt", "r+");}
        else if (opcao==3){f = fopen("paisesecidades.txt", "r+");}
        else if (opcao==4){f = fopen("frutas.txt", "r+");}
        else if (opcao==5){f = fopen("profissoes.txt", "r+");}
        
        
        
        if(f == 0) {
            printf("Banco de dados de palavras nao disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);

    }
}

int main() {
    int opcao; //retorno da escolha de palavra, serve para caso o usuário queira adicionar alguma palavra em algum dos arquivos
    abertura();
    escolhepalavra(&opcao);

    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionapalavra(opcao);
}