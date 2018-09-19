#include "glmc.h"

inline void glmc_mat3f_inverse(mat3f dest, mat3f src)
{
	float det = glmc_mat3f_determinant(src);
	
	dest[0][0] =  1*( src[1][1]*src[2][2] - src[1][2]*src[2][1] )/det;
	dest[1][0] = -1*( src[0][1]*src[2][2] - src[0][2]*src[2][1] )/det;
	dest[2][0] =  1*( src[0][1]*src[1][2] - src[0][2]*src[1][1] )/det;

	dest[0][1] = -1*( src[1][0]*src[2][2] - src[1][2]*src[2][0] )/det;
	dest[1][1] =  1*( src[0][0]*src[2][2] - src[0][2]*src[2][0] )/det;
	dest[2][1] = -1*( src[0][0]*src[1][2] - src[0][2]*src[1][0] )/det;

	dest[0][2] =  1*( src[1][0]*src[2][1] - src[1][1]*src[2][0] )/det;
	dest[1][2] = -1*( src[0][0]*src[2][1] - src[0][1]*src[2][0] )/det;
	dest[2][2] =  1*( src[0][0]*src[1][1] - src[0][1]*src[1][0] )/det;
}

inline float glmc_mat3f_determinant(mat3f src);
{
	return ( ( src[0][0]*(src[1][1]*src[2][2] - src[2][1]*src[1][2] ) ) - (( src[1][0]*(src[0][1]*src[2][2] - src[2][1]*src[0][2] )) + (( src[2][0]*(src[0][1]*src[1][2] - src[0][2]*src[1][1] )) );
}

inline void glmc_mat3f_transpose(mat3f dest, mat3f src)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[0][2] = src[2][0];

	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
	dest[1][2] = src[2][1];

	dest[2][0] = src[0][2];
	dest[2][1] = src[1][2];
	dest[2][2] = src[2][2];
}

inline void glmc_mat3f_transpose_dest(mat3f src_dest)
{
	mat3f temp;
	
	temp[0][0] = src_dest[0][0];
	temp[1][0] = src_dest[1][0];
	temp[2][0] = src_dest[2][0];

	temp[0][1] = src_dest[0][1];
	temp[1][1] = src_dest[1][1];
	temp[2][1] = src_dest[2][1];

	temp[0][2] = src_dest[0][2];
	temp[1][2] = src_dest[1][2];
	temp[2][2] = src_dest[2][2];
	
	glmc_mat3f_transpose(src_dest, temp);
}

void glmc_mat3f_normlize(vec4f dest, vec4f src)
{
	
}

void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b)
{
	// dest = src_a + src_b
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[2][0] = src_a[2][0] + src_b[2][0];

	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	dest[2][1] = src_a[2][1] + src_b[2][1];

	dest[0][2] = src_a[0][2] + src_b[0][2];
	dest[1][2] = src_a[1][2] + src_b[1][2];
	dest[2][2] = src_a[2][2] + src_b[2][2];


}

void glmc_mat3f_add_dest(mat3f src_dest, mat3f src_b)
{
	// dest += src_a
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[1][0] = src_dest[1][0] + src_b[1][0];
	src_dest[2][0] = src_dest[2][0] + src_b[2][0];

	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
	src_dest[2][1] = src_dest[2][1] + src_b[2][1];

	src_dest[0][2] = src_dest[0][2] + src_b[0][2];
	src_dest[1][2] = src_dest[1][2] + src_b[1][2];
	src_dest[2][2] = src_dest[2][2] + src_b[2][2];
}

void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b)
{
	// dest = src_a - src_b
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[2][0] = src_a[2][0] - src_b[2][0];

	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	dest[2][1] = src_a[2][1] - src_b[2][1];

	dest[0][2] = src_a[0][2] - src_b[0][2];
	dest[1][2] = src_a[1][2] - src_b[1][2];
	dest[2][2] = src_a[2][2] - src_b[2][2];


}

