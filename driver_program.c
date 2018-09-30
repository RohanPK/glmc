#include <stdio.h>
#include "glmc.h"

void print_vec_2f(vec2f vec, int precision)
{
	for(int i = 0; i<2; i++)
	{
		printf("%8.*f ",precision, vec[i]);
		printf("\n");
	}
	printf("\n");
}
void print_vec_3f(vec3f vec, int precision)
{
	for(int i = 0; i<3; i++)
	{
		printf("%8.*f ",precision, vec[i]);
		printf("\n");
	}
	printf("\n");
}
void print_vec_4f(vec4f vec, int precision)
{
	for(int i = 0; i<4; i++)
	{
		printf("%8.*f ",precision, vec[i]);
		printf("\n");
	}
	printf("\n");
}

void print_mat_2f(mat2f mat, int precision)
{
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<2; j++)
		{
			printf("%8.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}
void print_mat_3f(mat3f mat, int precision)
{
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			printf("%8.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}
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

void assign_mat3f(mat3f expected_output, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
{
	expected_output[0][0] = a1;
	expected_output[0][1] = a2;
	expected_output[0][2] = a3;

	expected_output[1][0] = a4;
	expected_output[1][1] = a5;
	expected_output[1][2] = a6;

	expected_output[2][0] = a7;
	expected_output[2][1] = a8;
	expected_output[2][2] = a9;

}

void reset_a3(mat3f A3)
{
	A3[0][0] = 1;
	A3[0][1] = 4;
	A3[0][2] = 7;

	A3[1][0] = 2;
	A3[1][1] = 5;
	A3[1][2] = 8;

	A3[2][0] = 3;
	A3[2][1] = 6;
	A3[2][2] = 10;
}

void check_mat3f(mat3f ans, mat3f expected_output, char function[])
{
	int flag = 0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(ans[i][j]!=expected_output[i][j])
			{
				flag=1;
			}
		}
	}
	if( flag == 1 )
	{
		printf("%s FAILED \nResult:\n",function);
		print_mat_3f(ans,4);
		printf("Expected Output:\n");
		print_mat_3f(expected_output,4);
	}
	else
	{
		printf("%s PASSED\n",function);
	}
}

int main(int arg, char **argc)
{

	mat3f A3 = {{1,4,7}, {2,5,8}, {3,6,10}};
	mat3f B3 = {{2,5,8}, {3,6,9}, {4,7,9}};
	mat3f dest;
	mat3f expected_output;

	glmc_mat3f_add(dest,A3,B3);
	assign_mat3f(expected_output,3,9,15,5,11,17,7,13,19);
	check_mat3f(dest,expected_output,"Mat3f Add");

	glmc_mat3f_add_dest(A3,B3);
	assign_mat3f(expected_output,3,9,15,5,11,17,7,13,19);
	check_mat3f(A3,expected_output,"Mat3f Add-Dest");
	reset_a3(A3);

	glmc_mat3f_sub(dest,A3,B3);
	assign_mat3f(expected_output,-1,-1,-1,-1,-1,-1,-1,-1,1);
	check_mat3f(dest,expected_output,"Mat3f Sub");
	
	glmc_mat3f_sub_dest(A3,B3);
	assign_mat3f(expected_output,-1,-1,-1,-1,-1,-1,-1,-1,1);
	check_mat3f(A3,expected_output,"Mat3f Sub-Dest");
	reset_a3(A3);

	glmc_mat3f_mul(dest,A3,B3);
	assign_mat3f(expected_output,36,81,134,42,96,159,45,105,174);
	check_mat3f(dest,expected_output,"Mat3f Mul");

	glmc_mat3f_mul_dest(A3,B3);
	assign_mat3f(expected_output,36,81,134,42,96,159,45,105,174);
	check_mat3f(A3,expected_output,"Mat3f Mul-Dest");
	reset_a3(A3);

	glmc_mat3f_mul_s(dest,A3,2);
	assign_mat3f(expected_output,2,8,14,4,10,16,6,12,20);
	check_mat3f(dest,expected_output,"Mat3f Mul-Scalar");

	glmc_mat3f_inverse(dest,A3);
	assign_mat3f(expected_output,-2/3,-2/3,1,-4/3,11/3,-2,1,-2,1);
	check_mat3f(A3,expected_output,"Mat3f Inverse");
	reset_a3(A3);

	glmc_mat3f_div(dest,A3,B3);
	assign_mat3f(expected_output,4/3,1/3,-5/3,-1/3,2/3,11/3,0,0,-1);
	check_mat3f(A3,expected_output,"Mat3f Div");
	reset_a3(A3);
	return 0;
}