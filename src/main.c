#include <stdio.h>
#include <stdlib.h>

#include "utils/utils.h"
#include "utils/config-utils.h"
#include "utils/server-utils.h"


int main() {
    struct structConfig *config = malloc(sizeof(struct structConfig));

    load_config(config);

    printf("NAME = %s\n", config->cfg_server_name); // tmp
    printf("MAC = %s\n", config->cfg_server_mac); // tmp
    printf("IP = %s\n", config->cfg_server_ip); // tmp

    print_server_status(config->cfg_server_ip);

    free(config);

    return 0;
}