void glmc_mat3f_sub_dest(mat3f src_dest, mat3f src_b)
{
	// dest -= src_a
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[1][0] = src_dest[1][0] - src_b[1][0];
	src_dest[2][0] = src_dest[2][0] - src_b[2][0];

	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
	src_dest[2][1] = src_dest[2][1] - src_b[2][1];

	src_dest[0][2] = src_dest[0][2] - src_b[0][2];
	src_dest[1][2] = src_dest[1][2] - src_b[1][2];
	src_dest[2][2] = src_dest[2][2] - src_b[2][2];
}

inline void glmc_mat3f_mul(mat3f dest, mat3f src_a , mat3f src_b)
{
	// dest = src_a * src_b

	dest[0][0] = ( src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] );
	dest[1][0] = ( src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] );
	dest[2][0] = ( src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] );

	dest[0][1] = ( src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] );
	dest[1][1] = ( src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] );
	dest[2][1] = ( src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] );

	dest[0][2] = ( src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] );
	dest[1][2] = ( src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] );
	dest[2][2] = ( src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] );
}

void glmc_mat3f_mul_dest(mat3f src_dest, mat3f src_b)
{
	mat3f temp;
	
	temp[0][0] = src_dest[0][0];
	temp[1][0] = src_dest[1][0];
	temp[2][0] = src_dest[2][0];

	temp[0][1] = src_dest[0][1];
	temp[1][1] = src_dest[1][1];
	temp[2][1] = src_dest[2][1];

	temp[0][2] = src_dest[0][2];
	temp[1][2] = src_dest[1][2];
	temp[2][2] = src_dest[2][2];
	
	glmc_mat3f_mul(src_dest, temp, src_b);
}

void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] * src_b;
	dest[1][0] = src_a[1][0] * src_b;
	dest[2][0] = src_a[2][0] * src_b;

	dest[0][1] = src_a[0][1] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	dest[2][1] = src_a[2][1] * src_b;

	dest[0][2] = src_a[0][2] * src_b;
	dest[1][2] = src_a[1][2] * src_b;
	dest[2][2] = src_a[2][2] * src_b;
}

void glmc_mat3f_mul_dest_s(mat3f src_dest, float src_b)
{
	src_dest[0][0] = src_dest[0][0] * src_b;
	src_dest[1][0] = src_dest[1][0] * src_b;
	src_dest[2][0] = src_dest[2][0] * src_b;

	src_dest[0][1] = src_dest[0][1] * src_b;
	src_dest[1][1] = src_dest[1][1] * src_b;
	src_dest[2][1] = src_dest[2][1] * src_b;

	src_dest[0][2] = src_dest[0][2] * src_b;
	src_dest[1][2] = src_dest[1][2] * src_b;
	src_dest[2][2] = src_dest[2][2] * src_b;
}

void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] / src_b;
	dest[1][0] = src_a[1][0] / src_b;
	dest[2][0] = src_a[2][0] / src_b;

	dest[0][1] = src_a[0][1] / src_b;
	dest[1][1] = src_a[1][1] / src_b;
	dest[2][1] = src_a[2][1] / src_b;

	dest[0][2] = src_a[0][2] / src_b;
	dest[1][2] = src_a[1][2] / src_b;
	dest[2][2] = src_a[2][2] / src_b;
}

void glmc_mat3f_div_dest_s(mat3f src_dest, float src_b)
{
	src_dest[0][0] = src_dest[0][0] / src_b;
	src_dest[1][0] = src_dest[1][0] / src_b;
	src_dest[2][0] = src_dest[2][0] / src_b;

	src_dest[0][1] = src_dest[0][1] / src_b;
	src_dest[1][1] = src_dest[1][1] / src_b;
	src_dest[2][1] = src_dest[2][1] / src_b;

	src_dest[0][2] = src_dest[0][2] / src_b;
	src_dest[1][2] = src_dest[1][2] / src_b;
	src_dest[2][2] = src_dest[2][2] / src_b;
}

