#ifndef __TBA_H__
#define __TBA_H__

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 0xFF
#define CLEAR "clear"			//remplacer par cls pour les utilisateur de windows


unsigned char CompterLettre(const char* _tab);
unsigned char RemplacerLettre(const char* _tab, char* _mots_cacher, char _lettre);
unsigned char Gagner(char* _mots_cacher);
void AfficherPendu(unsigned char _pendu);
void AfficherMot(const char* _tab);
void RemplireMotCacher(const char* _tab, char* _mots_cacher);

#endif
