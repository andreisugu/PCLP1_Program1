# PCLP1_Tema1
Tema 1 - PCLP 1
Problema 1 - infinite_product.c
Pasi abordati in rezolvare:
- citirea numerelor a_i si b_i
- transformarea acestora din baza 8 in baza 10 (prin folosirea subprogramului convertire_b8_b10 care foloseste convertirea uzuala din baza 8 in baza 10 matematic vorbind)
- pt a_i si b_i stabilim daca sunt noi maxime sau maxime secunde si le punem in variabile daca sunt
- produsul scalar poate fi calculat normal
- suma de patrate poate fi calculata normal
- afisam produsul scalar, maximele secunde si dupa la final , deoarece in functie doar am facut suma de patrate, in final aplicam functia sqrt() pe acestea si le afisam

Problema 2 - simple_queries.c
Pasi abordati in rezolvare:
- avem 4 subprograme:
a. biggest -> returneaza un int care reprezinta pozitia celui mai mare numar din matricea unidimensionala primita
b. biggest_c -> afisam cele mai mari (ramas) numere din matricea unidimensionala primita folosind subprogramul biggest() si prin inlocuirea numerelor gasite ulterior
c. nenule -> returneaza numarul de cifre nenule din matricea unidimensionala primita
d. cmmdc -> returneaza cel mai mic divizor comun a doua numere
- abordam prin multiple if-uri si else-uri situatiile in care suntem pusi (litere mici, Q, T, E, altceva (adica oprire))
- pentru litere mici, actualizam numarul de citiri totale, adaugam litera si verificam daca e nevoie de o alerta
- alertele se activeaza atunci cand avem nenule(x) >= 2, numarul de citiri de litere de la ultima alerta minim 5 (total_citiri - citiri_last >= 5) si un numar are mai mult de jumate din citiri (x[big] * 2 >= total_citiri), dupa afisam
- pentru Q, e nevoie doar de afisarea directa din matricile s si x
- pentru T, facem citirea pentru numar (care poate fi de maxim 2 cifre deci nu e nevoie de un subprogram dedicat) si dupa afisam ceea ce ne este cerut cu ajutorul subprogramului biggest_c()
- pentru E, putem elimina direct ce este nevoie din x, avand grija sa ajustam si variabilele total_citiri si citiri_last

Problema 3 - gigel_and_the_checkboard.c
Pasi abordati in rezolvare:
- are loc citirea si declararea variabilelor necesare rezolvarii
- folosim un while care se opreste doar atunci cand ajungem intr-un punct in care nu mai putem face nimic
- avem grija ca la fiecare pas sa facem elementele parcurse ale matricei nule
- abordam separat culoarea casutei in care ne aflam, care este aflata din paritatea sumei coordonatelor casutei respective, si rezolvam
- daca while-ul continua, actualizam distanta si pozitiile
- facem afisarea in format excel al casutelor, acesta fiind calculat prin presupunerea bazei 25 si a efectuarii calculelor aferente acestei transformari

Problema 4 - another_queries.c
Pasi abordati in rezolvare:
- avem un numar Mare de subprograme folosite pentru modularizarea acestui program complex:
a. init_val -> suprascrie toate variabilele dintr-o matrice cu valoarea primita ca argument
b. citire -> citeste valorile matricii x
c. valid -> intoarce validitatea matricii x: este necesar ca valoarea intoarsa de subprogramele v_linie_coloana() si v_careu() sa fie pozitiva
d. v_linie_coloana -> intoarce validitatea matricii x cand vine vorba de validitate pe linii si coloane (valorile sa fie unice in parcurgerea acestora)
e. v_careu -> intoarce validitatea matricii x cand vine vorba de validitate pe careuri (valorile sa fie unice in parcurgerea matricii pe careuri)
f. op_1 -> prin folosirea unei matrici de frecventa, aflam eficient si afisam ce elemente pot fi puse pe o linie specificata
g. op_2 -> prin folosirea unei matrici de frecventa, aflam eficient si afisam ce elemente pot fi puse pe o coloana specificata
h. op_3 -> prin folosirea unei matrici de frecventa, aflam eficient si afisam ce elemente pot fi puse intr-un careu specificat
i. op_4 -> daca celula noastra este ocupata, intoarcem n * n zero-uri; altfel, prin folosirea unei matrici de frecventa de 2 ori, aflam eficient si afisam ce elemente pot fi puse in celula specificata
j. op_5 -> doar verificam daca celula specificata nu este ocupata si introducem valoarea
k. op_6 -> verificam , prin folosirea subprogramului valid() daca matricea este valida; daca este valida, verificam daca are vreun element liber (astfel fiind completabila); daca este completabila, intoarcem 0; daca nu este completabila, intoarcem 2; daca este invalida intoarcem 1
- in main() are loc doar declararea si citirea, precum si un switch() care ne trimite la subprogramele cerute

