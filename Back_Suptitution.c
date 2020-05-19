#include<stdio.h>
#include<math.h>
//#include "Print_Matrix.c"
//#include "Identity_Maker.c"

void Back_Suptitution(int m,int n,float mat[][n+1],int solution_type)
{	
	int min = 0;
	if(n>m){
		min=m;
	}else{
		min = n;
	}
	int i=0,j=0,k=0, l=0, counter=0;
	printf("\n--------------------------------------------------------------------------------------------\n");   
	printf("\n-----------------------------------Back Suptitution-----------------------------------------\n");
	for(l = 0; l<min; l++){
		if(mat[l][l] != 0){
			counter++;
		}
	}
	for(i=min-1; i>=0; i--)
	{
		//printf("n=%d  i=%d");
		float pri=mat[i][i]	;
		if(pri)
		{
			for(j=i-1;j>=0;j--)
			{			
				float coffi=mat[j][i]/pri;
				for(k=n;k>=0;k--)
				{
					mat[j][k]-=coffi*mat[i][k];
				}
			}
			Print_Matrix(m,n,mat);	
		}	
				
	}
	Identity_Maker(m,n,mat,solution_type);	
	
}
