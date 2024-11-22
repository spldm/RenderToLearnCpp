#include "Helper.h"
#include <stdlib.h>

int Helper::getRandomInt(int minIncl, int maxExcl) {
	return minIncl + rand() % (maxExcl - minIncl);
}