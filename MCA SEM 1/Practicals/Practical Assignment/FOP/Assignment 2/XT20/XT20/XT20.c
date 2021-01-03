#include<stdio.h>
#include<conio.h>
void main()
{
	int i, j, getchar1 = 0, getkey1 = 0, dec;
	char c = 32, input[50], encpy_table[100][100], key[]= "iMpoSSib1eteXtPleaSe#0071998", ENCRPYT[20], DECRYPT[20];
	printf("Enter The String : ");
	scanf("%s",input);
	for( i = 0; i < 91; i++ )
	{
		c = 32+i;
		for( j = 0; j < 91; j++ )
		{	
			encpy_table[i][j] = c;
			/*printf("%c ",encpy_table[i][j]);*/
			if(c == 122)
				c = 32;
			else
				c++;
		}
		/*printf("\n");*/
	}
	i=0;
	j=0;
	printf(" Encrypted Text = ");
	while(input[i] != '\0')
	{
		getchar1 = input[i]-32;
		if(key[j] == '\0')
		{
			j = 0;
		}
		else{
			getkey1 = key[j]-32;
		}
		ENCRPYT[i] = encpy_table[getchar1][getkey1];
		printf("%c",ENCRPYT[i]);
		i++;
		j++;
	}
	getch();
}
