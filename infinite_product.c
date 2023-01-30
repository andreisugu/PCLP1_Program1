#include <stdio.h>
#include <math.h>

signed long long convertire_b8_b10(signed long long x)
{
	signed long long rez = 0, pow = 1;
	while (x > 0) {
		rez += pow * (x % 10);
		pow *= 8;
		x /= 10;
	}
	return rez;
}

int main(void)
{
	long N;
	signed long long
	a_i, b_i,
	maxa1 = -1, maxa2 = -1, maxb1 = -1, maxb2 = -1;
	unsigned long long ps = 0;
	double suma_patrate_a = 0, suma_patrate_b = 0;
	scanf("%ld", &N);
	for (long i = 1; i <= N; i++) {
		scanf("%lld", &a_i);
		scanf("%lld", &b_i);

		a_i = convertire_b8_b10(a_i);
		b_i = convertire_b8_b10(b_i);

		//Maxime    S-ar putea sa fie in baza 8, refaci daca da
		//pt a
		if (a_i > maxa1) {
			maxa2 = maxa1;
			maxa1 = a_i;
		} else {
			if (a_i > maxa2 && a_i != maxa1)
				maxa2 = a_i;
		}
		//pt b
		if (b_i > maxb1) {
			maxb2 = maxb1;
			maxb1 = b_i;
		} else {
			if (b_i > maxb2 && b_i != maxb1)
				maxb2 = b_i;
		}

		//Produs scalar
		ps += a_i * b_i;

		//Norma2
		suma_patrate_a += (a_i * a_i);
		suma_patrate_b += (b_i * b_i);
	}

	printf("%llu\n", ps);
	if (maxa2 == -1)
		printf("-1 ");
	else
		printf("%llu ", maxa2);
	if (maxb2 == -1)
		printf("-1\n");
	else
		printf("%llu\n", maxb2);

	printf("%.7lf %.7lf\n", sqrt(suma_patrate_a), sqrt(suma_patrate_b));
	return 0;
}
