#ifndef CONFIG_UTILS_H
#define CONFIG_UTILS_H

#define CONFIG_FILE_NAME "ghsu.conf"
#define NB_CONFIGS 3
#define MAX_CONFIG_LENGTH 50
#define MAC_LENGTH 18
#define IP_LENGTH 14

enum Config_Type {
   CFG_SERVER_NAME,
   CFG_SERVER_MAC,
   CFG_SERVER_IP,
   CFG_NB_CONFIGS = NB_CONFIGS
};

struct structConfig {
   char cfg_server_name[MAX_CONFIG_LENGTH];
   char cfg_server_mac[MAC_LENGTH];
   char cfg_server_ip[IP_LENGTH];
};

/* Récupère les adresses MAC et IP du serveur dans le fichier de configuration.*/
void load_config(struct structConfig *config);

#endif
