#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int main()
{
	int current[5][5];
	int maximum_claim[5][5];
	int available[5];
	int allocated[5] = {0,0,0,0,0};
	int maximum_resource[5];
	int running[5];
	
	int i,j,exec,r,p;
	int count = 0;
	bool safe = false;
	
	printf("\nEnter the number of resources : ");
	scanf("%d",&r);
	
	printf("\nEnter the number of processes : ");
	scanf("%d",&p);
	
	for(i=0; i<p ; i++)
	{
		running[i]=1;
		count++;
	}
	
	printf("\nEnter The total instances available of each resource : \n");
	for(i=0 ; i<r ;i++)
	{
		scanf("%d", &maximum_resource[i]);
	}
	
	printf("\nEnter Allocated Resource Table : \n");
	for(i=0 ; i<p ;i++)
	{
		for(j=0 ; j<r ; j++)
		{
			scanf("%d", &maximum_claim[i][j]);
		}
	}
	
	printf("\nThe total instances available of each resource : \n");
	for(i=0 ; i<r ;i++)
	{
		printf(" %d", maximum_resource[i]);
	}
	
	printf("\nThe Allocated Resource Table is : \n");
	for(i=0 ; i<p ;i++)
	{
		for(j=0 ; j<r ; j++)
		{
			printf("\t%d", current[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThe Maximum Claim Table is : \n");
	for(i=0 ; i<p ;i++)
	{
		for(j=0 ; j<r ; j++)
		{
			printf("\t%d",maximum_claim[i][j]);
		}
		printf("\n");		
	}
	
	for(i=0 ; i<p ; i++)
	{
		for(j=0 ; j<r ; j++)
		{
			allocated[j]+= current[i][j];
		}
	}
	
	printf("\nAllocated Resources are : \n");
	for(i=0 ;i<r ; i++)
	{
		printf("%d",allocated[i]);
	}
	for(i=0 ; i<r ;i++)
	{
		available[i] = maximum_resource[i] - allocated[i];
	}
	
	printf("\nAvailable Resources are : \n");
	for(i=0 ; i<r ; i++)
	{
		printf("%d",available[i]);
	}
	printf("\n");
	
	while(count !=0)
	{
		safe = false;
		for(i=0 ; i<p ; i++)
		{
			if(running[i])
			{
				exec = 1;
				for(j=0 ; j<r ; j++)
				{
					if(maximum_claim[i][j] - current[i][j] > available[j])
					{
						exec=0;
						break;
					}
				}
				
				if(exec)
			    {
					printf("\nProcess %d is Executing. \n", i+1);
					running[i] = 0;
					count--;
					safe = true;
					for(j=0 ; j<r ;j++)
					{
						available[j] += current[i][j];
					}
					break;
				}
			}
		}
		
		if(!safe)
		{
			printf("\nThe Processes are in Safe state.");
			break;
		}
		
		if(safe)
		{
			printf("\nThe Processes is in safe state. ");
		}
		
		printf("\nAvailable Vector : \n");
		for(i=0 ; i<r ; i++)
		{
			printf("%d",available[i]);
		}
	}
	
	return 0;
	
}
