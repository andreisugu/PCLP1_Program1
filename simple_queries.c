#include <stdio.h>

int biggest(int x[])
{
	int k = 0;
	for (int i = 1; i < 'z' - 'a' + 1; i++) {
		if (x[i] > x[k])
			k = i;
	}
	return k;
}

void biggest_c(int x[], int ramas)
{
	if (ramas > 0) {
		int k = biggest(x);
		printf("%c", k + 'a');
		if (ramas > 1)
			printf(" ");
		int val = x[k];
		x[k] = -1;
		biggest_c(x, ramas - 1);
		x[k] = val;
	}
}

int nenule(int x[])
{
	int k = 0;
	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		if (x[i] != 0)
			k++;
	}
	return k;
}

int cmmdc(int a, int b)
{
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

int main(void)
{
	int total_citiri = 0, citiri_last = 0;
	char s[10] = { 0 };
	int x[30] = { 0 };
	while (1 > 0) {
		for (int i = 0; i < 10; i++) {
			scanf("%c", &s[i]);
			if (s[i] == '\n')
				break;
		}
		//litera mica
		if (s[0] >= 'a' && s[0] <= 'z') {
			total_citiri++;
			int i = s[0] - 'a';
			x[i]++;
			//alerta
			if (nenule(x) >= 2) {
				if (total_citiri - citiri_last >= 5) {
					int big = biggest(x);
					if (x[big] * 2 >= total_citiri) {
						int tmp = cmmdc(x[big], total_citiri);
						int tmp1 = x[big] / tmp;
						int tmp2 = total_citiri / tmp;
						printf("%c %d/%d\n", big + 'a', tmp1, tmp2);
						citiri_last = total_citiri;
					}
				}
			}
		} else {
			//Q => interogare numar aparitii
			if (s[0] == 'Q')
				printf("%c %d\n", s[2], x[s[2] - 'a']);
			else
				//T => cele mai importante k litere
				if (s[0] == 'T') {
					int rez = 0;
					if (s[3] >= '0' && s[3] <= '9')
						rez = 10 * (s[2] - '0') + (s[3] - '0');
					else
						rez = (s[2] - '0');
					biggest_c(x, rez);
					printf("\n");
				}
			else
				//E => eliminare numar de aparitii
				if (s[0] == 'E') {
					total_citiri -= x[s[2] - 'a'];
					citiri_last -= x[s[2] - 'a'];
					x[s[2] - 'a'] = 0;
				}
			//Iesim din while
			else
				break;
		}
	}
	return 0;
}
