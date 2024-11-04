#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/logic.h"
#include "../include/input.h"

void processar_entrada(int argc, char *argv[], char **kit_file, char **config_file) {
    int opt;

    while ((opt = getopt(argc, argv, "k:c:")) != -1) {
        switch (opt) {
            case 'k':
                *kit_file = optarg;
                break;
            case 'c':
                *config_file = optarg;
                break;
            default:
                fprintf(stderr, "Uso: %s -k kit_file -c config_file\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (!*kit_file || !*config_file) {
        fprintf(stderr, "Erro: Ambos os arquivos (kit e configuracao) devem ser fornecidos.\n");
        exit(EXIT_FAILURE);
    }

}

void ler_kit(const char *filename, KitExplosivo **kit, int *numero_bomba) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo do kit");
        exit(EXIT_FAILURE);
    }

    int i = 0, max_barras = 10;  // inicializa com o total de 10 barras
    *kit = (KitExplosivo *)malloc(max_barras * sizeof(KitExplosivo));

    *numero_bomba = 0; 

    while (fscanf(file, "%d %d %s", &(*kit)[i].quantidade, &(*kit)[i].tam, (*kit)[i].cor) == 3) {
        *numero_bomba += (*kit)[i].quantidade;  // essa linha do codigo funciona para que enquanto eu estiver lendo o arquivo some a quantidade com a quantidade certa e nao por linha
        i++;
        if (i >= max_barras) {          // como iniciamos com 10 barras, caso na configuração tenha mais do que 10, faco um realloc para armazenar de acordo com o necessario e nao mais do que o que se pede
            max_barras *= 2;
            *kit = (KitExplosivo *)realloc(*kit, max_barras * sizeof(KitExplosivo));
        }
    }
    fclose(file);
    printf("Kit lido com sucesso! Numero de explosivos no kit: %d\n", *numero_bomba);
}


void ler_config(const char *filename, Bomba **config, int *numero_bomba) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo de configuracao");
        exit(EXIT_FAILURE);
    }

    int i = 0, max_barras = 10;  // inicializa com o total de 10 barras
    *config = (Bomba *)malloc(max_barras * sizeof(Bomba));

    while (fscanf(file, "%d %d %d %d %d %s", &(*config)[i].x_inicial, &(*config)[i].y_inicial, &(*config)[i].x_final, &(*config)[i].y_final, &(*config)[i].tam, (*config)[i].cor) == 6) {
        i++;
        if (i >= max_barras) {
            max_barras *= 2;
            *config = (Bomba *)realloc(*config, max_barras * sizeof(Bomba)); // mesma ideia da funcao "ler kit"
        }
    }

    *numero_bomba = i;
    fclose(file);
    printf("Configuracao lida com sucesso! Numero de explosivos configurados: %d\n", *numero_bomba);
}
