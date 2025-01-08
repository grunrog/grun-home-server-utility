#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "server-utils.h"

#define CONFIG_MAC_LENGTH 29
#define CONFIG_IP_LENGTH 24

#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

/* Ferme le fichier file.
   Fait exit(exit_value) si problème lors de fclose(). */
void close_file(FILE *file, int exit_value) {
    if (fclose(file) != 0) {
        perror("Erreur : load_config -> fclose()\n");
        exit(exit_value);
    }
}

/* Retourne une adresse du serveur depuis le fichier de configuration.
   Retourne NULL si elle n'existe pas ou que le fichier de configuration est incorrect. */
int get_address_from_config(FILE *file, char *server_address, size_t address_length) {
    char buffer[50];
    char *config;

    if ((fgets(buffer, sizeof(buffer), file) == NULL)
            || ((config = strchr(buffer, '=')) == NULL))
        return -1;

    config++;
    config[strcspn(config, "\r\n")] = '\0';

    if (strlen(config) != address_length - 1)
        return -1;

    strcpy(server_address, config);

    return 0;
}


int load_config(char *server_mac, char *server_ip) {
    FILE *config_file;

    if ((config_file = fopen("config/ghsu.conf", "r")) == NULL) {
        return -1;
    }

    // addresse MAC
    if (get_address_from_config(config_file, server_mac, MAC_LENGTH) != 0) {
        close_file(config_file, 1);
        return -1;
    }

    // addresse IP
    if (get_address_from_config(config_file, server_ip, IP_LENGTH) != 0) {
        close_file(config_file, 2);
        return -1;
    }

    close_file(config_file, 3);

    return 0;
}

void print_server_status(char *server_ip) {
    printf("Statut du serveur : ");

    if (ping_server(server_ip))
        printf("%s.\n", COLOR_GREEN "allumé" COLOR_RESET);
    else
        printf("%s.\n", COLOR_RED "éteint" COLOR_RESET);
}
