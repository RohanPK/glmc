#include "glmc.h"

inline void glmc_mat2f_scan(mat2f dest)
{
	scanf("%f",&dest[0][0]);
	scanf("%f",&dest[1][0]);
	scanf("%f",&dest[0][1]);
	scanf("%f",&dest[1][1]);

	#ifdef NORMALISE 
		glmc_mat2f_normlize_dest(dest);
	#endif
}

inline float glmc_mat2f_determinant(mat2f mat)
{
	return (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);
}

inline void glmc_mat2f_inverse(mat2f dest, mat2f src)
{
	float mat_det;
	mat_det = glmc_mat2f_determinant(src);

	dest[0][0] =  1.0f*(src[1][1])/mat_det;
	dest[0][1] = -1.0f*(src[0][1])/mat_det;

	dest[1][0] = -1.0f*(src[1][0])/mat_det;
	dest[1][1] =  1.0f*(src[0][0])/mat_det;
}

inline void glmc_mat2f_transpose_dest(mat2f src_dest)
{
	mat2f temp;

	temp[0][0] = src_dest[0][0];
	temp[1][0] = src_dest[1][0];

	temp[0][1] = src_dest[0][1];
	temp[1][1] = src_dest[1][1];

	src_dest[0][0] = temp[0][0];
	src_dest[0][1] = temp[1][0];

	src_dest[1][0] = temp[0][1];
	src_dest[1][1] = temp[1][1];
}
inline void glmc_mat2f_transpose(mat2f dest, mat2f src)
{
	
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];

	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];

}


inline void glmc_mat2f_normlize(mat2f dest, mat2f src)
{
	float mat2f_det_inv;
	mat2f_det_inv = 1.0f/(glmc_mat2f_determinant(src));

	dest[0][0] = src[0][0]*mat2f_det_inv;
	dest[0][1] = src[0][1]*mat2f_det_inv;

	dest[1][0] = src[1][0]*mat2f_det_inv;
	dest[1][1] = src[1][1]*mat2f_det_inv;
}
inline void glmc_mat2f_normlize_dest(mat2f src_dest)
{
	float mat2f_det_inv;
	mat2f_det_inv = 1.0f/(glmc_mat2f_determinant(src_dest));

	src_dest[0][0] = src_dest[0][0]*mat2f_det_inv;
	src_dest[0][1] = src_dest[0][1]*mat2f_det_inv;

	src_dest[1][0] = src_dest[1][0]*mat2f_det_inv;
	src_dest[1][1] = src_dest[1][1]*mat2f_det_inv;
}


void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b)
{
	// dest = src_a + src_b
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[1][0] = src_a[1][0] + src_b[1][0];

	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[1][1] = src_a[1][1] + src_b[1][1];

}

void glmc_mat2f_add_dest(mat2f src_dest, mat2f src_b)
{
	// dest += src_a
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[1][0] = src_dest[1][0] + src_b[1][0];

	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
}

void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b)
{
	// dest = src_a - src_b
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[1][0] = src_a[1][0] - src_b[1][0];

	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[1][1] = src_a[1][1] - src_b[1][1];
}

void glmc_mat2f_sub_dest(mat2f src_dest, mat2f src_b)
{
	// dest -= src_a
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[1][0] = src_dest[1][0] - src_b[1][0];

	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
}

inline void glmc_mat2f_mul(mat2f dest, mat2f src_a , mat2f src_b)
{
	// dest = src_a * src_b

	dest[0][0] = ( src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] );
	dest[1][0] = ( src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] );

	dest[0][1] = ( src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] );
	dest[1][1] = ( src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] );

}

void glmc_mat2f_mul_dest(mat2f src_dest, mat2f src_b)
{
	mat2f temp;
	
	temp[0][0] = src_dest[0][0];
	temp[1][0] = src_dest[1][0];

	temp[0][1] = src_dest[0][1];
	temp[1][1] = src_dest[1][1];
	
	glmc_mat2f_mul(src_dest, temp, src_b);
}

