#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	long long x[1000][1000] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%lld", &x[i][j]);
	}
	int working = 1;
	int pi = 0, pj = 0; //fiind piesa alba
	int pir, pjr;
	long long distanta = 0;
	while (working == 1) {
		if ((pi + pj) % 2 == 0) {
			//culoare alba -> mutari pe linie
			pir = pi;
			pjr = (pj + x[pi][pj]) % n;
			if (pjr < 0)
				pjr = n + pjr;
		} else {
			//culoare neagra -> mutari pe coloana
			pir = (pi + x[pi][pj]) % n;
			pjr = pj;
			if (pir < 0)
				pir = n + pir;
		}
		if (x[pi][pj] == 0) {
			working = 0;
		} else {
			long long tmp = x[pi][pj];
			if (tmp < 0)
				tmp = tmp * (-1);
			distanta += tmp;
			x[pi][pj] = 0;
			pi = pir;
			pj = pjr;
		}
	}
	printf("%lld\n%d ", distanta,  n - pi);
	//Aflam reprezentarea EXCEL a lui pj
	char l[25] = {'\0'};
	int litere = 'Z' - 'A' + 1, tmp_n = pj + 1, i = 0;
	do {
		l[24 - i] = tmp_n % litere + 'A' - 1;
		tmp_n /= litere;
		i++;
	} while (tmp_n > 0);
	i--;
	while (i >= 0) {
		printf("%c", l[24 - i]);
		i--;
	}
	printf("\n");
	return 0;
}
