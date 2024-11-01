#ifndef CONFIG_H
#define CONFIG_H

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

// Funcoes para entrada e saida
void ler_kit(const char *filename, KitExplosivo **kit, int *numero_bomba);
void ler_config(const char *filename, Bomba **config, int *numero_bomba);
void processar_entrada(int arh, char *argv[], char **kit_file, char **config_file);

// Funcoes de validar
int validar_configuracao(Bomba *config, int tamanhoconfig);
int verificar_correspondencia(KitExplosivo *kit, int num_kit, Bomba *config, int num_config);

// Funcoes de tempo
void start_timer();
void stop_timer();
void print_timer();

#endif
