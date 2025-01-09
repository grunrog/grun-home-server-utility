#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config-utils.h"
#include "server-utils.h"


/* Retourne la clé du fichier de configuration associée à Config_Type */
char *get_config_type_key(enum Config_Type config_type) {
    switch (config_type) {
        case CFG_SERVER_NAME:
            return "SERVER_NAME=";
        case CFG_SERVER_MAC:
            return "SERVER_MAC=";
        case CFG_SERVER_IP:
            return "SERVER_IP=";
        default:
            return NULL;
    }
}

/* Récupère la valeur de la configuration depuis le fichier de configuration.
   Retourne -1 si elle n'existe pas ou que le fichier de configuration est incorrect. */
int get_value_from_config_file(char *config, enum Config_Type config_type) {
    FILE *config_file;
    char buffer[50];
    char *config_tmp;

    if ((config_file = fopen("config/ghsu.conf", "r")) == NULL)
        return -1;

    char *config_key = get_config_type_key(config_type);

    // On lit dans le fichier de configuration
    while (fgets(buffer, sizeof(buffer), config_file) != NULL
                && (config_tmp = strstr(buffer, config_key)) == NULL);

    // Si la clé n'existe pas, set_config s'en chargera.
    if (config_tmp == NULL) {
        if (fclose(config_file) != 0) {
            perror("Erreur : load_config -> fclose()\n");
            exit(1);
        }
        return -1;
    }

    config_tmp += strlen(config_key);
    config_tmp[strcspn(config_tmp, "\r\n")] = '\0';
    strcpy(config, config_tmp);

    if (fclose(config_file) != 0) {
        perror("Erreur : load_config -> fclose()\n");
        exit(2);
    }

    return 0;
}

void load_config(struct structConfig *config) {
    // TODO : return -? si des configurations manquent
    get_value_from_config_file(config->cfg_server_name, CFG_SERVER_NAME);
    get_value_from_config_file(config->cfg_server_mac, CFG_SERVER_MAC);
    get_value_from_config_file(config->cfg_server_ip, CFG_SERVER_IP);
}
