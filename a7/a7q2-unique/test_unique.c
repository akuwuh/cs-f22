// an assertion-based test client for unique

#include <assert.h>
#include "unique.h"

int main(void) {
	int len = 3;
	int a[3] = {1, 2, 3};

	assert(distinct(a, len) == true);

	assert(distinct_range(a, len) == true);

	int b[2] = {1, 2};
	assert(missing(b, len) == 3);
}