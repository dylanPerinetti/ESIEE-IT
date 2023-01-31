/*
Voici la CORECTION

Fait par dylan le Mer22 juin 2022
à 20:39

1) Modifier l'affichage pour afficher ne nombre d'heur de vols et la Comp du pilote
2) Code la fonction lier a ce prototype void AjouterHeurDeVols(S_pilote* _pilote, int heur_de_vols_supplementaire); 						//cette foction permet d'ajouter des heurs de vols a un pilote 
3) Code la fonction lier a ce prototype void ChangerDeCompagnies(S_pilote* _pilote, char nouvelle_comp);									// chager la comp dunnpilote

Bonus Completer le main pour que l'on puisse selectioner le pilote et le modifier a sa guize

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 0xff  		//256
#define NOMBRE_DE_PILOTE 0x01	//1
#define VIDE_TERM "clear"     //La commande sur windows est "cls"


typedef struct pilote
{
    char prenom[BUFFER_SIZE];
    char nom[BUFFER_SIZE];
    char statut[BUFFER_SIZE];
    int age;
    int heur_de_vols;
    char compagnies[BUFFER_SIZE];
}S_pilote;



S_pilote CreePilote(char nom_pilote[], char prenom_pilote[], char statut_pilote[], int age_pilote, int heur_de_vols_pilote, char compagnies_pilote[]);	//Return &pilote
void AfficherPilote(S_pilote pilote_a_afficher);
void AjouterHeurDeVols(S_pilote* _pilote, int heur_de_vols_supplementaire); 						//cette foction permet d'ajouter des heurs de vols a un pilote 
void ChangerDeCompagnies(S_pilote* _pilote, char nouvelle_comp[]);									//changer la comp d'un pilote


int main(void)
{
	char reponse1_utilisateur[BUFFER_SIZE];
	char reponse2_utilisateur[BUFFER_SIZE];
	char reponse3_utilisateur[BUFFER_SIZE];
	int reponse4_utilisateur, reponse5_utilisateur;
	char reponse6_utilisateur[BUFFER_SIZE];

	S_pilote tab_pilote[NOMBRE_DE_PILOTE];

	for (int i = 0; i < NOMBRE_DE_PILOTE; ++i)
		{
		printf("\nEntree le nom du pilote :\n--> ");												//Demander le Nom du pilote a l'utilisateur du programme
		scanf("%s",reponse1_utilisateur);

		printf("\nEntree le prenom du pilote :\n--> ");												//Demander le Prenom du pilote a l'utilisateur du programme
		scanf("%s",reponse2_utilisateur);

		printf("\nEntree le statut du pilote :\n--> ");												//Demander le statut du pilote a l'utilisateur du programme
		scanf("%s",reponse3_utilisateur);

		printf("\nEntree l'age du pilote :\n--> ");													//Demander l'age du pilote a l'utilisateur du programme
		scanf("%d",&reponse4_utilisateur);

		printf("\nEntree le total d'heur de vols :\n--> ");
		scanf("%d",&reponse5_utilisateur);

		printf("\nEntree le nom de la compagnies :\n--> ");
		scanf("%s",reponse6_utilisateur);

		tab_pilote[i] = CreePilote(reponse1_utilisateur, reponse2_utilisateur, reponse3_utilisateur, reponse4_utilisateur, reponse5_utilisateur, reponse6_utilisateur); //Remplie
		AfficherPilote(tab_pilote[i]);
	}


	////////////////////////////////////////
	//______________ BONUS _______________//

	printf("\nQuelle pilote souhaitez-vous modifier ? \n(Quelle est son numeros dans le tableau des pilotes de 0 a %d)",(NOMBRE_DE_PILOTE-1));
	scanf("%d",&reponse4_utilisateur);

	system(VIDE_TERM);
	AfficherPilote(tab_pilote[reponse4_utilisateur]);

	printf("\nCombien d'heurs de vols vient t'il effectuer ?\n--> ");
	scanf("%d",&reponse5_utilisateur);
	printf("\nEntree le nom de la nouvelle compagnie ou appuiyer sur [t + Entree] pour ne pas chager sa compagnie\n--> ");
	scanf("%s",reponse6_utilisateur);
	
	AjouterHeurDeVols(&tab_pilote[reponse4_utilisateur],reponse5_utilisateur);
	if(strcmp(reponse6_utilisateur,"t\0")!=0) ChangerDeCompagnies(&tab_pilote[reponse4_utilisateur], reponse6_utilisateur);

	system(VIDE_TERM);
	AfficherPilote(tab_pilote[reponse4_utilisateur]);

	//______________ BONUS _______________//
	////////////////////////////////////////



	return 0;
}

S_pilote CreePilote(char nom_pilote[], char prenom_pilote[], char statut_pilote[], int age_pilote, int heur_de_vols_pilote, char compagnies_pilote[])
{
	static S_pilote _pilote;
	strcpy(_pilote.nom, nom_pilote);
	strcpy(_pilote.prenom, prenom_pilote);
	strcpy(_pilote.statut, statut_pilote);
	strcpy(_pilote.compagnies, compagnies_pilote);
	_pilote.age = age_pilote;
	_pilote.heur_de_vols = heur_de_vols_pilote;

	return _pilote;
}

void AfficherPilote(S_pilote pilote_a_afficher)
{
	printf("----- Fiche Pilote -----\n\n");

	printf("Nom    : %s\n",pilote_a_afficher.nom);
	printf("Prenom : %s\n",pilote_a_afficher.prenom);
	printf("statut : %s\n",pilote_a_afficher.statut);
	printf("Age    : %d Ans\n",pilote_a_afficher.age);
	printf("vols   : %d Heur\n",pilote_a_afficher.heur_de_vols);
	printf("compagnies : %s\n\n",pilote_a_afficher.compagnies);
}

void AjouterHeurDeVols(S_pilote* _pilote, int heur_de_vols_supplementaire)
{
	_pilote->heur_de_vols = _pilote->heur_de_vols + heur_de_vols_supplementaire;
	//ON POUVAIS AUSSI ECRIRE : *_pilote.heur_de_vols  à la place _pilote->heur_de_vols
}

void ChangerDeCompagnies(S_pilote* _pilote, char nouvelle_comp[])
{
	strcpy(_pilote->compagnies,nouvelle_comp);
	//ON POUVAIS AUSSI ECRIRE : *_pilote.compagnies  à la place _pilote->compagnies
}
