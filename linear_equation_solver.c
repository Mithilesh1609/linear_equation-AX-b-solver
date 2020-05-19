#include<stdio.h>
#include<math.h>

void PrintMat(int n,int m,float mat[][m+1])
{
    int i,j;  
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j <= m; j++)
        {
        	if(j==m){printf("|");}
            printf("%0.2f\t",mat[i][j]);            
        }
        printf("\n");
    }   
}

//int IGNOR_ROWSWAP_IF_ROW_IS_ZERO(int n,int m,float mat[][m+1])
//{
//	int j=0,i,count=0;
//	for(i=n-1;i>0;i--){
//		for(j=0;j<m+1;j++)
//		{
//		int yn=0;	
//			if((mat[i][j])==0)
//			{
//				yn=1;
//			}
//			if(yn==1)
//			{
//				count++;
//			}
//		}
//	}
//	
//	return count;
//}

/*bool CHECK_ROW_ZERO_BREAK(int n , int m , float mat){
	int i , j , cnt = 0 ;
	for(i = n-1  ; i > 0 ; i-- ){
		for(j=)
	}
}*/

void ROWELEM(int n,int m,float mat[][m+1])
{
	   
	printf("---------------------------------ROW ELEMINATION------------------------------------\n");
	
	int min = 0  ;
	if(m>n){
		min=n;
	}else{
		min = m;
	}
	int i=0,j=0,k=0;
	
	for(i=0;i<min;i++)
	{		
		SWAPROWS(n,m,mat);
		
		//x=IGNOR_ROWSWAP_IF_ROW_IS_ZERO(n,m,mat);		
		float pri=mat[i][i]	;	
		for(j=i+1;j<min;j++)
		{
			float coffi=mat[j][i]/pri;
			for(k=0;k<m+1;k++)
			{
				mat[j][k]-=coffi*mat[i][k];
			}
		}
		PrintMat(n,m,mat);
		
	}
	BACKSUP(n,m,mat);	
}
BACKSUP(int n,int m,float mat[][m+1])
{
	
	int min = 0  ;
	if(m>n){
		min=n;
	}else{
		min = m;
	}
	int i=0,j=0,k=0;
	   
	printf("-----------------------------------BACK SUP-----------------------------------------\n");
	for(i=min-1;i>=0;i--)
	{	
		
		int x;
		/*;		
		n-=x;
		i-=x;		*/
		printf("n=%d  i=%d");
		float pri=mat[i][i]	;	
		for(j=i-1;j>=0;j--)
		{			
			float coffi=mat[j][i]/pri;
			for(k=m;k>=0;k--)
			{
				mat[j][k]-=coffi*mat[i][k];
			}
		}
		PrintMat(n,m,mat);		
	}
	MAKE_IDENTITY(n,m,mat);	
	
}
void SWAPROWS(int n,int m,float mat[][m+1])
{
	printf("Entered in roeswap");
	int i,j,k,po=n-1;
	for(i=0;i<n-1;i++)				//i for row
	{
		if(mat[i][i]==0)
		{
			for(j=n-1;j>i;j--)		//j for cheking rows 
			{
				if(mat[j][i]!=0)
				{
					po=j;
					break;		
				}												
			}
			float temp;
			for(k=0;k<m+1;k++)
			{
				temp=mat[po][k];
				mat[po][k]=mat[i][k];
				mat[i][k]=temp;
			}			
		}
		po--;
	}
}
void MAKE_IDENTITY(int n,int m,float mat[][m+1])
{   
   	
	printf("--------------------------------MAKING IDENTITY-------------------------------------\n");
	
	int min = 0  ;
	if(m>n){
		min=n;
	}else{
		min = m;
	}
	int i=0,j=0,k=0;
	for(i=0;i<min;i++)
	{
		float priv=mat[i][i];
		for(j=0;j<m+1;j++)
		{
			mat[i][j]/=priv;
		}
	}
}
int main()
{
    int n,m,j,i;
    printf("Enter the Number of columns: ");
    scanf("%d",&m);
    printf("Enter the Number of rows: ");
    scanf("%d",&n);
    printf("Enter Matrix A for Ax=b: \n");
    
	float mat[n][m+1];
    for ( i = 0; i < n; i++)
    {    	
	    for ( j = 0; j < m; j++)
        {
            printf("Enter A[%d][%d]:",i+1,j+1);
            scanf("%f", &mat[i][j]);   
			//printf("Enter A[%d][%d]=%f: \n",i+1,j+1,mat[i][j]);         
        }        
    }	
    printf("Enter Matrix b for Ax=b: \n");
    for ( i = 0; i < n; i++)
    {    
		printf("Enter b[%d]:",i+1);
	    scanf("%f", &mat[i][m]);       
    }
	   
   printf("-----------------------------GIVEN MATRIX AND VECTOR--------------------------------\n");
	
      PrintMat(n,m,mat);
      ROWELEM(n,m,mat);
    printf("---------------------------------FINAL ANSWER---------------------------------------\n");
	  
	  
	  //SWAPROWS(n,m,mat);
      PrintMat(n,m,mat);
 return 0;
}

