#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED

#include <math.h>

// a
int interval(int n)
{
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a < n && n <= b)
        return 1;
    return 0;
}

// b
int cifre(int n)
{
    // exemplu: a = 783
    int unit = n % 10;
    int zeci = (n / 10) % 10;
    int sute = (n / 100) % 10;
    if(unit < sute)
        return 1;
    return 0;
}


// c
int progresie(int n)
{
    int u1 = n % 10; // unitati
    int u2 = (n / 10) % 10; // zeci
    int u3 = (n / 100) % 10; // sute
    if(u2 == ((u1 + u3) >> 1))
        return 1;
    return 0;

}

// d

int nrCfire(int n)
{
    int nrcifre = 0;
    while(n)
    {
        nrcifre++;
        n /= 10;
    }
    return nrcifre;
}

// e

int sumaCifrePare(int n)
{
    int sum = 0;
    while(n)
    {
        if((n % 10) % 2 == 0)
            sum += (n % 10);
        n /= 10;
    }
    return sum;
}

// f
int cateCifreK(int n)
{
    int k;
    scanf("%d", &k);
    int contor = 0;
    while(n)
    {
        if(n % 10 == k)
        {
            contor++;
        }

        n /= 10;
    }
    return contor;
}

// g
void CifMaxSiCifMin(int n)
{
    int max = 0, min = 0;
    int cp = n;
    // ex: 12341209
    while(n)
    {
        if(n % 10 > max)
            max = n % 10;
        n /= 10;
    }
    n = cp;
    min = max;
    while(n)
    {
        if(n % 10 < min)
            min = n % 10;
        n /= 10;
    }

    printf("max: %d si min: %d", max, min);
}
//===================CUSTOM BUILD FUNCTIIONS==============================
int sumaCifre(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sumCifRecursiv(int n)
{
    if(n <= 9)
        return n;
    else
        return n % 10 + sumCifRecursiv(n);
}

int prim(int n)
{
    if(n < 2)
        return 0;
    if(n > 2 && n % 2 == 0)
        return 0;
    int d = 3;
    for(; d * d <= n; d += 2)
        if(n % d == 0)
            return 0;
    return 1;
}
//=================================================

// h
float medieAritCifre(int n)
{
    int sum = 0;
    int cifre = nrCfire(n);
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return (float) sum / cifre;
}

// i
int cifraControl(int n)
{
    // Cifra de control se calculeaza facand suma cifrelor numarului,
    // dupa care suma cifrelor sumei si asa mai departe pana cand suma obtinuta este o cifra.

    int sumacif = sumaCifre(n);
    while(sumacif > 9)
    {
        sumacif = sumaCifre(sumacif);
    }
    return sumacif;
}

// k
int rasturnat(int n)
{
    int rast = 0;
    while(n)
    {
        rast = rast * 10 + n % 10;
        n /= 10;
    }
    return rast;
}

// l

int palindrom(int n)
{
    if(n == rasturnat(n))
        return 1;
    return 0;
}

// m

int celPutin4Div(int n)
{
    int d = 2;
    int contor = 0;
    while(d < n)
    {
        d++;
        if(n % d == 0)
            contor++;
    }
    if(contor == 4)
        return 1;
    return 0;

}


// n
// 12
// 1 2 3 4 6 12
// = 28
int sumaDiv(int n)
{
    int sum = 0;
    int i = 1;
    for(; i * i <= n; i++)
    {
        if(n % i == 0)
            sum = sum + i + n / i;
        //printf("%d ", i);
        //printf("%d ", n / i);
    }

    if(sqrt(n) == floor(sqrt(n)))
        sum -= sqrt(n);
    return sum;
}

// o

int perfect(int n)
{
    int sumadiv = sumaDiv(n);
    sumadiv -= n;
    if(sumadiv == n)
        return 1;
    return 0;
}

// p

void numerePrimePanaLaN(int n)
{
    int iter = 2;
    for(; iter <= n; iter++)
    {
        if(prim(iter))
            printf("%d ", iter);
    }
}


// q

void primeleNpatratePerfecte(int n)
{
    int iter = 1;
    for(; iter <= n; iter++)
        if(sqrt(iter) == floor(sqrt(iter)))
            printf("%d ", iter);
}

// r
void multipliiK(int n)
{
    int k;
    scanf("%d", &k);
    //printf("%d ", k);
    int iter = 0;
    int multiplu = k;
    for(; iter < n; iter++)
    {
        multiplu += k;
        if(multiplu % k == 0)
            printf("%d ", multiplu);
    }
}

// s

int doiLaN(int n)
{
    int iter = 0;
    int val = 2;
    for(; iter < n - 1; iter++)
        val *= val;
    return val;
}

// t
// n = 8
// 3 9 27
int primaPutereAluiN_3(int n)
{
    int p = 3;
    while(p < n)
    {
        p *= p;
    }
    return p;
}

// u
void numereDe2CifreNpatrat(int n)
{
    int iter = 10;
    for(; iter < n * n; iter++)
        if(palindrom(sumaDiv(iter)))
            printf("%d ", iter);
}



// ==========================SETUL 2 DE PROBLEME================================
// functii aplicate pe vectori


// a

int sumaElemParePozImp(int *v, int n)
{
    int iter = 0, sum = 0;
    for(; iter < n; iter++)
    {
        if(iter % 2 != 0 && iter)
        {
            sum += v[iter];
        }
    }

    return sum;
}

// b

void Swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void MinSiMaxInter(int *v, int n)
{
    int max = 0, index;
    int iter;
    for(iter = 0; iter < n; iter++)
    {
        if(v[iter] > max)
        {
            max = v[iter];
            index = iter;
        }

    }

    int min = max;

    for(iter = 0; iter < index; iter++)
    {
        if(v[iter] < min)
            min = v[iter];
    }

    Swap(&min, &max);
}

// miruna1224@yahoo.com

// c
void citirePanaLaNpe2Pare(int *v, int n)
{
    int contor = 0;
    int iter;
    for(iter = 0; iter < n; iter++)
    {
        scanf("%d", &v[iter]);
        if(v[iter] % 2 == 0)
            contor++;
    }

    if(contor >= n / 2)
        printf("un mesaj corespunzator");
}

// d
void citireKvalori(int *v, int n)
{
    int k, contor = 0;
    scanf("%d", &k);

    int iter;
    for(iter = 0; iter < n; iter++)
    {
        scanf("%d", &v[iter]);
        if(nrCfire(v[iter]) == 3)
            contor++;
    }

    if(contor >= k)
        printf("un mesaj corespunzator");
}


// e

int intervalVectorAB(int *v, int n)
{
    int contor = 0;
    int a,b;
    scanf("%d", a);
    scanf("%d", b);
    if(a > b)
        return;

    int iter = a;
    for(; iter < b; iter++)
    {
        if(a > v[iter] && v[iter] < b)
            contor++;
    }
    return contor;
}

// f
void pozitiiK(int *v, int n)
{
    int k;
    scanf("%d", &k);

    int iter;
    for(iter = 0; iter < n; iter++)
    {
        if(v[iter] == k)
            printf("%d", iter);
    }
}
// g

int numereCifraZecilorIntre2si8(int *v, int n)
{
    int iter, contor = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(2 < v[iter] % 10 && v[iter] % 10 < 8)
            contor++;
    }
    return contor;
}

