#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int main(int argc, char *argv[]) {
    char *kit_file = NULL;
    char *config_file = NULL;
    KitExplosivo *kit = NULL;
    Bomba *config = NULL;
    int tamanhokit, tamanhoconfig;

    processar_entrada(argc, argv, &kit_file, &config_file);

    ler_kit(kit_file, &kit, &tamanhokit);
    ler_config(config_file, &config, &tamanhoconfig);
    
    start_timer();

    verificar_correspondencia(kit, tamanhokit, config, tamanhoconfig);
    validar_configuracao(config, tamanhoconfig);

    stop_timer();
    print_timer();

    free(kit);
    free(config);

    return 0;
}
