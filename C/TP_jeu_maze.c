#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CONSTANTES
#define MAP_X_SIZE 0x0A
#define MAP_Y_SIZE 0x0A
#define GREEN_COLOR 0x20
#define RED_COLOR 0x1F
#define TOUCH_QUITTER 'p'
#define FOND_MAP '*'
#define CLEAR "clear" // pour Win replacer "clear" par "cls"


//Si les ' int8_t ' vous pose probleme changé par 'char ' 

// PROTOTYPE
void InitialiserMap(char _map[MAP_X_SIZE][MAP_Y_SIZE]);
void AfficherMap(char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _score);
void PlacerJoeur(char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _x, int8_t _y, char _skin);
uint8_t LoseTest(const char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _x, int8_t _y, int8_t _score);
int8_t DeplacerJoueur(char _map[MAP_X_SIZE][MAP_Y_SIZE], char _deplacement, int8_t* _x, int8_t* _y, char _skin);// 1 : Deplacement OK et 2 : Pas de Deplacelent
int8_t AutoriserDeplacement(const char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _x, int8_t _y);						// 1 : Autoriser et 2 : Non Autoriser



//MAIN
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	char map[MAP_X_SIZE][MAP_Y_SIZE];
	char input = 0;
	char skin = 0;
	int8_t score = 0;
	int8_t pos_x_player = (int8_t)(rand() / (double)RAND_MAX * (MAP_X_SIZE - 1));
	int8_t pos_y_player = (int8_t)(rand() / (double)RAND_MAX * (MAP_Y_SIZE - 1));


	/****************************************************************************
	
	//		TEST PART FOR OPTION
	
	if(argc != 0 && argv[1][0] !='-')
	{
		printf("-h or -H : Option pour afficher l'aide ");
		return -1;
	}
	if(argv[1][1]=='h' || argv[1][1]=='H')
	{
		printf("Pour quitter le jeu appuyer sur :\t%c\n",TOUCH_QUITTER );
		printf("-r or -R : Option pour afficher les regles du jeu ");
		return 1;
	}
	if(argv[1][1]=='r' || argv[1][1]=='R')
	{
		printf("Pour quitter le jeu appuyer sur :\t%c\n",TOUCH_QUITTER );

		return 2;
	}/***************************************************************************/
printf("Bnjour, Veuiller choisir un caracter et appuiyer sur entree \nil seras utiliser en tant que skin pour le jeu alors choisie bien :)\n");
	scanf("%c",&input);
	skin = input;
	InitialiserMap(map);
	time_t begin = time(NULL);

	do
	{	
		score += DeplacerJoueur(map,input,&pos_x_player,&pos_y_player,skin);
		if(LoseTest(map, pos_x_player, pos_y_player,score)|| score == 99)break;
		AfficherMap(map , score);
		fflush(stdin);
		scanf("%c",&input);
		system(CLEAR);
	}while (input != TOUCH_QUITTER);
	printf("\tTemps : %ld seconds\n", (time(NULL) - begin));

	return 0;
}


void InitialiserMap(char _map[MAP_X_SIZE][MAP_Y_SIZE])
{
	for(int i = 0; i < MAP_X_SIZE; i++)
	{
		for(int j = 0; j < MAP_Y_SIZE; j++)
		{
			_map[i][j]=FOND_MAP;
		}
	}
}

void AfficherMap(char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _score)
{
	system(CLEAR);
	for(int i = 0; i < MAP_X_SIZE; i++)
	{
		for(int j = 0; j < MAP_Y_SIZE; j++)
		{
			if(_map[i][j]==32 || _map[i][j]==FOND_MAP)printf("%c",_map[i][j]);
			else printf("\033[%dm%c\033[00m",RED_COLOR,_map[i][j]);
		}
		printf("\n");
	}
	if(_score != 99)printf("Score : \033[%dm%3d\033[00m\n", GREEN_COLOR,_score);
	else printf("\033[%dm  VICTOIRE !! BRAVO !!\033[00m\n", GREEN_COLOR);
}

void PlacerJoeur(char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _x, int8_t _y, char _skin)
{
	_map[_x][_y] = _skin;
}


uint8_t LoseTest(const char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _x, int8_t _y, int8_t _score)
{
	if(_map[_x-1][_y] != FOND_MAP && _map[_x+1][_y] != FOND_MAP && _map[_x][_y-1] != FOND_MAP && _map[_x][_y+1] != FOND_MAP && _score != 99)
		{
			system(CLEAR);
			printf("\033[%dm\tPERDU\n \033[00m",RED_COLOR);
			return 1;
		}
	return 0;
}

int8_t DeplacerJoueur(char _map[MAP_X_SIZE][MAP_Y_SIZE], char _deplacement, int8_t* _x, int8_t* _y, char _skin)
{
	if(_deplacement == 122 && AutoriserDeplacement(_map,*_x-1,*_y))
	{
		_map[*_x][*_y] = 32;
		*_x = *_x-1;
		PlacerJoeur(_map,*_x,*_y,_skin);
		return 1;
	}
	if(_deplacement == 115 && AutoriserDeplacement(_map,*_x+1,*_y))
	{
		_map[*_x][*_y] = 32;
		*_x = *_x+1;
		PlacerJoeur(_map,*_x,*_y,_skin);
		return 1;
	}
	if(_deplacement == 113 && AutoriserDeplacement(_map,*_x,*_y-1))
	{
		_map[*_x][*_y] = 32;
		*_y = *_y-1;
		PlacerJoeur(_map,*_x,*_y,_skin);
		return 1;
	}
	if(_deplacement == 100 && AutoriserDeplacement(_map,*_x,*_y+1))
	{
		_map[*_x][*_y] = 32;
		*_y = *_y+1;
		PlacerJoeur(_map,*_x,*_y,_skin);
		return 1;
	}
	return 0;
}


int8_t AutoriserDeplacement(const char _map[MAP_X_SIZE][MAP_Y_SIZE], int8_t _x, int8_t _y)
{
	if(_x != -1 && _y != -1 && _x != MAP_X_SIZE && _y != MAP_Y_SIZE && _map[_x][_y] == FOND_MAP)return 1;
	return 0;	
}
