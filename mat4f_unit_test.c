#include <stdio.h>
#include <math.h>
#include "glmc.h"

void print_mat_4f(mat4f mat, int precision)
{
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			printf("%8.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}


void assign_mat4f(mat4f expected_output, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, float a13, float a14, float a15, float a16)
{
	expected_output[0][0] = a1;
	expected_output[0][1] = a2;
	expected_output[0][2] = a3;
	expected_output[0][3] = a4;

	expected_output[1][0] = a5;
	expected_output[1][1] = a6;
	expected_output[1][2] = a7;
	expected_output[1][3] = a8;

	expected_output[2][0] = a9;
	expected_output[2][1] = a10;
	expected_output[2][2] = a11;
	expected_output[2][3] = a12;

	expected_output[3][0] = a13;
	expected_output[3][1] = a14;
	expected_output[3][2] = a15;
	expected_output[3][3] = a16;

}

void reset_a4(mat4f A4)
{
	A4[0][0] = 2;
	A4[0][1] = 2;
	A4[0][2] = 3;
	A4[0][3] = 4;

	A4[1][0] = 5;
	A4[1][1] = 6;
	A4[1][2] = 7;
	A4[1][3] = 8;

	A4[2][0] = 9;
	A4[2][1] = 10;
	A4[2][2] = 11;
	A4[2][3] = 12;

	A4[3][0] = 13;
	A4[3][1] = 14;
	A4[3][2] = 15;
	A4[3][3] = 15;

}

void check_mat4f(mat4f ans, mat4f expected_output, char function[])
{
	int flag = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(ans[i][j]-expected_output[i][j]>=0.001)
			{
				flag=1;
			}
		}
	}
	if( flag == 1 )
	{
		printf("%s FAILED \nResult:\n",function);
		print_mat_4f(ans,4);
		printf("Expected Output:\n");
		print_mat_4f(expected_output,4);
	}
	else
	{
		printf("%s PASSED\n",function);
	}
}
void unit_test_case_mat4f()
{
	mat4f A4;
	reset_a4(A4);
	mat4f B4;
	reset_a4(B4);
	mat4f dest;
	mat4f expected_output;

	glmc_mat4f_add(dest,A4,B4);
	assign_mat4f(expected_output,4,4,6,8,10,12,14,16,18,20,22,24,26,28,30,30);
	check_mat4f(dest,expected_output,"Mat4f Add");

	glmc_mat4f_add_dest(A4,B4);
	assign_mat4f(expected_output,4,4,6,8,10,12,14,16,18,20,22,24,26,28,30,30);
	check_mat4f(A4,expected_output,"Mat4f Add-Dest");
	reset_a4(A4);

	glmc_mat4f_sub(dest,A4,B4);
	assign_mat4f(expected_output,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	check_mat4f(dest,expected_output,"Mat4f Sub");
	
	glmc_mat4f_sub_dest(A4,B4);
	assign_mat4f(expected_output,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	check_mat4f(A4,expected_output,"Mat4f Sub-Dest");
	reset_a4(A4);

	glmc_mat4f_mul(dest,A4,B4);
	assign_mat4f(expected_output,93,102,113,120,207,228,254,272,323,356,398,428,426,470,527,569);
	check_mat4f(dest,expected_output,"Mat4f Mul");

	glmc_mat4f_mul_dest(A4,B4);
	assign_mat4f(expected_output,93,102,113,120,207,228,254,272,323,356,398,428,426,470,527,569);
	check_mat4f(A4,expected_output,"Mat4f Mul-Dest");
	reset_a4(A4);

	glmc_mat4f_mul_s(dest,A4,2);
	assign_mat4f(expected_output,4,4,6,8,10,12,14,16,18,20,22,24,26,28,30,30);
	check_mat4f(dest,expected_output,"Mat4f Mul-Scalar");

	glmc_mat4f_inverse(dest,A4);
	assign_mat4f(expected_output,1.0,-2.0,1.0,0.0,-2.0,1/4.0,7/4.0,-1.0,1,5/2.0,-9/2,2.0,0,-1,2,-1);
	check_mat4f(dest,expected_output,"Mat4f Inverse");
	reset_a4(A4);

	glmc_mat4f_div(dest,A4,B4);
	assign_mat4f(expected_output,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	check_mat4f(dest,expected_output,"Mat4f Div");
	reset_a4(A4);

	glmc_mat4f_div_dest(A4,B4);
	assign_mat4f(expected_output,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	check_mat4f(A4,expected_output,"Mat4f Div-Dest");
	reset_a4(A4);

	glmc_mat4f_div_s(dest,A4,1);
	assign_mat4f(expected_output,2,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15);
	check_mat4f(dest,expected_output,"Mat4f Div-Scalar");

	glmc_mat4f_transpose(dest,A4);
	assign_mat4f(expected_output,2,5,9,13,2,6,10,14,3,7,11,15,4,8,12,15);
	check_mat4f(dest,expected_output,"Mat4f Transpose-Dest");

	glmc_mat4f_transpose_dest(A4);
	assign_mat4f(expected_output,2,5,9,13,2,6,10,14,3,7,11,15,4,8,12,15);
	check_mat4f(dest,expected_output,"Mat4f Transpose-Dest");
	reset_a4(A4);

	glmc_mat4f_normlize(dest,A4);
	assign_mat4f(expected_output,2/4.0,2/4.0,3/4.0,4/4.0,5/4.0,6/4.0,7/4.0,8/4.0,9/4.0,10/4.0,11/4.0,12/4.0,13/4.0,14/4.0,15/4.0,15/4.0);
	check_mat4f(dest,expected_output,"Mat4f Normalize");

	glmc_mat4f_normlize_dest(A4);
	assign_mat4f(expected_output,2/4.0,2/4.0,3/4.0,4/4.0,5/4.0,6/4.0,7/4.0,8/4.0,9/4.0,10/4.0,11/4.0,12/4.0,13/4.0,14/4.0,15/4.0,15/4.0);
	check_mat4f(A4,expected_output,"Mat4f Normalize-Dest");
	reset_a4(A4);

	glmc_mat4f_scale(A4,2,3,4);
	assign_mat4f(expected_output,2,0,0,0,0,3,0,0,0,0,4,0,0,0,0,1	);
	check_mat4f(A4,expected_output,"Mat4f Scale");

	glmc_mat4f_translation(A4,2,3,4);
	assign_mat4f(expected_output,1,0,0,0,0,1,0,0,0,0,1,0,2,3,4,1);
	check_mat4f(A4,expected_output,"Mat4f Translation");

	glmc_mat4f_rotation(A4, 1, 2, 3, 3.1415);
	assign_mat4f(expected_output,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	check_mat4f(A4,expected_output,"Mat4f Rotation");

	printf("\n\n\n");
}

int main(int arg, char **argc)
{

	unit_test_case_mat4f();
	return 0;
}

