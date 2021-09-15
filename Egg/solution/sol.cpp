#include "Egg.h"

long long height_limit(long long M) {
	long long l = 1, r = M + 1;
	while (r - l > 1) {
		long long mid = (l + r) >> 1;
		if (is_broken(mid)) r = mid;
		else l = mid;
	}
	return l;
}
