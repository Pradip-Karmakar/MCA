#include<stdio.h>
int count_student( int i, int j, int count )
{
	while( i != 0 || j != 0 )
	{
		if( i == j )
		{
			count += 1;
			i = 0;
			j = 0;
		}
		else if( i > j )
		{
			count += 1;
			i = i - j;
			
		}
		else if( j > i )
		{
			count += 1;
			j = j - i;
		}
	}
	return count;
}

int main()
{
	int P = 0, Q = 0,  R = 0,  S = 0, i, j, count, total = 0;
	scanf("%d",&P);
	scanf("%d",&Q);
	scanf("%d",&R);
	scanf("%d",&S);
	if(P > 0 && P < 1501)
	{
		if(Q > 0 && Q < 1501)
		{
			if(R > 0 && R < 1501)
			{
				if(S > 0 && S < 1501)
				{
					if(P<Q)
					{
						if(R<S)
						{
							for( i = P ; i <= Q; i++ )
							{
								for( j = R; j <= S; j++ )
								{
									count = 0;
									count += count_student( i, j, count);
									total += count;
								}
							}
							printf("%d",total);
						}
					}
				}
			}
		}
	}
	return 0;
}

