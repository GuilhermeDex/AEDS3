#include <stdio.h>
#include <stdlib.h>

#include "../include/logic.h"
#include "../include/input.h"
#include "../include/timer.h"

int main(int argc, char *argv[]) {
    char *kit_file = NULL;
    char *config_file = NULL;
    KitExplosivo *kit = NULL;
    Bomba *config = NULL;
    int tamanhokit, tamanhoconfig;

    start_timer();
    processar_entrada(argc, argv, &kit_file, &config_file);

    ler_kit(kit_file, &kit, &tamanhokit);
    ler_config(config_file, &config, &tamanhoconfig);
    

    verificar_correspondencia(kit, tamanhokit, config, tamanhoconfig);
    validar_configuracao(config, tamanhoconfig);

    stop_timer();
    print_timer();

    free(kit);
    free(config);

    return 0;
}
