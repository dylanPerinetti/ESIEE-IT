#include <stdio.h>

int main(void)
{
	int user_saisi = 0;
	int _affich_num = 1;

	printf("Combien de nombres à tester :\n-->");
	scanf("%d",&user_saisi);

	printf("000--> [\t\033[31m0\033[00m\t]\n");

	for (int i = 1; i < user_saisi+1; ++i)
	{
		printf("%.3d-->[",i);
		if(!(i%3))
		{
			printf("\033[32mFizz\033[00m");
			_affich_num = 0;
		}
		if(!(i%5))
		{
			printf("\033[33mBuzz\033[00m");
			_affich_num = 0;
		}
		if(_affich_num)
		{
			printf("\t\033[31m%d\033[00m",i);
		}
		_affich_num = 1;

		printf("\t]\n");
	}
	return 0;
}
