#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void Null_Finder(int m,int n,float mat[m][n+1])
{
	int i,count=0,j=0,k=0,l=0,s=0;
	int min;
	if(m < n) {
		min = m;
	} else {
		min = n;
	}
	for(i=0;i<min;i++)
	{
		if(mat[i][i]!=0)
		{
			count++;
		}
	}
	
	int rawzero=0;
	//int l=0;
	int pivot=0;
	//int min = 0;          // m = #rows
	if(n > m) {			  // n = #columns
		min = m;
	} else {
		min = n;
	}
	for(l=0;l<m;l++)
	{
		if(Zero_Row_Indicator(m,n,mat,l) == 1)
		{
			rawzero++;
		}
	}
	float new_mat[m-rawzero][n];
	
	int z=0;
	for(l=0;l<m;l++)
	{
		if(Zero_Row_Indicator(m,n,mat,l) == 0)
		{
			for(j=0;j<n;j++)
			{
				new_mat[z][j] = mat[l][j];
			}
			
			z++;
			
		}
	
	}
	
	int *swap_store = (int *) calloc(n,sizeof(int));
	float temp=0;
	int cnt=0;
	for(i=0; i<n-1; i++)
	{
		for(j=i; j<m-rawzero; j++)
		{
			if(new_mat[j][i]==0){
				cnt++;
			}
		}
		if(cnt==m-rawzero-i){
			int p = i;
			while(p<n){
				int next_col = p+1;
				if(cnt==m-rawzero-i && new_mat[i][next_col]!=0)
				{
					for(k=0; k<m-rawzero; k++)
					{
						temp = new_mat[k][i];
						new_mat[k][i] = new_mat[k][next_col];
						new_mat[k][next_col] = temp;
					}
						swap_store[i] = next_col;
						swap_store[next_col] = i;
						break;
				}
				else{
					p++;
				}
			}
		}
		
		cnt = 0;
	}
	printf("Matrix\n");
	/*for(i=0;i<m-rawzero;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%.2f  ",new_mat[i][j]);
		}
		printf("\n");
	}*/
	float F[m-rawzero][n-m+rawzero];
	int r=0,c=0;
	
	for(i=0;i<m-rawzero;i++)
	{
		c=0;
		for(j=count;j<n;j++)
		{
			F[i][c] = -new_mat[i][j];
			//printf("%.2f ",F[i][c]);
			
				c++;
			
		}
		printf("\n");
		
	}
	printf("\n---------------------------------- NULL SPACE ------------------------------------\n"); 
	
		
	
	//printf("\n\n I matrix : ");
	float I[c][c];
	
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i==j)
			{
				I[i][j] =1;
				
			}
			else
			{
				I[i][j] = 0;
			}
		}
	}
	if((m - rawzero) == n)
	{
		for(i =0;i<n;i++)
		{
			printf("\t0.00\t\n");
		}
		
		
	}
	else{
		for(i=0;i<m-rawzero;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("\t%.2f\t",F[i][j]);
			}
			printf("\n");
		}
		for(i=0;i<c;i++)
		{
			if(i < (m-rawzero))
			{
				for(j=0;j<c;j++)
					{
						printf("\t%.2f\t",I[i][j]);
					}
					printf("\n");
			}
			
		}
	}
	
	
	float null[n][n-m+rawzero];
	int check_I = 0;
	int a=0,b=0;
	for(i =0;i<n;i++)
	{
		for(j=0;j<n-m+rawzero;j++)
		{
			if(i < m-rawzero)
			{
				null[i][j] = F[i][j];
			}
			else
			{
				null[i][j] = I[a][b];
				b++;
				check_I++;
			}
		}
		if(check_I != 0)
		{
			i++;	
		}
		
	}
	
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n-m+rawzero;j++)
		{
			printf("\t%.2f\t",null[i][j]);
		}
		printf("\n");
	}*/
	printf("\n--------------------------------------------------------------------------------------------\n"); 
}
