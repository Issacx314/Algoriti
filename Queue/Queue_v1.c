/***************************************************************************
*=====================      Copyright by Don Issac      ===============
****************************************************************************
* Title        : Queue
*
* Description  : Code used to create a queue
*
* Environment  : Laptop
*
* Responsible  : Issac Jim�nez
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAM      10

typedef struct element
{
	unsigned int u32value;
	struct element *ptstnext;
}element;

typedef element *ptrElement;


void QUEUE_vstNodCreate(ptrElement *, ptrElement *, int);
void QUEUE_vprint(ptrElement);


int main(void)
{
	element *ptstNodFirst =  NULL;
	element *ptstNodLast = NULL;
	unsigned char u8Count;
	unsigned int au32values[TAM] = { 2, 4, 5, 6, 7, 8, 9, 1, 3, 0 };

	printf("\n Creation of a queue \n\n");

	for (u8Count = 0; u8Count<10; u8Count++)
	{
		QUEUE_vstNodCreate(&ptstNodFirst, &ptstNodLast, au32values[u8Count]);
		
	}
	
	QUEUE_vprint(ptstNodFirst);


	free(ptstNodFirst);
	free(ptstNodLast);


	getch();
	return 0;
}


void QUEUE_vstNodCreate(ptrElement *ptstNodeHead, ptrElement *ptstNodeEnd, int value)
{
	element *ptstNodeNew;

	ptstNodeNew = (element*)calloc(1, sizeof(element));

	if (ptstNodeNew != NULL)
	{
		ptstNodeNew->u32value = value;
		ptstNodeNew->ptstnext = NULL;

		if (NULL == *ptstNodeHead)
		{
			*ptstNodeHead = ptstNodeNew;
		}

		else {
			(*ptstNodeEnd)->ptstnext = ptstNodeNew;/*Move node*/
		}
		
		*ptstNodeEnd = ptstNodeNew;/*Move node*/
		
	}

	else {
		printf("\n  failure of allocation.");
	}
}



void QUEUE_vprint(ptrElement ptstNodeHead)
{
	unsigned char u8count;
	if (NULL == ptstNodeHead)
	{
		printf("\n Queue is empty \n");
	}
	else {
		for (u8count = 0; u8count < TAM; u8count++)
		{
			printf("\n --{%d, node direction %d}", ptstNodeHead->u32value, ptstNodeHead);
			ptstNodeHead = ptstNodeHead->ptstnext;
		}
	}
}
