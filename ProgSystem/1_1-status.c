/*
 * Auteur(s):
 *
 * Cet programme refait ce que fait la commande "ls". Il donne des
 * informnations sur les caracteristiques de fichiers dont le nom est passe
 * en parametre.
 *
 * Utilisation de la primitive stat(2) et de la fonction getpwuid(3).
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

/* Petite fonction qui se charge d'envoyer les messages d'erreur
   et qui ensuite "suicide" le processus. */

void erreur_grave(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

/* Fonction principale (fournie avec erreur(s?)) */

int main(int argc, char **argv) {
  struct stat status, *buffer;
  int r;
// it seems there is something we must do before using pointer
  r = stat(argv[1],&status);// change from buffer to &status
  buffer=&status;
  if (r < 0)
    erreur_grave("Stat");

  printf("Fichier %s:  mode: %X  Taille: %ld  Proprietaire: %d\n",
	argv[1], buffer->st_mode, buffer->st_size, buffer->st_uid);


  exit(EXIT_SUCCESS);
}
//If you want to use a *buffer than you must do XXX* one = malloc(sizeof(*one)) first to dinamically assign the place
//example: http://stackoverflow.com/questions/12958931/c-warning-x-may-be-used-uninitialized-in-this-function