#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int value;
	struct element *next;
}element;

typedef element *ptrElement;


void QUEUE_vstNodCreate(ptrElement *, ptrElement *, int);
void QUEUE_vprint(ptrElement ,char);
void QUEUE_vfree(ptrElement ptstNodeHead);


int main(void)
{
	element *ptstNodFirst =  NULL;
	element *ptstNodLast = NULL;
	int num = 2, i;
	char *strin = "123A";
	int result;

	int values[10] = { 2, 4, 5, 6, 7, 8, 9, 1, 3, 0 };
	/* your code */
	//stNodFirst = QUEUE_stFirstNodCreate(values[0]);

	for (i = 0; i<10;i++)
	{
		QUEUE_vstNodCreate(&ptstNodFirst, &ptstNodLast, values[i]);
		
	}
	
	QUEUE_vprint(ptstNodFirst, 5);

	QUEUE_vprint(ptstNodFirst, 7);


	free(ptstNodFirst);
	free(ptstNodLast);

	//QUEUE_vfree(ptstNodLast);

	result = atoi(strin);

	printf("\n %d\n", result);

	getch();
	return 0;
}


void QUEUE_vstNodCreate(ptrElement *ptstNodeHead, ptrElement *ptstNodeEnd, int value)
{
	element *ptstNodeNew;

	ptstNodeNew = (element*)calloc(1, sizeof(element));

	if (ptstNodeNew != NULL)
	{
		ptstNodeNew->value = value;
		ptstNodeNew->next = NULL;

		if (NULL == *ptstNodeHead)
		{
			*ptstNodeHead = ptstNodeNew;
		}

		else {
			(*ptstNodeEnd)->next = ptstNodeNew;/*Move node*/
		}
		
		*ptstNodeEnd = ptstNodeNew;/*Move node*/
		
	}

	else {
		printf("\n  failure of allocation.");
	}
}



void QUEUE_vprint(ptrElement ptstNodeHead, char u8limit)
{
	char count;
	if (NULL == ptstNodeHead)
	{
		printf("\n Queue is empty \n");
	}
	else {
		for (count = 0; count <u8limit; count++)
		{
			printf("\n --{%d, node direction %d}", ptstNodeHead->value, ptstNodeHead);
			ptstNodeHead = ptstNodeHead->next;
		}
	}
}

void QUEUE_vfree(ptrElement ptstNodelast)
{
	//char count;
	ptrElement ptsTemp = NULL;

	printf("\n %d\n",sizeof(ptstNodelast));

	if (NULL == ptstNodelast)
	{
		printf("\n Queue is empty \n");
	}
	else {
		/*while (NULL != ptstNodeHead)
		{
			printf("\n --{%d, node direction %d}", ptstNodeHead->value, ptstNodeHead);
			ptsTemp = ptstNodeHead->next;
			free(ptstNodeHead);
		}*/
	}
}