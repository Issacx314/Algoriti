/***************************************************************************
*=====================      Copyright by Don Issac      ===============
****************************************************************************
* Title        : Listas
*
* Description  : Code used to handling lists
*
* Environment  : Laptop
*
* Responsible  : Issac Jiménez
*****************************************************************************************************/


#include<stdio.h>
#include<stdlib.h>



typedef struct stnode
{
	unsigned int u32element;
	struct node *stNode_link;
}NODE;


NODE* LIST_stNodCreate(NODE *, unsigned int);

void LIST_vAdd(NODE *, unsigned int, unsigned int);

void LIST_vPrint(NODE *);

void LIST_vRemove(NODE **, unsigned int);

_Bool LIST_bEmpty(NODE *);


void main(int argc, char *argv[])
{
#pragma warning(disable : 4996).
	NODE *stNodFirst = NULL;
	unsigned int u32NewElement = 0, u32Element = 0;
	unsigned int u32Option = 0;


	printf("\n Handling lists \n");

	while(1)
	{
		printf("\n\n [1] Add element \n");
		printf("\n [2] Print list \n");
		printf("\n [3] Add a node after another node \n");
		printf("\n [4] Remove a node \n");
		printf("\n [5] Exit \n");
		printf("\n\n Add an option \n");
		scanf("%d", &u32Option);

		switch (u32Option)
		{
		case 1:
				printf("\n Add element \n");
				scanf("%d", &u32NewElement);
				stNodFirst = LIST_stNodCreate(stNodFirst, u32NewElement);

			break;

		case 2:
				printf("\n List \n");
				LIST_vPrint(stNodFirst);
			break;


		case 3:
				if (LIST_bEmpty(stNodFirst) == 0)
				{
					printf("\n Add new element \n");
					scanf("%d", &u32NewElement);
					printf("\n Add the element that, you want to be introduced after the new element\n");
					scanf("%d", &u32Element);
					LIST_vAdd(stNodFirst, u32NewElement, u32Element);
				}
			break;

		case 4:
				if (LIST_bEmpty(stNodFirst) == 1)
				{
					printf("Vacia");
				}
			
				else
				{
					printf("\n Add element to be removed  \n");
					scanf("%d", &u32NewElement);
					LIST_vRemove(&stNodFirst, u32NewElement);
				}
			break;

		case 5:
				exit(0);
		}
	} 
}


NODE* LIST_stNodCreate(NODE *stNode, unsigned int u32element)
{
	NODE *stNodeNew;

	stNodeNew = (NODE*)malloc(sizeof(NODE));

	if (stNodeNew != NULL)
	{
		stNodeNew->u32element = u32element;            
		stNodeNew->stNode_link = stNode;/*Move node*/
		stNode = stNodeNew;
	}

	else {
		printf("\n  failure of allocation.");
	}

	return stNodeNew;
}

void LIST_vAdd(NODE *stNode, unsigned int u32number, unsigned int u32NumberBefor)
{
	NODE *stNodeNew = NULL; 
	NODE *stNodeAfter = NULL;

	_Bool bFlag = 0;

	stNodeNew = (NODE *)calloc(1, sizeof(NODE));

	if (stNodeNew != NULL)
	{
		stNodeNew->u32element = u32number;
		stNodeAfter = stNode;

		while (stNode != NULL)
		{
			if (stNode->u32element == u32NumberBefor)
			{
				printf("Data has been found");
				bFlag = 1;

				stNodeAfter = stNode->stNode_link;
				stNode->stNode_link = stNodeNew;
				stNodeNew->stNode_link = stNodeAfter;
			}

			stNode = stNode->stNode_link;
		}
		if (bFlag == 0)
			printf("\n Data has not been found \n");
	}
}

void LIST_vPrint(NODE *stNode)
{
	while (stNode != NULL)
	{
		printf(" --> {%d , Node direction %d}", stNode->u32element, stNode);
		stNode = stNode->stNode_link;/*move until null*/
	}
	printf("-->NULL");
}

void LIST_vRemove(NODE **stNode, unsigned int u32Number)
{
	_Bool bFlag = 0;
	NODE *stNodeTemp = NULL;
	NODE *stNodeBefore = NULL;
	NODE *stNodeFirst;

	stNodeFirst = *stNode;

	while ( (*stNode != NULL) && (0 == bFlag))
	{
		if ((*stNode)->u32element == u32Number)
		{
			printf("Data has been found");
			bFlag = 1;

			if (*stNode == stNodeFirst) /*First node*/
			{
				stNodeTemp = *stNode;
				stNodeTemp = (*stNode)->stNode_link;
				free(*stNode);
				*stNode = stNodeTemp;
			}

			else
			{
				stNodeTemp = (*stNode)->stNode_link;
				stNodeBefore->stNode_link = stNodeTemp;
				free(*stNode);
				*stNode = stNodeFirst;
			}
		}

		else
		{
			stNodeBefore = *stNode;
			*stNode = (*stNode)->stNode_link;
		}
		
	}

	if (bFlag == 0)
	{
		printf("\n Data has not been found \n");
		*stNode = stNodeFirst;
	}
		
}

_Bool LIST_bEmpty(NODE *stNode)
{
	if (stNode == NULL)
		return 1;

	else
		return 0;
}
