#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int main()
{
	int current[5][5];                //stores currently allocated resources of each type of each process
	int maximum_claim[5][5];          //stores maximum need of resources of each type of each process 
	int available[5];                 //stores the currently available resources of each type 
	int allocated[5] = {0,0,0,0,0};   //stores total of currently allocated resources of each type  
	int maximum_resource[5];          //stores total instances of each resource 
	int running[5];                   //stores the information of process whether it is in execution or it has terminated
	int new_request[5][5];            //stores the new request table of each process
	int new_req[5];
	
	int i,j,exec,r,p;
	//r is variable of number of resources 
	//p is variable of number of processes
	//i and j are used in loops
	
	int count = 0;                    //stores total number of processes in execution 
	bool safe = false;
	
	//taking input from user for number of resources
	printf("\nEnter the number of resources : ");
	scanf("%d",&r);
	
	//taking input from user for number of processes
	printf("\nEnter the number of processes : ");
	scanf("%d",&p);
	
	//sets value for each process in execution
	for(i=0; i<p ; i++)
	{
		running[i]=1;   
		count++;        //total number of processes in execution 
	}
	
	//taking input from user for total number of instances of each resource
	printf("\nEnter The total number of instances of each resource : \n");
	for(i=0 ; i<r ;i++)
	{
		scanf("%d", &maximum_resource[i]);
	}
	
	//taking input from user for currently allocated resources of each type for each process  
	printf("\nEnter the Allocated Resource Table : \n");
	for(i=0 ; i<p ;i++)
	{
		for(j=0 ; j<r ; j++)
		{
			scanf("%d", &current[i][j]);
		}
	}
	
	//taking input from user for maximum need of resources of each type for each process 
	printf("\nEnter the Maximum Claim Table : \n");
	for(i=0 ; i<p ;i++)
	{
		for(j=0 ; j<r ; j++)
		{
			scanf("%d", &maximum_claim[i][j]);		   	
		}
	}
	
	//taking input from user for New Request for resources made by the processes
	printf("\nEnter the New Request Table : \n");
	for(i=0 ; i<p ;i++)
	{
		for(j=0 ; j<r ; j++)
		{
			scanf("%d", &new_request[i][j]);		   	
		}
	}
	
	//displays the value
	printf("\nThe total number of instances of each resource : \n\t");
	printf("\tA\tB\tC\n\t");
	for(i=0 ; i<r ;i++)
	{
		printf("\t%d", maximum_resource[i]);
	}
	
	//displays the value
	printf("\nThe Allocated Resource Table is : \n");
	printf("\t\tA\tB\tC\n");
	for(i=0 ; i<p ;i++)
	{
		printf("\tP%d",i);
		for(j=0 ; j<r ; j++)
		{
			
			printf("\t%d", current[i][j]);
		}
		printf("\n");
	}
	
	//displays the value
	printf("\nThe Maximum Claim Table is : \n");
	printf("\t\tA\tB\tC\n");
	for(i=0 ; i<p ;i++)
	{
		printf("\tP%d",i);
		for(j=0 ; j<r ; j++)
		{
			printf("\t%d",maximum_claim[i][j]);
		}
		printf("\n");		
	}
	
	//displays the value
	printf("\nThe New Request Table is : \n");
	printf("\t\tA\tB\tC\n");
	for(i=0 ; i<p ;i++)
	{
		printf("\tP%d",i);
		for(j=0 ; j<r ; j++)
		{
			printf("\t%d",new_request[i][j]);
		}
		printf("\n");		
	}
	
	//total of currently allocated resources of each type or the total instances of a particular resource currently allocated
	for(i=0 ; i<p ; i++)
	{
		for(j=0 ; j<r ; j++)
		{
			allocated[j]+= current[i][j];
		}
	}
	
	//displays the value 
	printf("\nThe Allocated Resources are : \n\t");
	printf("\tA\tB\tC\n\t");
	for(i=0 ;i<r ; i++)
	{
		printf("\t%d",allocated[i]);
	}
	
	for(i=0 ; i<r ;i++)
	{
		available[i] = maximum_resource[i] - allocated[i];
	}
	
	printf("\nThe Available Resources are : \n\t");
    printf("\tA\tB\tC\n\t");
	for(i=0 ; i<r ; i++)
	{
		printf("\t%d",available[i]);
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
					if(new_request[i][j] > available[j])
					{
						exec=0;
						break;
					}
				}
				
				if(exec)
			    {
					for(j=0 ; j<r ; j++)
					{
						if(new_request[i][j]<available[j])
						{
				    	    available[j] -= new_request[i][j];
				    	    current[i][j] += new_request[i][j];
				    	     
				    	    if(maximum_claim[i][j] - current[i][j] > available[j])
				    	    {
				    	    	printf("\nProcess %d is in Unsafe State, So The Request made cannot be granted.!\n",i);
				    	    	available[j] += new_request[i][j];
				    	    	current[i][j] -= new_request[i][j];
				    	    	exec = 0;
				    	    	break;
							}
						}
					}
								
				    printf("\nProcess %d is Executing. \n", i);		
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
			printf("\nThe Processes is in Unsafe state.\n");
			break;
		}
		
		if(safe)
		{
			printf("\nThe Processes is in Safe state.\n");
		}
		
		printf("\nThe Available Resources are : \n\t");
		printf("\tA\tB\tC\n\t");
		for(i=0 ; i<r ; i++)
		{
			printf("\t%d",available[i]);
		}
	}
	
	return 0;
	
}
