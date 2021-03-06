/*Program to implement bankers algorithm
 * input=number of resoures,number of process
 * output = determine whether the state is safe
 * created on 15:10:12*/		
	  	
	
#include<stdio.h>
struct bank_algthm
{
    int alloc[10];
    int max[10];
    int need[10];
    int c;
}process[10];

int avail[10];
int m,n;
char res[5]={'A','B','C','D','E'};
int safe[20];
int grant[10];
int g=0;


void read()
{
    printf("\nEnter the number of processes:");
    scanf("%d",&n);
    int i,j;
    printf("\nEnter the number of resorces:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        process[i].c=0;
        printf("\n\nEnter the details of the process %d:\n",i+1);
        for(j=0;j<m;j++)
        {
            printf("\nEnter the instances of %c allocated:",res[j]);
            scanf("%d",&process[i].alloc[j]);
        }
        for(j=0;j<m;j++)
        {
            printf("\nEnter the instances of %c maximum:",res[j]);
            scanf("%d",&process[i].max[j]);
            process[i].need[j]=process[i].max[j]-process[i].alloc[j];
        }

    }


    printf("\nEnter the total instances of availailable resources:\n");
    for(i=0;i<m;i++)
    {
        printf("%c\t",res[i]);
        scanf("%d",&avail[i]);
    }
}


void display()
{
    int i,j;
    printf(" \t Alloc \t Max \t Need \t avail \n");
    printf(" \t ");
    for(j=0;j<4;j++,printf("\t "))
        for(i=0;i<m;i++)
            printf("%c",res[j]);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t",i);
        for(j=0;j<m;j++)
            printf("%d",process[i].alloc[j]);
        printf("\t");
        for(j=0;j<m;j++)
            printf("%d",process[i].max[j]);
        printf("\t");
        for(j=0;j<m;j++)
            printf("%d",process[i].need[j]);
        printf("\t");
        if(i==0)
        {
            for(j=0;j<m;j++)
                printf("%d\t",avail[j]);
        }
        printf("\n");
    }
}


int over()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(process[i].need[j]!=0)
                return 1;
    return 0;
}
void bankersalgo()
{
    int i,j,k,l;
    for(i=0,l=0;;i++,l++,i=i%n)
    {
        if(over()==0)
        {
            printf("\nAll processes complete\n\nNo Deadlock");
            printf("\n\nSafe state:");
            for(i=0;i<g;i++)
                printf("%d",safe[i]);
            printf(">");
            break;
        }
        else
        {
            if(process[i].c==0)
            {
                for(j=0;j<m;j++)
                    if(process[i].need[j]>avail[j])
                        break;
                if(j==m)
                {
                    safe[2 1 0 1]=i;
                    g++;
                    p[i].c=1;
                    for(j=0;j<m;j++)
                    {
                        avail[j]=avail[j]-p[i].need[j];
                        process[i].need[j]=0;
                        process[i].alloc[j]=process[i].max[j];
                    }
                    printf("\n\nProcess P%d is executing:\n\n",i);
                    display();
                    for(j=0;j<m;j++)
                    {
                        avail[j]=avail[j]+process[i].alloc[j];
                        process[i].alloc[j]=0;
                        process[i].max[j]=0;
                    }
                    printf("\n\nProcess P%d is completed:\n\n",i);
                    display();
                }
            }
        }
        if(l==25)
        {
            printf("....Deadlock...");
            break;
        }
    }
}

main()
{
    int choice;
    do
    {
        printf("\n\nBANKERS ALGORITHM");
        printf("\n1.Read data\n2.Display data\n3.Safe sequence\n4.Exit\nEnter you choiceoice--");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:read();break;
            case 2:display();break;
            case 3:bankersalgo();break;
            case 4:break;
        }
    }while(choice!=4);
}