// h

int numerePalindromVector(int *v, int n)
{
    int iter, contor = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(palindrom(v[iter]))
            contor++;
    }
    return contor;
}

// i

int NumarDivizoriN(int n)
{
    int iter, contor = 0;
    for(iter = 1; iter <= n; iter++)
        if(n % iter == 0)
            contor++;
    return contor;
}
void NumereCuCelMult6Div(int *v, int n)
{
    int iter, contor = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(NumarDivizoriN(v[iter]) <= 6)
            printf("%d ", v[iter]);
        }
}

// j

void NumereCu4Cifre(int *v, int n)
{
    int iter, contor = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(nrCfire(v[iter]) == 4)
            printf("%d ", v[iter]);
    }
}

// k

void SumaDivNrPrim(int *v, int n)
{
    int iter, contor = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(prim(sumaDiv(v[iter])))
            contor++;
    }
    return contor;
}

// l
void CateNumereSuperPrime(int *v, int n)
{
    int iter, contor = 0, nr = 0;
    for(iter = 0; iter < n; iter++)
    {
        int copie = v[iter];
        while(copie)
        {
            if(prim(copie))
                nr++;
            copie /= 10;
        }
        if(nr == nrCfire(v[iter]))
            contor++;
    }
    return contor;
}

// m
int ProdusDivizoriPariN(int n)
{
    int iter, produs = 1;
    for(iter = 1; iter <= n; iter++)
        if(n % iter == 0)
            if(iter % 2 == 0)
                produs *= iter;
    return produs;
}

