#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdbool.h>

enum File_Type {
    CONFIG
};

// Ouvre un fichier dans le dossier associé à file_type, et le crée s'il n'existe pas
FILE *create_file(char *file_name, bool overwrite_file, enum File_Type file_type);

// Ouvre un fichier en lecture dans le dossier associé à file_type
FILE *open_file_read(char * file_name, enum File_Type file_type);

// Ferme un fichier
void close_file(FILE *file, int exit_value);

#endif
