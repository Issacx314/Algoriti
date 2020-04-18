/*Programa de una Arbol ABB PC*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct nodo
{
  int tro;
  struct nodo *izquier;
  struct nodo *derech;
};

typedef struct nodo Arbol;
typedef   Arbol  *Arptdr;

int insertar(Arptdr *,int);
Arptdr crear(int);
void impresion(Arptdr);

int main()
{
  Arptdr Raiz=NULL,temp=NULL;
  int arb=0,op=0;
  
  //textbackground(8);  
  printf("\n Programa de Arboles \n");
  
     	 do{
		    printf("\n [1] Insertar \n");
		    printf("\n [2] Impresion por el ultimo \n");
	        printf("\n [3] Salir \n");
	        printf("\n Introduce tu opcion \n");
             scanf("%d",&op);
       
		    switch(op)
             {
              case 1:printf("\n Ingresa un numero \n");
                      scanf("%d",&arb);  
                      insertar(&Raiz,arb);      
                               
                 break;
             
              case 2:printf("\n El Arbol es \n");
                     impresion(Raiz); 
		             printf("\n\n");
                      
                 break;  
                 
              case 3:
                 exit(0);
          }  
       }while(1);  
    
  getch();
  return 0;
}  

Arptdr crear(int arb)
{
 Arptdr nuevo=NULL;
 
 nuevo=(Arptdr)calloc(1,sizeof(Arbol));
 
 nuevo->izquier=NULL;
 nuevo->derech=NULL;
 
 nuevo->tro=arb;
 
 
 return nuevo;
}
      
int insertar(Arptdr *Raiz,int arb)
{
      
  if(*Raiz==NULL)
    *Raiz=crear(arb);
    
  else
    {
     if(arb==(*Raiz)->tro)
       {
        printf("\n SOn iguales \n");
        return 0;
       }
       
     else
       {
        if(arb>(*Raiz)->tro)
          {
          insertar(&((*Raiz)->derech),arb);
          printf("Derecha");
          }
                   
        else
          {
          insertar(&((*Raiz)->izquier),arb);      //avanza raiz en direccion izq o dere        
          printf("Izquierda");
          }
       }
    }
                 
}                 
void impresion(Arptdr Raiz)
{
    
    if(Raiz!=NULL)
    {
        printf(" [%d]",Raiz->tro);
        impresion(Raiz->derech);
        impresion(Raiz->izquier);
    }
}