void ProdusDivizoriPariVec(int *v, int n)
{
    int iter, contor = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(ProdusDivizoriPariN(v[iter]) % 10 == 0)
            printf("%d ", v[iter]);
    }
}


// n
void InversElemMaxVector(int *v, int n)
{
    int iter, contor = 0;
    int max = v[0];
    for(iter = 1; iter < n; iter++)
    {
        if(v[iter] > max)
            max = v[iter];
    }

    printf("%d", rasturnat(max));
}

// o

void PozMaxsiMinVec(int *v, int n)
{
    int max = 0, indexMax, indexMin;
    int iter;
    for(iter = 0; iter < n; iter++)
    {
        if(v[iter] > max)
        {
            max = v[iter];
            indexMax = iter;
        }

    }

    int min = max;

    for(iter = 0; iter < indexMax; iter++)
    {
        if(v[iter] < min)
        {
            min = v[iter];
            indexMin = iter;
        }
    }

    printf("max %d si min %d", indexMax, indexMin);
}

// p

// 1 2 3 4 5 6
void CeleMaiMari2ValVec(int *v, int n)
{
    int max1 = 0, indexMax, indexMin;
    int iter;
    for(iter = 0; iter < n; iter++)
    {
        if(v[iter] > max1)
        {
            max1 = v[iter];
        }
    }

    int max2 = 0;

    for(iter = 0; iter < n; iter++)
    {
        if(v[iter] > max2 && v[iter] != max1)
            max2 = v[iter];
    }


    printf("max1 %d si max2 %d", max1, max2);
}
// k2

void printInvers(int *v, int n)
{
    if(n == 0)
    {
        printf(v[0]);
        return;
    }
    printf(v[n - 1]);
    printInvers(v, n - 1);
}

// l2
void SortDescVec(int *v, int n)
{
    int iter = 0;
    int jiter = 1;
    for(; iter < n; iter++)
        for(; jiter < n; jiter++)
            if(v[iter] < v[jiter])
                Swap(&v[iter], &v[jiter]);

    for(iter = 0; iter < n; iter++)
        printf("%d ", v[iter]);

}
// m2
// 1 2 3 4 5
/*
    medie = 15 / 2 = 7.5

    1 7.5 2 3 4 5
*/
void medieAritNrParePePoz2Vec(int *v, int n)
{
    //int newArray[sizeof(v)] = {0};
    int iter, nrPare = 0, sumPare = 0;
    for(iter = 0; iter < n; iter++)
    {
        if(v[iter] % 2 == 0)
        {
            sumPare += v[iter];
            nrPare++;
        }
    }

    int medie = sumPare / nrPare;

    // shiftare la dreapta
    for(iter = 2; iter < n; iter++)
    {
        v[iter + 1] = v[iter];
    }
    v[2] = medie;
}
// n2
// 1 2 3 4 5
// 0 1 2 3 4
/*
    medie = 15 / 2 = 7.5

    1 2 3 4 7.5 5
*/
void medieAritNrPareintreUltimiVec(float *v, int n)
{
    //int newArray[sizeof(v)] = {0};
    int iter, sum = 0;
    for(iter = 0; iter < n; iter++)
            sum += v[iter];



    int medie = sum / n;

    // shiftare la dreapta
    for(iter = n - 2 ; iter < n; iter++)
    {
        v[iter + 1] = v[iter];
    }
    v[n - 2] = medie;
}



#endif // FUNCTII_H_INCLUDED
