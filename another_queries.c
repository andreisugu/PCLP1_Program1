#include <stdio.h>

void init_val(int n, char m_fr[401], int val);
void citire(int x[400][400], int n);
void op_1(int x[400][400], int n, char m_fr[401]);
void op_2(int x[400][400], int n, char m_fr[401]);
void op_3(int x[400][400], int n, char m_fr[401]);
void op_4(int x[400][400], int n, char m_fr[401]);
void op_5(int x[400][400]);
void op_6(int x[400][400], int n, char m_fr[401]);
int valid(int x[400][400], int n, char m_fr[401]);
int v_linie_coloana(int x[400][400], int n, char m_fr[401]);
int v_careu(int x[400][400], int n, char m_fr[401]);
//int invalid(int x[400][400], int n, int i, int j);

int main(void)
{
	//Citire
	int x[400][400], n, m;
	char m_fr[401];
	scanf("%d", &n);
	scanf("%d", &m);
	citire(x, n);
	//Operatii si efectuarea acestora
	for (int i = 0; i < m; i++) {
		int op;
		scanf("%d", &op);
		switch (op) {
		case 1:
			op_1(x, n, m_fr);
			break;
		case 2:
			op_2(x, n, m_fr);
			break;
		case 3:
			op_3(x, n, m_fr);
			break;
		case 4:
			op_4(x, n, m_fr);
			break;
		case 5:
			op_5(x);
			break;
		case 6:
			op_6(x, n, m_fr);
			break;
		}
	}
	return 0;
}

void init_val(int n, char m_fr[401], int val)
{
	//initializam cu 0
	for (int k = 0; k <= n * n; k++)
		m_fr[k] = val;
}

void citire(int x[400][400], int n)
{
	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < n * n; j++)
			scanf("%d", &x[i][j]);
	}
}

//Functional EFICIENTA
void op_1(int x[400][400], int n, char m_fr[401])
{
	//linia nr
	int nr;
	scanf("%d", &nr);
	nr--;
	init_val(n, m_fr, 1);
	for (int i = 0; i < n * n; i++) // <- numere
		m_fr[x[nr][i] - 1] = 0;
	for (int i = 0; i < n * n; i++)
		printf("%d ", m_fr[i]);
	printf("\n");
}

//Functional EFICIENTA
void op_2(int x[400][400], int n, char m_fr[401])
{
	//coloana nr
	int nr;
	scanf("%d", &nr);
	nr--;
	init_val(n, m_fr, 1);
	for (int i = 0; i < n * n; i++) // <- numere
		m_fr[x[i][nr] - 1] = 0;
	for (int i = 0; i < n * n; i++)
		printf("%d ", m_fr[i]);
	printf("\n");
}

//Functional EFICIENTA
void op_3(int x[400][400], int n, char m_fr[401])
{
	//careu = n coloana * n linii
	//in teorie, trebuie verificat doar careul respectiv
	//Aflam unde incepe careul
	int careu, i, j;
	scanf("%d", &careu);
	i = (careu - 1) / n;
	i = i * n;
	j = ((careu - 1) % n) * n;
	init_val(n, m_fr, 1);
	//rezolvam
	for (int k = i; k <= i + n - 1; k++) {
		for (int l = j; l <= j + n - 1; l++)
			m_fr[x[k][l] - 1] = 0;
	}
	for (i = 0; i < n * n; i++)
		printf("%d ", m_fr[i]);
	printf("\n");
}

//Functional
void op_4(int x[400][400], int n, char m_fr[401])
{
	//ce putem pune intr-o celula specifica
	//trebuie verificat pe linie si coloana doar odata
	//de asemenea verificam in careu
	int i, j;
	scanf("%d", &i); i--;
	scanf("%d", &j); j--;
	if (x[i][j] != 0) {
		for (int i = 0; i < n * n; i++)
			printf("0 ");
		printf("\n");
	} else {
		init_val(n, m_fr, 1);
		for (int k = 0; k < n * n; k++) {
			m_fr[x[i][k] - 1] = 0;
			m_fr[x[k][j] - 1] = 0;
		}
		//Aflam coordonatele din colt stanga sus careu
		int c1 = i / n;
		c1 = c1 * n;
		int c2 = j / n;
		c2 = c2 * n;
		//verificam si in careu
		for (int e = c1; e < c1 + n; e++) {
			for (int r = c2; r < c2 + n; r++) {
				if (e != i && r != j)
					m_fr[x[e][r] - 1] = 0;
			}
		}
		for (int k = 0; k < n * n; k++)
			printf("%d ", m_fr[k]);
		printf("\n");
	}
}

void op_5(int x[400][400])
{
	//doar pui valoarea lol
	int i, j, c;
	scanf("%d", &i); i--;
	scanf("%d", &j); j--;
	scanf("%d", &c);
	if (x[i][j] == 0)
		x[i][j] = c;
}

void op_6(int x[400][400], int n, char m_fr[401])
{
	int completabila = 0;
	if (valid(x, n, m_fr) == 1) {
		for (int i = 0; i < n * n && completabila == 0; i++) {
			for (int j = 0; j < n * n; j++) {
				if (x[i][j] == 0) {
					completabila = 1;
					break;
				}
			}
		}
		if (completabila == 1)
			printf("0");
		else
			printf("2");
	} else {
		printf("1");
	}
	printf("\n");
}

int valid(int x[400][400], int n, char m_fr[401])
{
	if (v_linie_coloana(x, n, m_fr) == 0)
		return 0;
	if (v_careu(x, n, m_fr) == 0)
		return 0;
	return 1;
}

int v_linie_coloana(int x[400][400], int n, char m_fr[401])
{
	//verificam validitatea pe linii si coloane
	for (int i = 0; i < n * n; i++) {
		init_val(n, m_fr, 0);
		for (int j = 0; j < n * n; j++) {
			if (++m_fr[x[i][j]] > 1 && x[i][j] != 0)
				return 0;
		}
		init_val(n, m_fr, 0);
		for (int j = 0; j < n * n; j++) {
			if (++m_fr[x[j][i]] > 1 && x[j][i] != 0)
				return 0;
		}
	}
	return 1;
}

int v_careu(int x[400][400], int n, char m_fr[401])
{
	//verificam validitatea pe careuri
	for (int i = 0; i < n * n; i += n) {
		for (int j = 0; j < n * n; j += n) {
			init_val(n, m_fr, 0);
			for (int c1 = i; c1 < i + n; c1++) {
				for (int c2 = j; c2 < j + n; c2++) {
					if (++m_fr[x[c1][c2]] > 1 && x[c1][c2] != 0)
						return 0;
				}
			}
		}
	}
	return 1;
}
