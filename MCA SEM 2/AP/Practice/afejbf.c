#include<stdio.h>

int maximum(int n, int num[])
{
	int i,max;

	max=num[0];
	for(i=1;i<n;i++)
	{
		if(max<num[i])
		{
			max=num[i];
		}
	}
	return max;
}

int minimum(int n, int num[])
{
	int i,min;

	min=num[0];
	for(i=1;i<n;i++)
	{
		if(min>num[i])
		{
			min=num[i];
		}
	}
	return min;
}


int length(int no)
{
	int rem,i=0;

	while(no!=0)
	{
		rem=no%10;
		no=no/10;
		i++;
	}
	return i;
	
}

int duplicate(int arr[],int size)
{
	int j,num,i,k=0,res[20],rem,rem2,cnt=0;
	
	
	for(i=0;i<size;i++)
	{	
		
		num=arr[i];
		while(num!=0)
		{
			rem=num%10;
			num=num/10;
		}
		res[k]=rem;
		k++;
	}	
	for(i=1;i<size;i+=2)
	{
		rem=res[i];
		for(j=i+2;j<size;j+=2)
		{
			if(rem==res[j])
			{
				cnt++;
			}

		}
	}
	cnt--;

	for(i=0;i<size;i+=2)
	{
		rem=res[i];
		for(j=i+2;j<size;j+=2)
		{
			if(rem==res[j])
			{
				cnt++;
			}

		}
	}
	return cnt;
}

int main()
{
	int n,i,j,arr[500],temp[5],tmp2[5],num,min,max,res,rem,k,final_res[30],l=0,size,value;
	scanf("%d",&n);
	
    if( n <= 500 )
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        for(i=0;i<n;i++)
        {
            j=0;
            
            num=arr[i];

            while(num!=0)
            {
                temp[j]=num%10;
                num=num/10;
                j++;
            }
            
            max=maximum(3,temp);
            min=minimum(3,temp);
            
            res=(max*11)+(min*7);
            if(length(res)==3)
            {
                k=0;
                while(res!=0)
                {
                    tmp2[k]=res%10;				
                    res=res/10;
                    k++;
                }
                if(tmp2[1]==0)
                {
                    res=tmp2[0];
                }
                else
                {
                    res=(tmp2[1]*10)+(tmp2[0]); 
                }
            }
            final_res[l]=res;
            l++;
        }
        size=l;

        value=duplicate(final_res,size);
        printf("%d",value);
    }
}