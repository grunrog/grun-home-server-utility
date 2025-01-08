#include <stdio.h>

#include "utils/utils.h"


int main() {
    char server_mac[MAC_LENGTH];
    char server_ip[IP_LENGTH];

    load_config(server_mac, server_ip);

    printf("MAC = %s\n", server_mac); // tmp
    printf("IP = %s\n", server_ip); // tmp

    print_server_status(server_ip);

    return 0;
}
