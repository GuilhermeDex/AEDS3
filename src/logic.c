#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

int adjacencia(Bomba b1, Bomba b2) {
    if (b1.x_inicial == b2.x_inicial) {
        if ((b1.y_final + 1 == b2.y_inicial) || (b2.y_final + 1 == b1.y_inicial)) {
            return 1;  // quando temos adjacencia na mesma linha
        }
    }

    if (b1.y_inicial == b2.y_inicial) {
        if ((b1.x_final + 1 == b2.x_inicial) || (b2.x_final + 1 == b1.x_inicial)) {
            return 1;  // quando temos adjacencia na mesma coluna
        }
    }

    return 0;
}

// funcao para verificar se a configuracao esta dentro dos limites de 6x6
int dentro_dos_limites(Bomba b) { 
    return (b.x_inicial >= 1 && b.x_inicial <= 6 && b.y_inicial >= 1 && b.y_inicial <= 6 &&
            b.x_final >= 1 && b.x_final <= 6 && b.y_final >= 1 && b.y_final <= 6);
}

// funcao para calcular o tamanho e verificar para debugar o codigo qual a area que cada kit ta ocupando
int calcular_tamanho(Bomba b) {
    int largura = abs(b.x_final - b.x_inicial) + 1;
    int altura = abs(b.y_final - b.y_inicial) + 1;
    return largura * altura; 
}

// funcao para verificar a configuracao das bombas
int validar_configuracao(Bomba *config, int tamanhoconfig) {
    int area_total = 0;

    for (int i = 0; i < tamanhoconfig; i++) {
        if (!dentro_dos_limites(config[i])) {
            printf("Explosivo %d%s esta fora dos limites da caixa! Coordenadas: (%d,%d) -> (%d,%d)\n",
                   config[i].tam, config[i].cor, config[i].x_inicial, config[i].y_inicial, config[i].x_final, config[i].y_final);
            printf("Configuracao invalida!\n");
            return 0;
        }

        int area_explosivo = calcular_tamanho(config[i]);
        area_total += area_explosivo;

        // verifica se existem explosivos com a mesma cor adjacentes
        for (int j = i + 1; j < tamanhoconfig; j++) {
            if (strcmp(config[i].cor, config[j].cor) == 0 && adjacencia(config[i], config[j])) {
                printf("Explosivos adjacentes de mesma cor: %d%s e %d%s\n", config[i].tam, config[i].cor, config[j].tam, config[j].cor);
                printf("Configuracao invalida!\n");
                return 0;
            }
        }
    }

    printf("Area total ocupada: %d \n", area_total);
    if (area_total > 36) {
        printf("A configuracao excede a area maxima de 6x6 (36 quadrados). Area ocupada: %d\n", area_total);
        printf("Configuracao invalida!\n");
        return 0;
    }
    printf("Configuracao valida!\n");
    return 1;
}



int verificar_correspondencia(KitExplosivo *kit, int num_kit, Bomba *config, int num_config) {
    int *quantidade_explosivos = (int *)calloc(num_kit, sizeof(int));

    // for para verificar a quantidade dos explosivos do kit
    for (int i = 0; i < num_config; i++) {
        int encontrado = 0;
        for (int j = 0; j < num_kit; j++) {
            if (strcmp(kit[j].cor, config[i].cor) == 0 && kit[j].tam == config[i].tam) {
                quantidade_explosivos[j]++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Erro: explosivo %d%s na configuracao nao existe no kit!\n", config[i].tam, config[i].cor);
            free(quantidade_explosivos);
            printf("Erro: A configuracao nao corresponde ao kit!\n");
            stop_timer();
            print_timer();
            free(kit);
            free(config);
            printf("Erro: configuracao invalida\n");
            exit(1); 
        }
    }

    // comparando para ver se a quantidade de explosivos do kit esta de acordo com a quantidade da configuracao
    for (int j = 0; j < num_kit; j++) {
        if (quantidade_explosivos[j] != kit[j].quantidade) {
            printf("Erro: A quantidade de %d%s esta incorreta. No kit: %d, na configuracao: %d\n",
                   kit[j].tam, kit[j].cor, kit[j].quantidade, quantidade_explosivos[j]);
            free(quantidade_explosivos);
            stop_timer();
            print_timer();
            free(kit);
            free(config);
            printf("Erro: configuração invalida\n");
            exit(1); 
        }
    }

    free(quantidade_explosivos);
    return 1;
}

