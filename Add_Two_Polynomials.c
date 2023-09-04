
// Program to add two polynomials maintained as linked lists

#include <stdio.h>
#include <stdlib.h>

struct Polynomial {
    int iCoeff;
    int iExp;
    struct Polynomial *ptrNext;
};

typedef struct Polynomial PolyNode;
PolyNode * fnCreate_Polynomial(PolyNode *, int , int);
void fnDisplayPoly ( PolyNode *);
PolyNode * fnPolyADD(PolyNode *, PolyNode *, PolyNode *);
PolyNode *fnCreate_Polynomial(PolyNode *ptrPoly, int iCoeff, int iExp){
    PolyNode *ptrTemp,*ptrNewNode ;
    ptrTemp = ptrPoly;
    ptrNewNode = (PolyNode*) malloc(sizeof (PolyNode)) ;

    if ( ptrPoly == NULL ){
        ptrPoly = ptrNewNode;
    }
    else
    {
        while ( ptrTemp -> ptrNext != NULL )
            ptrTemp = ptrTemp -> ptrNext;
        ptrTemp -> ptrNext = ptrNewNode;
    }
    ptrNewNode -> iCoeff = iCoeff ;
    ptrNewNode -> iExp = iExp ;
    ptrNewNode -> ptrNext = NULL ;
    return ptrPoly;
}

void fnDisplayPoly ( PolyNode *ptrPoly ){
    if(ptrPoly==NULL)
    {
        printf("List is empty");
        return;
    }
    while ( ptrPoly != NULL ){
        printf ( "%dx^%d", ptrPoly -> iCoeff, ptrPoly -> iExp ) ;
        ptrPoly = ptrPoly -> ptrNext ;
        if(ptrPoly != NULL)
            printf(" + ");
        else
            printf("\n");
    }
}

PolyNode *fnPolyADD(PolyNode *ptrPolyA, PolyNode *ptrPolyB, PolyNode *ptrPolyC){
    int iX;
    PolyNode *ptrTempA, *ptrTempB;
    ptrTempA = ptrPolyA;
    ptrTempB = ptrPolyB;
    while(ptrTempA != NULL && ptrTempB != NULL)
    {
        if(ptrTempA->iExp == ptrTempB->iExp){
            iX = ptrTempA->iCoeff + ptrTempB->iCoeff;
            if(iX != 0)
            ptrPolyC = fnCreate_Polynomial(ptrPolyC, iX, ptrTempA->iExp);
            ptrTempA = ptrTempA->ptrNext;
            ptrTempB = ptrTempB->ptrNext;
        }
        else if(ptrTempA->iExp < ptrTempB->iExp)
        {
            ptrPolyC = fnCreate_Polynomial(ptrPolyC, ptrTempB->iCoeff, ptrTempB->iExp);
            ptrTempB = ptrTempB->ptrNext;
        }
        else
        {
            ptrPolyC = fnCreate_Polynomial(ptrPolyC, ptrTempA->iCoeff, ptrTempA->iExp);
            ptrTempA = ptrTempA->ptrNext;
        }
    }
    while(ptrTempA != NULL){
        ptrPolyC = fnCreate_Polynomial(ptrPolyC, ptrTempA->iCoeff, ptrTempA->iExp);
        ptrTempA = ptrTempA->ptrNext;
    }
    while(ptrTempB != NULL){
        ptrPolyC = fnCreate_Polynomial(ptrPolyC, ptrTempB->iCoeff, ptrTempB->iExp);
        ptrTempB = ptrTempB->ptrNext;
    }
    return ptrPolyC;
}
void main( ){
    PolyNode *ptrPolyA, *ptrPolyB, *ptrPolyC;
    int i = 0,iChoice,iCoeff,iExp ;
    ptrPolyA = ptrPolyB = ptrPolyC = NULL ;  
    while(1)
    {
        printf("\n 1. Add term in first polynomial");
        printf("\n 2. Show first polynomial");
        printf("\n 3. Add term in second polynomial");
        printf("\n 4. Show second polynomial");
        printf("\n 5. Add two polynomials");
        printf("\n 6. Exit");
        printf("\nEnter your choice");
        scanf("%d",&iChoice);
        switch(iChoice) {
            case 1:
                printf("\nEnter coefficient and exponent");
                scanf("%d%d",&iCoeff,&iExp);
                ptrPolyA = fnCreate_Polynomial(ptrPolyA,iCoeff,iExp);
                break;
            case 2:
                fnDisplayPoly(ptrPolyA);
                break;
            case 3:
                printf("\nEnter coefficient and exponent");
                scanf("%d%d",&iCoeff,&iExp);
                ptrPolyB = fnCreate_Polynomial(ptrPolyB,iCoeff,iExp);
                break;
            case 4:
                fnDisplayPoly(ptrPolyB);
                break;
            case 5:
                ptrPolyC=NULL;
                ptrPolyC = fnPolyADD(ptrPolyA,ptrPolyB,ptrPolyC);
                fnDisplayPoly (ptrPolyC) ;  
                break;
            case 6:
                exit(1);
            default:
                printf("\nWrong choice");
        }
    }
}