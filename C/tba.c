#include "tba.h"

unsigned char CompterLettre(const char* _tab)
{
	int i = 0;
	while(_tab[i]!='\0')i++;
	return i;
}

unsigned char RemplacerLettre(const char* _tab, char* _mots_cacher, char _lettre)
{
	int _i = 0;
	unsigned char _score = 0;
	do
	{
		if(_lettre == _tab[_i])
		{
			_mots_cacher[_i] = _lettre;
			_score++;
		}
		_i++;
	}while(_tab[_i]!='\0');
	return _score;
}

unsigned char Gagner(char* _mots_cacher)
{
	int _i = 0;
	unsigned char _gagner = 1;
	do
	{
		if('_' == _mots_cacher[_i])_gagner = 0;
		_i++;
	}while(_mots_cacher[_i]!='\0');
	return _gagner;
}

void AfficherPendu(unsigned char _pendu)
{
	switch(_pendu){
		case 1:
			printf("\n\n\n\n\n\n\n\n\n\n\t=============");
			break;
		case 2:
			printf("\n\n\t+\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t=============");
			break;
		case 3:
			printf("\n\n\t+-------+\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t=============");
			break;
		case 4:
			printf("\n\n\t+-------+\n\t|\t|\n\t|\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n\t=============");
			break;
		case 5:
			printf("\n\n\t+-------+\n\t|\t|\n\t|\t_\n\t|      / \\\n\t|      \\_/\n\t|\n\t|\n\t|\n\t|\n\t=============");
			break;
		case 7:
			printf("\n\n\t+-------+\n\t|\t|\n\t|\t_\n\t|      / \\\n\t|      \\_/\n\t|\t|\n\t|\t|\n\t|\n\t|\n\t=============");
			break;
		case 8:
			printf("\n\n\t+-------+\n\t|\t|\n\t|\t_\n\t|      / \\\n\t|      \\_/\n\t|\t|\n\t|\t|\n\t|\t^\n\t|      / \n\t=============");
			break;
		case 9:
			printf("\n\n\t+-------+\n\t|\t|\n\t|\t_\n\t|      / \\\n\t|      \\_/\n\t|\t|\n\t|\t|\n\t|\t^\n\t|      / \\\n\t=============");
			break;
		default:
			break;

	}
}

void AfficherMot(const char* _tab)
{
	int i = 0;
	while(_tab[i]!='\0')
	{
		printf("%c ",_tab[i]);
		i++;
	}
	printf("\n");
}


void RemplireMotCacher(const char* _tab, char* _mots_cacher)
{
	int i = 0;
	do
	{
		_mots_cacher[i] = '_';
		i++;
	}while(_tab[i]!='\0');
}