#include<stdio.h>
#include<math.h>

void Print_Matrix(int m,int n,float mat[][n+1])
{
    int i,j;  
    printf("\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j <= n; j++)
        {
        	if(j==n){printf("|");}
            printf("%0.2f\t",mat[i][j]);            
        }
        printf("\n");
    }   
}
