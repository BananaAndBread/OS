#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int maxInt = INT_MAX;
    float maxFloat = FLT_MAX;
    double maxDouble = DBL_MAX;
    printf("%d %lu\n", maxInt, sizeof(maxInt));
    printf("%f %lu\n", maxFloat, sizeof(maxFloat));
    printf("%lf %lu\n", maxDouble, sizeof(maxDouble));
    return 0;
}
