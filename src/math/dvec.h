/**
 *  dvec.h - dynamic vector.
 *  author - 7Gv
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _dvec dvec_t;

struct _dvec
{
	double *data;
	const int dimension;

	bool is_complex;
};

/**
 * @brief      Initialize dynamic vector.
 *
 * @param[in]  dimension   The dimension
 * @param[in]  is_complex  Indicates if complex
 */
void dvec_init(const int dimension, bool is_complex);

/**
 * @brief      Return data address.
 *
 * @param[in]  ref  Reference to the associated dvec struct.
 *
 * @return     Pointer to the first index where the data is stored.
 */
double * dvec_data(struct _dvec *ref);


