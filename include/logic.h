#ifndef LOGIC_H
#define LOGIC_H

typedef struct {
    char cor[3];
    int tam;
    int x_inicial, y_inicial;
    int x_final, y_final;
} Bomba;

typedef struct {
    char cor[3];
    int tam;
    int quantidade;
} KitExplosivo;

// Funcoes de validar
int adjacencia(Bomba b1, Bomba b2);
int dentro_dos_limites(Bomba b);
int calcular_tamanho(Bomba b);
int validar_configuracao(Bomba *config, int tamanhoconfig);
int verificar_correspondencia(KitExplosivo *kit, int num_kit, Bomba *config, int num_config);


#endif