void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] * src_b;
	dest[1][0] = src_a[1][0] * src_b;

	dest[0][1] = src_a[0][1] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
}

void glmc_mat2f_mul_dest_s(mat2f src_dest, float src_b)
{
	src_dest[0][0] = src_dest[0][0] * src_b;
	src_dest[1][0] = src_dest[1][0] * src_b;

	src_dest[0][1] = src_dest[0][1] * src_b;
	src_dest[1][1] = src_dest[1][1] * src_b;
}

void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] / src_b;
	dest[1][0] = src_a[1][0] / src_b;

	dest[0][1] = src_a[0][1] / src_b;
	dest[1][1] = src_a[1][1] / src_b;
}

void glmc_mat2f_div_dest_s(mat2f src_dest, float src_b)
{
	src_dest[0][0] = src_dest[0][0] / src_b;
	src_dest[1][0] = src_dest[1][0] / src_b;

	src_dest[0][1] = src_dest[0][1] / src_b;
	src_dest[1][1] = src_dest[1][1] / src_b;
}

inline void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b)
{
	dest[0][0] = dest[0][0] + ( ( src_a[0][0]*src_b[0][0] ) + ( src_a[1][0]*src_b[0][1] ) + ( src_a[2][0]*src_b[0][2] )	 );
	dest[0][1] = dest[0][1] + ( ( src_a[0][1]*src_b[0][0] ) + ( src_a[1][1]*src_b[0][1] ) + ( src_a[2][1]*src_b[0][2] ) );

	dest[1][0] = dest[1][0] + ( ( src_a[0][0]*src_b[1][0] ) + ( src_a[1][0]*src_b[1][1] ) + ( src_a[2][0]*src_b[1][2] ) );
	dest[1][1] = dest[1][1] + ( ( src_a[0][1]*src_b[1][0] ) + ( src_a[1][1]*src_b[1][1] ) + ( src_a[2][1]*src_b[1][2] ) );

}

inline void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b)
{
	dest[0][0] = dest[0][0] - ( ( src_a[0][0]*src_b[0][0] ) + ( src_a[1][0]*src_b[0][1] ) + ( src_a[2][0]*src_b[0][2] ) );
	dest[0][1] = dest[0][1] - ( ( src_a[0][1]*src_b[0][0] ) + ( src_a[1][1]*src_b[0][1] ) + ( src_a[2][1]*src_b[0][2] ) );

	dest[1][0] = dest[1][0] - ( ( src_a[0][0]*src_b[1][0] ) + ( src_a[1][0]*src_b[1][1] ) + ( src_a[2][0]*src_b[1][2] ) );
	dest[1][1] = dest[1][1] - ( ( src_a[0][1]*src_b[1][0] ) + ( src_a[1][1]*src_b[1][1] ) + ( src_a[2][1]*src_b[1][2] ) );
}

inline void glmc_mat2f_mul_vec2f(vec2f dest, mat2f src_a, vec2f src_b)
{
	dest[0] = src_a[0][0]*src_b[0] + src_a[1][0]*src_b[1];
	dest[1] = src_a[0][1]*src_b[0] + src_a[1][1]*src_b[1];
}

inline void glmc_mat2f_scale(mat2f dest, float src_x)
{
	dest[0][0] = src_x;
	dest[0][1] = 0;

	dest[1][0] = 0;
	dest[1][1] = 1;
}

inline void glmc_mat2f_translation(mat2f dest, float src_x)
{
	dest[0][0] = 1.0f;
	dest[0][1] = 0;

	dest[2][0] = src_x;
	dest[2][1] = 1.0f;
}

void glmc_mat2f_to_glsl2f(glsl2f dest, mat2f src)
{
	dest[0] = src[0][0];
	dest[1] = src[1][0];

	dest[2] = src[0][1];
	dest[3] = src[1][1];

}
void glmc_glsl2f_to_mat2f(mat2f dest, glsl2f src)
{
	dest[0][0] = src[0];
	dest[1][0] = src[1];

	dest[0][1] = src[2];
	dest[1][1] = src[3];
}
