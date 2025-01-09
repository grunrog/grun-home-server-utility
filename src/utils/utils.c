#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "utils.h"

#define CONFIG_DIR "config/"


// Renvoie le dossier associé à file_type
char *get_file_dir(enum File_Type file_type) {
    char *dir;

    switch (file_type) {
            case CONFIG:
                dir = CONFIG_DIR;
                break;
            default:
                perror("Erreur : switch create_dir\n");
                exit(1);
    }
    return dir;
}

// Crée le dossier associé à file_type s'il n'existe pas
void create_dir(enum File_Type file_type) {
    struct stat dir_stat;
    char *dir = get_file_dir(file_type);
    if (stat(dir, &dir_stat) != 0)
            if (mkdir(dir, 0755)) { // 0755 : Owner -> Read & Write, Group -> Read only, Others -> Read only
                perror("Erreur : mkdir\n");
                exit(2);
            }
}

FILE *create_file(char *file_name, bool overwrite_file, enum File_Type file_type) {
    FILE *file;
    char *file_dir = get_file_dir(file_type);
    char file_path[strlen(file_dir) + strlen(file_name)];
    char *fopen_modes;

    strcpy(file_path, file_dir);
    strcat(file_path, file_name);
    create_dir(file_type);

    if (overwrite_file)
        fopen_modes = "w";
    else
        fopen_modes = "a";
        
    if ((file = fopen(file_path, fopen_modes)) == NULL) {
        fprintf(stderr, "Erreur : fopen\n");
        exit(3);
    }

    return file;
}

FILE *open_file_read(char * file_name, enum File_Type file_type) {
    FILE *file;
    char *file_dir = get_file_dir(file_type);
    char file_path[strlen(file_dir) + strlen(file_name)];

    strcpy(file_path, file_dir);
    strcat(file_path, file_name);
    create_dir(file_type);

    file = fopen(file_path, "r");

    return file;   
}

void close_file(FILE *file, int exit_value) {
    if (fclose(file) != 0) {
        perror("Erreur : close_file -> fclose()\n");
        exit(exit_value);
    }
}
