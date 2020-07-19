#include "math.h"


// Get the number's length
int numlen(int num) {
	int len = 1;
	while(num > 9) {
		len++;
		num /= 10;
	}
	return len;
}


// Clamp a number
int clamp(int num, int min, int max) {
	if(num < min) return max;
	if(num > max) return min;
	return num;
}