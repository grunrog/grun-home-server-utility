#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "server-utils.h"


int ping_server(char *server_ip) {
    char ping_command[46];

    #ifdef _WIN32
        strcpy(ping_command, "ping -n 1 -w 1000 ");
        strcat(ping_command, server_ip);
        strcat(ping_command, " > nul");
    #else
        strcpy(ping_command, "ping -c 1 -W 1 ");
        strcat(ping_command, server_ip);
        strcat(ping_command, " > /dev/null 2>&1");
    #endif

    return (system(ping_command) == 0);
}

void start_server(char *server_mac, char* server_ip) {
    if (ping_server(server_ip)) {
        printf("Le serveur est déjà allumé.\n");
        return;
    }

    printf("Allumage du serveur...\n");

    // TODO : compatibilité Windows
    char wol_command[45] = "wakeonlan -i 192.168.1.255";
    strcpy(wol_command, "wakeonlan -i 192.168.1.255");
    strcat(wol_command, server_mac);

    system(wol_command);

    while (!ping_server(server_ip)) {
         // Attente que le serveur soit allumé.
         // TODO : Afficher chargement, erreur si trop long ?
    }

    printf("Serveur allumé avec succès.\n");
}
