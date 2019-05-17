#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long float a(int i) {
	return (pow(-1, i)*(1 - pow(2, i) / (pow(2, i) + 1)));
}
long float summ(int n);
long float summ2(long float eps);
void print(int n, int k);
int findFirstElement(long float eps);
int findFirstNegativeElement(long float eps);

void main() {
	char task;
	int x, y;
	long float E, res;
	printf("%s", "1: task 1\n2: task 2\n3: task 3\n4: task 4\n5: task 5\nanything else: quit\n");
	scanf("%c", &task);
	switch (task) {
	case '1':
		printf("%s", "elements to sum: ");
		scanf("%d", &x);
		res = summ(x);
		printf("summ of %d elements = %lf\n", x, res);
		break;
	case '2':
		printf("%s", "eps: ");
		scanf("%lf", &E);
		res = summ2(E);
		printf("summ of elements until |a(i)|<%lf = %lf\n", E, res);
		break;
	case '3':
		printf("%s", "elements to print: ");
		scanf("%d", &x);
		printf("%s", "skip every: ");
		scanf("%d", &y);
		print(x, y);
		break;
	case '4':
		printf("%s", "look for first element < : ");
		scanf("%lf", &E);
		x = findFirstElement(E);
		printf("a(%d) = %lf\n", x, a(x));
		break;
	case '5':
		printf("%s", "look for first negative element < : ");
		scanf("%lf", &E);
		x = findFirstNegativeElement(E);
		printf("a(%d) = %lf\n", x, a(x));
		break;
	default:
		break;
	}
	system("pause");
}

long float summ(int n) {
	long float result = 0;
	int i=1;
	while (i <= n)
	{
		result += a(i);
		i++;
	}
	return(result);
}

long float summ2(long float eps) {
	long float result = 0;
	int i=1;
	while(fabs(a(i))>eps) {
		result += a(i);
		i++;
	}
	return(result);
}

void print(int n, int k) {
	int i=1;
	while(i <= n) {
		if (i%k > 0)
			printf("i=%d; a(%d)=%lf\n", i, i, a(i));
		i++;
	}
}

int findFirstElement(long float eps) {
	int i=1;
	while (a(i) >= eps) { i++; }
	return i;
}

int findFirstNegativeElement(long float eps) {
	int i=1;
	while (fabs(a(i)) >= eps) { i++; }
	return i;
}