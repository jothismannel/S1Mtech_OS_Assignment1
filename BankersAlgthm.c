/*Program to implement bankers algorithm
 * input=number of resoures,number of process
 * output = determine whether the state is safe
 * created on 15:10:12*/		
	  	
	
#include<stdio.h>

int main()
{
    int claim[7][5],request[7][5],allocate[7][5],resource[5],available[5],comp[7];
    int first,p,r,i,j,prc,count,t;
    count=0;
    for(i=1;i<=7;i++)
        comp[i]=0;

    printf("\n BANKERS ALGORITHM \n");
    printf("Enter the no of processes : "); //reading number of process
    scanf("%d",&p);
    printf("\nEnter the no of resources : "); //reading number of resourses
    scanf("%d",&r);
    printf("\nEnter the claim for each process : ");
    for(i=1;i<=p;i++)
    {
        printf("\nFor process %d : ",i);
        for(j=1;j<=r;j++)
        {
            scanf("%d",&claim[i][j]);
        }
    }
    printf("\nEnter the allocation for each process : ");
    for(i=1;i<=p;i++)
    {
        printf("\nFor process ",i);
        for(j=1;j<=r;j++)
        {
            scanf("%d",&allocate[i][j]);
        }
    }
    printf("\nEnter total no of each resource : ");
    for(j=1;j<=r;j++)
        scanf("%d",&resource[j]);
    for(j=1;j<=r;j++)
    {
        int total=0;
        avail[j]=0;
        for(i=1;i<=p;i++)
        {
	total+=allocate[i][j];
	}
        available[j]=resource[j]-total;
    }
    do
    {
        for(i=1;i<=p;i++)
        {
            for(j=1;j<=r;j++)
            {
                request[i][j]=claim[i][j]-allocate[i][j];
            }
        }
        printf("\n\nAvailable resources are : ");
        for(j=1;j<=r;j++)
        { printf(" ",available[j]); }
        printf("\nClaim matrix:\tAllocation matrix:\n");
        for(i=1;i<=p;i++)
        {
            for(j=1;j<=r;j++)
            {
                printf("%d\t",claim[i][j]);
            }
            printf("\t\t\t");
            for(j=1;j<=r;j++)
            {
                printf("%d\t",allocate[i][j]);
            }
            printf("\n");
        }
        prc=0;
        for(i=1;i<=p;i++)
        {
            if(comp[i]==0)
            {
                prc=i;
                for(j=1;j<=r;j++)
                {
                    if(available[j])
                    {
                        prc=0;
                        break;
                    }
                }
            }
            if(prc!=0)
                break;
        }
        if(prc!=0)
        {
            printf("\nProcess ",prc,"runs to completion!");
            count++;
            for(j=1;j<=r;j++)
            {
                available[j]+=allocate[prc][j];
                allocate[prc][j]=0;
                claim[prc][j]=0;
                comp[prc]=1;
            }
        }
    }
    while(count!=p&&prc!=0);
    if(count==p)
        printf("\nThe system is in a safe state!!");
    else
        printf("\nThe system is in an unsafe state!!");
return ;
}