inline void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = dest[0][0] + ( ( src_a[0][0]*src_b[0][0] ) + ( src_a[1][0]*src_b[0][1] ) + ( src_a[2][0]*src_b[0][2] )	 );
	dest[0][1] = dest[0][1] + ( ( src_a[0][1]*src_b[0][0] ) + ( src_a[1][1]*src_b[0][1] ) + ( src_a[2][1]*src_b[0][2] ) );
	dest[0][2] = dest[0][2] + ( ( src_a[0][2]*src_b[0][0] ) + ( src_a[1][2]*src_b[0][1] ) + ( src_a[2][2]*src_b[0][2] ) );

	dest[1][0] = dest[1][0] + ( ( src_a[0][0]*src_b[1][0] ) + ( src_a[1][0]*src_b[1][1] ) + ( src_a[2][0]*src_b[1][2] ) );
	dest[1][1] = dest[1][1] + ( ( src_a[0][1]*src_b[1][0] ) + ( src_a[1][1]*src_b[1][1] ) + ( src_a[2][1]*src_b[1][2] ) );
	dest[1][2] = dest[1][2] + ( ( src_a[0][2]*src_b[1][0] ) + ( src_a[1][2]*src_b[1][1] ) + ( src_a[2][2]*src_b[1][2] ) );

	dest[2][0] = dest[2][0] + ( ( src_a[0][0]*src_b[2][0] ) + ( src_a[1][0]*src_b[2][1] ) + ( src_a[2][0]*src_b[2][2] ) );
	dest[2][1] = dest[2][1] + ( ( src_a[0][1]*src_b[2][0] ) + ( src_a[1][1]*src_b[2][1] ) + ( src_a[2][1]*src_b[2][2] ) );
	dest[2][2] = dest[2][2] + ( ( src_a[0][2]*src_b[2][0] ) + ( src_a[1][2]*src_b[2][1] ) + ( src_a[2][2]*src_b[2][2] ) );
}
inline void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = dest[0][0] - ( ( src_a[0][0]*src_b[0][0] ) + ( src_a[1][0]*src_b[0][1] ) + ( src_a[2][0]*src_b[0][2] ) );
	dest[0][1] = dest[0][1] - ( ( src_a[0][1]*src_b[0][0] ) + ( src_a[1][1]*src_b[0][1] ) + ( src_a[2][1]*src_b[0][2] ) );
	dest[0][2] = dest[0][2] - ( ( src_a[0][2]*src_b[0][0] ) + ( src_a[1][2]*src_b[0][1] ) + ( src_a[2][2]*src_b[0][2] ) );

	dest[1][0] = dest[1][0] - ( ( src_a[0][0]*src_b[1][0] ) + ( src_a[1][0]*src_b[1][1] ) + ( src_a[2][0]*src_b[1][2] ) );
	dest[1][1] = dest[1][1] - ( ( src_a[0][1]*src_b[1][0] ) + ( src_a[1][1]*src_b[1][1] ) + ( src_a[2][1]*src_b[1][2] ) );
	dest[1][2] = dest[1][2] - ( ( src_a[0][2]*src_b[1][0] ) + ( src_a[1][2]*src_b[1][1] ) + ( src_a[2][2]*src_b[1][2] ) );

	dest[2][0] = dest[2][0] - ( ( src_a[0][0]*src_b[2][0] ) + ( src_a[1][0]*src_b[2][1] ) + ( src_a[2][0]*src_b[2][2] ) );
	dest[2][1] = dest[2][1] - ( ( src_a[0][1]*src_b[2][0] ) + ( src_a[1][1]*src_b[2][1] ) + ( src_a[2][1]*src_b[2][2] ) );
	dest[2][2] = dest[2][2] - ( ( src_a[0][2]*src_b[2][0] ) + ( src_a[1][2]*src_b[2][1] ) + ( src_a[2][2]*src_b[2][2] ) );
}