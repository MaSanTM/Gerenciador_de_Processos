#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define PID_START 99
#define TERMINO 0
#define MAX_CHAR 20
#define MAX_PROC 7

int vetor = 0;
int num_processos = 0;
int removidos = 0;
int pid_usados[80][80];
int tamanho_max = 0;
char aux;

struct PROCESSOS{

    char nome[80];
    int pid;
    int cpu;
};

struct PROCESSOS processos[10];

void manipular_tabela_processos() {

    int poweroffTabela = 1;
    int manipularSelect = 0;
    int pid_num = 1;

    while (poweroffTabela == 1) {

        system("cls");
        printf("---------- Manipular Tabela de Processos ----------\n\n");

        printf("1. Inserir Processos (Nome, Ciclos de CPU)\n2. Alterar Processos\n3. Remover Processos\n4. Listar Tabela\n5. Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &manipularSelect);

        if (manipularSelect == 1) {

            num_processos++;

            if (vetor >= MAX_PROC) {

                printf("\n\nQuanditade de processos excedida !!!\n\n");

                printf("\n\nAperte ENTER para voltar...");
                getchar(); scanf("%c", &aux);

                return manipular_tabela_processos();
            }

            system("cls");

            printf("---------- Insira os dados do processo a ser criado ----------\n\n");

            printf("Nome do processo: ");
            scanf("%s", &processos[vetor].nome);

            tamanho_max = strlen(processos[vetor].nome);

            if (tamanho_max > MAX_CHAR) {

                printf("\n\nTamanho do Nome excedido, no maximo 20 caracteres !!!\n\n");

                printf("\n\nAperte ENTER para voltar...");
                getchar(); scanf("%c", &aux);

                return manipular_tabela_processos();
            }

            processos[vetor].pid = PID_START + num_processos;

            printf("\nQuantidade de Ciclos da CPU: ");
            scanf("%i", &processos[vetor].cpu);

            vetor++;
        }
        else if (manipularSelect == 2) {

            int pid;
            int i = 0;
            int j = 0;
            char novo_nome[80];
            int novo_cpu = 0;
            int opcao = 0;

            system("cls");

            printf("Informe o PID do processo a ser alterado: ");
            scanf("%i", &pid);

            for (i = 0; i < MAX_PROC; i++) {

                if (processos[i].pid == pid) {

                    printf("Tamanho maximo de caracteres no nome é de: 20.");
                    
                    printf("\n\nNome: %s  PID: %i  CPU: %i\n\n", processos[i].nome, processos[i].pid, processos[i].cpu);

                    printf("O que deseja alterar:\n1. Nome\n2. CPU\n\n");

                    printf("Escolha uma opcao: ");
                    scanf("%i", &opcao);

                    if (opcao == 1) {

                        printf("\n\nNovo nome: ");
                        scanf("%s", &novo_nome);
                        fflush(stdin);

                        strcpy(processos[i].nome, novo_nome);

                        tamanho_max = strlen(processos[i].nome);

                        if (tamanho_max > MAX_CHAR) {

                            printf("\n\nTamanho do Nome excedido, no maximo 20 caracteres !!!\n\n");

                            printf("\n\nAperte ENTER para voltar...");
                            getchar(); scanf("%c", &aux);

                            return manipular_tabela_processos();
                        }
                    }
                    else if (opcao == 2) {
                        printf("\n\nNovo ciclo de CPU: ");
                        scanf("%i", &novo_cpu);

                        processos[i].cpu = novo_cpu;
                    }
                }
            }
        }
        else if (manipularSelect == 3) {

            int pid;
            int i = 0;
            int j = 0;

            system("cls");

            printf("Informe o PID do processo a ser removido: ");
            scanf("%i", &pid);

            for (i = 0; i < MAX_PROC; i++) {

                if (processos[i].pid == pid) {

                    pid_usados[removidos][80] = pid;

                    removidos++;

                    for (j = i; j < vetor; j++) {
                  
                        strcpy(processos[j].nome , processos[j + 1].nome);
                        processos[j].pid = processos[j + 1].pid;
                        processos[j].cpu = processos[j + 1].cpu;
                    }

                    vetor--;
                    return manipular_tabela_processos();
                }
            }
        }
        else if (manipularSelect == 4) {

            system("cls");

            int i = 0;

            printf("---------- Processos ----------\n\n");

            for (i = 0; i < vetor; i++) {

                printf("Nome: %s  PID: %i  CPU: %i  \n", processos[i].nome, processos[i].pid, processos[i].cpu);
            }

            printf("\n\nAperte ENTER para voltar...");
            getchar(); scanf("%c", &aux);
        }
        else if (manipularSelect == 5) {

            poweroffTabela = 0;
            system("cls");
            return;
        }
        else {

            printf("\n\nOpcao Invalida !!!\n\n");

            printf("\n\nAperte ENTER para voltar...");            
            getchar(); scanf("%c", &aux);
        }
    }
    return;
}

void executar_simulacao() {

    
}

int main() {

    int poweroff = 1;

    while (poweroff == 1) {

        int menuSelect = 0;

        system("cls");

        printf("---------- Gerenciador da Fila de Prontos ----------\n\n");

        printf("---------- Menu Principal ----------\n\n");

        printf("1. Manipulacao da Tabela de Processos\n2. Executar Simulacao\n3. Copyright\n4. Encerrar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &menuSelect);

        if (menuSelect == 1) {

            manipular_tabela_processos();
        }
        else if (menuSelect == 2) {

            executar_simulacao();
        }
        else if (menuSelect == 3) {

            system("cls");
            printf("Copyright\n\nProjeto01 - Gerenciador de Processos\nCurso de Analise e Desenvolvimento de Sistemas\nProf. Jose Luis Zem\n\n");
            printf("Integrantes\n\nRodrigo Vinicius Ventura de Souza");
            printf("\n\n");
            
            printf("\n\nAperte ENTER para voltar...");            
            getchar(); scanf("%c", &aux);
        }
        else if (menuSelect == 4) {

            printf("\nEncerrando...\n");
            poweroff = 0;
        }
        else {

            printf("\n\nOpcao Invalida !!!\n\n");

            printf("\n\nAperte ENTER para voltar...");
            getchar(); scanf("%c", &aux);
        }
    }
}

