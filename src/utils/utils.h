#ifndef UTILS_H
#define UTILS_H

#define MAC_LENGTH 18
#define IP_LENGTH 14

/* Retourne les adresses MAC et IP du serveur dans le fichier de configuration.
   Retourne -1 si le fichier n'existe pas ou qu'il est incorrect (set_config() se chargera de le recréer). */
int load_config(char *server_mac, char *server_ip);

/* Affiche si le serveur est allumé ou éteint */
void print_server_status(char *server_ip);

#endif
