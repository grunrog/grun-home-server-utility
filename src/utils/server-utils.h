#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

/* Tente de ping le serveur à l'adresse server_ip.
   Retourne 1 si le ping à réussit, 0 sinon. */
int ping_server(char *server_ip);

/* Affiche si le serveur est allumé ou éteint */
void print_server_status(char *server_ip);

/* WIP - Tente de démarrer le serveur s'il est inaccessible.
   TODO : return ? */
void start_server();

#endif
