#ifndef INPUT_H
#define INPUT_H
#include "logic.h"

// Funcoes para entrada e saida
void processar_entrada(int arh, char *argv[], char **kit_file, char **config_file);
void ler_kit(const char *filename, KitExplosivo **kit, int *numero_bomba);
void ler_config(const char *filename, Bomba **config, int *numero_bomba);

#endif