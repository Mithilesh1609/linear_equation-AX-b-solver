#include<stdio.h>
#include<math.h>
//#include "Print_Matrix.c"
//#include "Back_Suptitution.c"
//#include "Zero_Row_Indicator.c"

void Row_Elimination_Check_Solution_Type(int m,int n,float mat[][n+1])
{
	printf("---------------------------------ROW ELEMINATION------------------------------------\n");
	
	int min = 0;          // m = #rows
	if(n > m) {			  // n = #columns
		min = m;
	} else {
		min = n;
	}
	int i=0,j=0,k=0,l=0;
	
	for(i = 0; i < min; i++)
	{	
		//for(k=0;)	
		//SWAPROWS(n,m,mat);
		float pri = mat[i][i];	
		if(pri != 0){	
			for(j = i + 1; j < m; j++)
			{
				float coffi = mat[j][i]/pri;
				for(k = 0; k < n+1; k++)
				{
					mat[j][k] -= coffi*mat[i][k];
				}
			}
		}
		else if(pri == 0){
			Row_Swapping(m, n, mat, i);
			pri = mat[i][i];
			if(pri != 0){
				for(j = i + 1; j < min; j++)
				{
					float coffi = mat[j][i]/pri;
					for(k = 0; k < m+1; k++)
					{
						mat[j][k] -= coffi*mat[i][k];
					}
				}
			}
		}
		Print_Matrix(m,n,mat);
		
	}
	int count = 0;
	for(l=0; l<min; l++)
	{
		if(mat[l][l] != 0)
		{
			count++;
		}
	}
	if(m < n)    // LOGIC FOR FAT MATRIX
	{
		printf("\n----------------------------------Solution Type------------------------------------\n"); 
		printf("\n   ------>>      System have INFINITE SOLUTION...                                     \n");
		Back_Suptitution(m, n, mat,2);
	}
	else if(m == n) {               // LOGIC FOR SQUARE MATRIX
		if(count < n)              // count = number of pivots   
		{
			int i, j, Pivotyes = 0, PivotNo = 0;
			for(i=0; i<m; i++) {
				if(Zero_Row_Indicator(m, n, mat, i) == 1 && mat[i][n] == 0){
					Pivotyes++;
				}
				if(Zero_Row_Indicator(m, n, mat, i) == 1 && mat[i][n] != 0){
					PivotNo++;
				}
			}
			printf("%d",Pivotyes);
			printf("%d",PivotNo);
			
			if(PivotNo >= 1) {
				printf("\n----------------------------------Solution Type------------------------------------\n"); 
				printf("\n   ------>>      System have NO SOLUTION...                                     \n");
		
				Back_Suptitution(m, n, mat,0);
			}
			else if(Pivotyes >= 1) {
				printf("\n----------------------------------Solution Type------------------------------------\n"); 
				printf("\n   ------>>      System have INFINITE SOLUTION...                                     \n");
		
				Back_Suptitution(m, n, mat,2);
			} 
			
		
		}
		else if(count == n)
		{
			printf("\n----------------------------------Solution Type------------------------------------\n"); 
			printf("\n   ------>>      System have Unique SOLUTION...                                     \n");
		
			Back_Suptitution(m,n,mat,1);       //CASE FOR UNIQUE SOLUTION
			
		}
	}
	else if(m > n){                         // LOGIC FOR TALL MATRIX
		int cnttall = 0;
		for(l = count; l<m; l++){
			if(mat[l][n] == 0){
				cnttall++;
			}
		}
		if(cnttall == m-count){
			printf("\n----------------------------------Solution Type------------------------------------\n"); 
			printf("\n   ------>>      System have Unique SOLUTION...                                     \n");
		
			Back_Suptitution(m, n, mat,1);
			
		}
		else{
			printf("\n----------------------------------Solution Type------------------------------------\n"); 
			printf("\n   ------>>      System have NO SOLUTION...                                     \n");
			Back_Suptitution(m, n, mat,0);
		}			
	} 
}

