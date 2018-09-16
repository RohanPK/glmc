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

void glmc_vec2f_from_3f(vec2f dest, vec3f src_a)
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];
}

void glmc_vec2f_from_4f(vec2f dest, vec4f src)
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];	
}

void glmc_vec2f_copy(vec2f dest, vec2f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
}

float glmc_vec2f_sqrlength(vec2f vec)
{
	float result=0;
	for(int i = 0; i < 2; i++)
	{
		result = result + (vec[i]*vec[i]);
	}
	return result;
}

float glmc_vec2f_length(vec2f vec)
{
	float result = glmc_vec2f_sqrlength(vec);
	result = sqrt(result);
	return result;
}

int  glmc_vec2f_is_normalized(vec2f src)
{
	//Check if length lies between  1-1.0e-7and 1 as sqrt may result in loss of precesion 
	
	int flag_normal=0;
	
	if( glmc_vec2f_length(src) >= (1-MIN_FLOAT_ERROR) && glmc_vec2f_length(src) <= 1  )
	{
		flag_normal = 1;
	}
	
	return flag_normal;
}

void glmc_vec2f_normlize(vec2f dest, vec2f src)
{
	if( glmc_vec2f_is_normalized(src) == 1 )
	{
		glmc_vec2f_copy(dest,src);
	}
	else
	{
		float denom_vec = glmc_vec2f_length(src);
		for(int i = 0; i < 2; i++)
		{
			dest[i] = (src[i]/denom_vec);
		}
	}
}

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b)
{
	// dest = src_a + src_b
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] + src_b[i];
	}
}

void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_a)
{
	// dest += src_a
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] = src_dest[i] + src_a[i];
	}
}

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b)
{
	// dest = src_a - src_b
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] - src_b[i];
	}
}

void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_a)
{
	// dest -= src_a
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] = src_dest[i] - src_a[i];
	}
}

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b) 
{
	// dest = src_a * src_b
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] * src_b[i];
	}
}

void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_a)
{
	// dest *= src_a
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] = src_dest[i] * src_a[i];
	}
}

void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b)
{
	// dest = src_a * scalar
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] * src_b;
	}
}

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b)
{
	// dest = src_a / src_b
	for(int i = 0; i < 2; i++)
	{
		assert(src_b[i] != 0);
		dest[i] = src_a[i] / src_b[i];
	}
}

void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b)
{
	// dest /= src_a;
	for(int i = 0; i < 2; i++)
	{
		assert(src_b[i] != 0);
		src_dest[i] = src_dest[i] / src_b[i];
	}
}

void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b) 
{
	// dest = src_a / scalar
	for(int i = 0; i < 2; i++)
	{
		assert(src_b != 0.0f);
		dest[i] = dest[i] / src_b;
	}
}

void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b)
{
	// dest += src_a + src_b;
	for(int i = 0; i < 2; i++)
	{
		dest[i] = dest[i] + src_a[i] + src_b[i];
	}
}

void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b)
{
	// dest += src_a - src_b;
	for(int i = 0; i < 2; i++)
	{
		dest[i] = dest[i] + src_a[i] - src_b[i];
	}
}

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b)
{
	// dest += src_a * src_b
	for(int i = 0; i < 2; i++)
		{
			dest[i] = dest[i] + (src_a[i] * src_b[i]);
		}
}

void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b)
{
	//dest += src_a * src_b
	for(int i = 0; i < 2; i++)
		{
			dest[i] = dest[i] - (src_a[i] * src_b[i]);
		}
}

float glmc_vec2f_dot(vec2f src_a, vec2f src_b)
{
	//sum(src_a[i]*src_b[i])
	float result=0;
	for(int i = 0; i < 2; i++)
	{
		result = result + (src_a[i] * src_b[i]);
	}
}

