
/*Program to implement bankers algorithm
 * input=number of resoures,number of process
 * output = determine whether the state is safe
 * created on 15:10:12*/		
	  	
	
#include<stdio.h>
	 
main()
{  
	int m,n;            //n-->number of processes
	int i,j,flagchek=0;   //m-->number of  resource types
	 
	printf("enter the number of process: ");  
	
	printf("\n***************************\n");
	scanf("%d",&n);  
	
	printf("enter the number of resource types: ");
	
	printf("\n**********************************\n");
	scanf("%d",&m);
	  
	 
	int avail[1][20],max[20][20],alloc[20][20],
             need[20][20],finish[10];
	 
	int seq[10],flagarr[10];
	
	printf("enter the values for the matrix max \n");
	printf("\n**********************************\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
	            printf("\nvalue for position %d and %d",i,j);
	            scanf("%d",&max[i][j]);
	        }
	    
	 }
	    
	 printf("enter the values for the allocation matrix :\n");
	 printf("\n******************************************\n");
	 for(i=0;i<n;i++)
	 {
	       for(j=0;j<m;j++)
	       {
	           printf("\nvalue for position %d and %d",i,j);
	           scanf("%d",&alloc[i][j]);
	       }
	    
	 }
	    
	 printf("enter the number of available resources :\n");
	 printf("\n***************************************\n");
	 
	 for(i=0;i<m;i++)
	 {
	          printf("\nvalue for position %d",i);
	          scanf("%d",&avail[0][i]);
	 }
	 for(i=0;i<n;i++)
	 {
             for(j=0;j<m;j++)
                {
                   need[i][j]=max[i][j]-alloc[i][j];
                }
          }

	  for(i=0;i<n;i++)
	  {
	      finish[i]=0;
	  }
	    int k;
	    int x=0;
	 
	   
	  for(i=0;i<n;i++)
	  {
	        for(j=0;j<m;j++)
	        {
	           if(finish[i]==0 && 
		   need[i][j]<=avail[0][j])
	           {
	               flagarr[j]=1;
                   }
	 
	           else
	           {
 
	           flagarr[j]=0;
	           }
	  }
	  int flag=0;
	  int flagarrint=0;
	  
           for(k=0;k<m;k++)
           {
                if(flagarr[k]==1)
                {
                    flagarrint++;
	 
                }
	 
	       if(flagarrint==m)
               {   
			for(k=0;k<m;k++)
                        {
	                        avail[0][k]+=alloc[i][k];
	                        printf("%d",avail[0][k]);
	                        finish[i]=1;
	                        flag=1;
	                 }
	 
	 
	       }
	 
	       else
	         finish[i]=0;
	       }
	   
	   if(flag==1)
	   {
	        seq[x]=i;
	         x++;
	   }
	   printf("\n");
	 
	  }
	 
	  for(i=0;i<n;i++)
	  {
	      if(finish[i]==1)
	      {
	           flagchek++;
	 
	      }
	 }
	      
	 if(flagchek==n)
	 {
	 printf("The system is in the safe state");
         }
	 else
	 {               
	 printf("the process sequence is :<");
	 }
	 for(i=0;i<n;i++)
	 {
	         printf("%d",seq[i]);
	 }
	 printf(">\n");
	 
	  
	 }
