#include <stdio.h>
#include <stdlib.h>
#include "tba.h"

int main(int argc, char const *argv[])
{
	char MotCacher[BUFFER_SIZE] = {0};
	char lettre_saisie;
	unsigned char nombre_lettre = CompterLettre(argv[1]);
	unsigned char score = 0;
	unsigned char score_temp = 0;
	unsigned char tour = 0;
	int pendu = 0;

	RemplireMotCacher(argv[1],MotCacher);
	system(CLEAR);
	do
	{
		if(score_temp == score && tour !=0)pendu++;
		AfficherPendu(pendu);
		score_temp = score;
		printf("\nDans le mot il y à %u lettre(s).\n",CompterLettre(argv[1]));
		printf("\tVotre score est : %3d \nEntrer une lettre :\n",score);
		AfficherMot(MotCacher);
		fflush(stdin);
		scanf("%c",&lettre_saisie);
		score += RemplacerLettre(argv[1],MotCacher,lettre_saisie);
		system(CLEAR);
		tour++;
	}while(pendu != 9 && !Gagner(MotCacher));
	AfficherMot(argv[1]);

	return 0;
}