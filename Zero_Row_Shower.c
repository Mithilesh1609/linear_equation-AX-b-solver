#include<stdio.h>
#include<math.h>

int Zero_Row_Shower(int a, int b, int mat[a][b+1], int Index_of_row) {

	int i, count = 0;

	for(i=0; i<b; i++){

		if(mat[Index_of_row][i] == 0 || mat[Index_of_row][i] == (float)(-0)) {

			count=count+1;

		}

	}

	if(count == b){

		return 1;

	}

	else {

		return 0;

	}

}
