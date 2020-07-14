//使用数组表示数学中的 多项式
/**
 * 使用数组实现多项式，加法的复杂度为O(N),乘法的复杂度为O(N2)，对于稠密性的多项式，没有问题，
 * 但是对于非稠密性的多项式，很多计算是无意义的（都是乘0计算），
 * **/

#include <stdlib.h>
#include <stdio.h>

#define MaxDegree 100  //定义多项式的最大指数是100

static int Max(int A, int B) {
    return A > B ? A : B;
}

struct PolyNom
{
    int CoefffArray[MaxDegree + 1];   // 需要多存储一个常数项
    int HighPower;                    //存储多项式的最高项的指数
} ;
typedef struct PolyNom *Polynomial;

//初始化多项式
void ZeroPolynomial(Polynomial Poly) {
    int i;
    for(i = 0; i<= MaxDegree; i++) {
        Poly->CoefffArray[i] = 0;
    }
    Poly->HighPower = 0;
}

//两个多项式相加
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum) {
    int i;
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);
    for(i = PolySum->HighPower; i >= 0; i--) {
        PolySum->CoefffArray[i] = Poly1->CoefffArray[i] + Poly2->CoefffArray[i];
    }
}

//打印多项式的系数
void PrintPoly(Polynomial Poly) {
    int i,HighPower = Poly->HighPower;
    for(i=HighPower; i>=0; i--) {
        printf("%d\n", Poly->CoefffArray[i]);
    }
    printf("\n");
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd) {
    int i, j;
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    if(PolyProd->HighPower > MaxDegree) {
        printf("Exceed array size");
    } else {
        for(i=0; i<=Poly1->HighPower; i++) {
            for(j=0; j<=Poly2->HighPower; j++) {
                if(PolyProd->CoefffArray[i+j] == NULL) {
                    PolyProd->CoefffArray[i+j] = Poly1->CoefffArray[i] * Poly2->CoefffArray[j];
                } else {
                    PolyProd->CoefffArray[i+j] += Poly1->CoefffArray[i] * Poly2->CoefffArray[j];
                }
            }
        }
    }
}

void MultPolynomial1(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd) {
    int i, j;
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;
    if(PolyProd->HighPower > MaxDegree) {
        printf("Exceed array size");
    } else {
        for(i=0; i<=Poly1->HighPower; i++) {
            for(j=0; j<=Poly2->HighPower; j++) {
                PolyProd->CoefffArray[i+j] = Poly1->CoefffArray[i] * Poly2->CoefffArray[j];
            }
        }
    }
}

void test1() {
    Polynomial Poly1 = (Polynomial)malloc(sizeof(PolyNom));
    Polynomial Poly2 = (Polynomial)malloc(sizeof(PolyNom));
    Polynomial PolySum = (Polynomial)malloc(sizeof(PolyNom));
    ZeroPolynomial(Poly1);
    ZeroPolynomial(Poly2);

    Poly1->HighPower = 3;
    Poly1->CoefffArray[0] = 8;
    Poly1->CoefffArray[1] = 1;
    Poly1->CoefffArray[2] = 2;
    Poly1->CoefffArray[3] = 4;
    
    Poly2->HighPower = 2;
    Poly2->CoefffArray[0] = 7;
    Poly2->CoefffArray[1] = 5;
    Poly2->CoefffArray[2] = 2;

    AddPolynomial(Poly1, Poly2, PolySum);
    PrintPoly(PolySum);
}

void test2() {
    Polynomial Poly1 = (Polynomial)malloc(sizeof(PolyNom));
    Polynomial Poly2 = (Polynomial)malloc(sizeof(PolyNom));
    Polynomial PolyProd = (Polynomial)malloc(sizeof(PolyNom));
    ZeroPolynomial(Poly1);
    ZeroPolynomial(Poly2);

    Poly1->HighPower = 2;
    Poly1->CoefffArray[0] = 4;
    Poly1->CoefffArray[1] = 3;
    Poly1->CoefffArray[2] = 2;
    
    Poly2->HighPower = 1;
    Poly2->CoefffArray[0] = 7;
    Poly2->CoefffArray[1] = 5;

    MultPolynomial(Poly1, Poly2, PolyProd);
    PrintPoly(PolyProd);
}

int main(void) {
    // test1();
    test2();

    system("pause");   //防止闪退
    return 0;
}