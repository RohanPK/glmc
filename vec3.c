/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

//Since float is rounded down
#define MIN_FLOAT_ERROR 1.0e-7

void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b)
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_b;
}

void glmc_vec3f_from_4f(vec3f dest, vec4f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];

}

void glmc_vec3f_copy(vec3f dest, vec3f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

float glmc_vec3f_sqrlength(vec3f vec)
{
	float result=0;

	result = result + (vec[0]*vec[0]);
	result = result + (vec[1]*vec[1]);
	result = result + (vec[2]*vec[2]);

	return result;
}

float glmc_vec3f_length(vec3f vec)
{
	return sqrt(glmc_vec3f_sqrlength(vec));
}

int  glmc_vec3f_is_normalized(vec3f src)
{
	//Check if length lies between  1-1.0e-7and 1 as sqrt may result in loss of precesion 
	
	int flag_normal=0;
	
	if( glmc_vec3f_length(src) >= (1-MIN_FLOAT_ERROR) && glmc_vec3f_length(src) <= 1  )
	{
		flag_normal = 1;
	}
	
	return flag_normal;
}

void glmc_vec3f_normlize(vec3f dest, vec3f src)
{
	if( glmc_vec3f_is_normalized(src) == 1 )
	{
		glmc_vec3f_copy(dest,src);
	}
	else
	{
		float denom_vec = glmc_vec3f_length(src);
		dest[0] = (src[0]/denom_vec);
		dest[1] = (src[1]/denom_vec);
		dest[2] = (src[2]/denom_vec);
	}
}

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b)
{
	// dest = src_a + src_b
	dest[0] = src_a[0] + src_b[0];
	dest[1] = src_a[1] + src_b[1];
	dest[2] = src_a[2] + src_b[2];

}

void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_a)
{
	// dest += src_a
	src_dest[0] = src_dest[0] + src_a[0];
	src_dest[1] = src_dest[1] + src_a[1];
	src_dest[2] = src_dest[2] + src_a[2];
}

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b)
{
	// dest = src_a - src_b
	dest[0] = src_a[0] - src_b[0];
	dest[1] = src_a[1] - src_b[1];
	dest[2] = src_a[2] - src_b[2];
}

void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_a)
{
	// dest -= src_a
	src_dest[0] = src_dest[0] - src_a[0];
	src_dest[1] = src_dest[1] - src_a[1];
	src_dest[2] = src_dest[2] - src_a[2];
}

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b) 
{
	// dest = src_a * src_b
	dest[0] = src_a[0] * src_b[0];
	dest[1] = src_a[1] * src_b[1];
	dest[2] = src_a[2] * src_b[2];
}

void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_a)
{
	// dest *= src_a
	src_dest[0] = src_dest[0] * src_a[0];
	src_dest[1] = src_dest[1] * src_a[1];
	src_dest[2] = src_dest[2] * src_a[2];

}

void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b)
{
	// dest = src_a * scalar
	dest[0] = src_a[0] * src_b;
	dest[1] = src_a[1] * src_b;
	dest[2] = src_a[2] * src_b;
}

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b)
{
	// dest = src_a / src_b
	//Avoid division by zero
	assert(src_b[0] != 0);
	assert(src_b[1] != 0);
	assert(src_b[2] != 0);

	dest[0] = src_a[0] / src_b[0];
	dest[1] = src_a[1] / src_b[1];
	dest[2] = src_a[2] / src_b[2];

}

void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b)
{
	// dest /= src_a;
	glmc_vec3f_div(src_dest,src_dest,src_b);
}

void glmc_vec3f_div_s(vec3f dest, float src_b) 
{
	// dest = src_a / scalar
	assert(src_b != 0.0f);
	dest[0] = dest[0] / src_b;
	dest[1] = dest[1] / src_b;
	dest[2] = dest[2] / src_b;
}

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b)
{
	// dest += src_a + src_b;
	dest[0] = dest[0] + src_a[0] + src_b[0];
	dest[1] = dest[1] + src_a[1] + src_b[1];
	dest[2] = dest[2] + src_a[2] + src_b[2];

}

void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b)
{
	// dest += src_a - src_b;
	dest[0] = dest[0] + src_a[0] - src_b[0];
	dest[1] = dest[1] + src_a[1] - src_b[1];
	dest[2] = dest[2] + src_a[2] - src_b[2];
}

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b)
{
	// dest += src_a * src_b
	dest[0] = dest[0] + (src_a[0] * src_b[0]);
	dest[1] = dest[1] + (src_a[1] * src_b[1]);
	dest[2] = dest[2] + (src_a[2] * src_b[2]);
}

void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b)
{
	//dest -= src_a * src_b
	dest[0] = dest[0] - (src_a[0] * src_b[0]);
	dest[1] = dest[1] - (src_a[1] * src_b[1]);
	dest[2] = dest[2] - (src_a[2] * src_b[2]);
}

float glmc_vec3f_dot(vec3f src_a, vec3f src_b)
{
	//sum(src_a[i]*src_b[i])
	float result=0;
	result = result + (src_a[0] * src_b[0]);
	result = result + (src_a[1] * src_b[1]);
	result = result + (src_a[2] * src_b[2]);
	return result;
}

void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b)
{
	//det({i,j,k},{src_a},{src_b})
	dest[0]=src_a[1]*src_b[2]-src_a[2]*src_b[1];
	dest[1]=src_a[2]*src_b[0]-src_a[0]*src_b[2];
	dest[2]=src_a[0]*src_b[1]-src_a[1]*src_b[0];
}

inline void glmc_vec3f_reflection(vec3f dest, vec3f src, vec3f norm)
{
	glmc_vec3f_normlize(norm, norm);
	float src_dot_norm = glmc_vec3f_dot(src,norm);
	vec3f scalar_n;
	
	glmc_vec3f_mul_s(scalar_n, norm, 2*src_dot_norm);
	glmc_vec3f_sub(dest,src,scalar_n);
}

inline void glmc_vec3f_refraction(vec3f dest, vec3f src, vec3f norm, float mu)
{
	vec3f src_cross_norm;
	vec3f norm_cross_src_cross_norm;
	vec3f coeff_dot_norm;
	float norm_vector_coeff;
	
	glmc_vec3f_cross(src_cross_norm, src,norm);
	glmc_vec3f_cross(norm_cross_src_cross_norm, norm,src_cross_norm);
	norm_vector_coeff = sqrt( (1- (1/(mu*mu))*(glmc_vec3f_dot(src_cross_norm, src_cross_norm)))  );
	glmc_vec3f_div_s(norm_cross_src_cross_norm, mu);
	glmc_vec3f_mul_s(coeff_dot_norm, norm, norm_vector_coeff);
	
	glmc_vec3f_sub(dest, norm_cross_src_cross_norm, coeff_dot_norm);
}
