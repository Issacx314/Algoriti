/***************************************************************************
*=====================      Copyright by Don Issac      ===============
****************************************************************************
* Title        : Permut
*
* Description  : Code used to generate a permutation sequence for 1<= N <= 9 elements
*                
* Environment  : SBC
*
* Responsible  : Issac Jim�nez
*****************************************************************************************************/

#include <stdio.h>
#include <conio.h>

#define NUMCHARS    11
#define ODD			2

void PERM__vSwap(unsigned char u8Pos_small, unsigned char u8Pos_big, char **pps8Matriz)
{
	char *s8Temp;

	s8Temp = pps8Matriz[u8Pos_big];
	pps8Matriz[u8Pos_big] = pps8Matriz[u8Pos_small];
	pps8Matriz[u8Pos_small] = s8Temp;
}


/* Generating permutation using Heap Algorithm */
void heapPermutation(char **pps8Matrix, unsigned int u32Ren, unsigned int u32Size)
{
	unsigned char u8count = 0;

	/* if size becomes 1 then prints the obtained permutation*/ 
	if (1 == u32Ren)
	{	
		for (u8count = 0; u8count < u32Size; u8count++)
			printf("%s%c", pps8Matrix[u8count], u8count == u32Size - 1 ? '\n' : ' ');
		
		return;
	}

	for (u8count = 0; u8count < u32Ren; u8count++)
	{
		heapPermutation(pps8Matrix, u32Ren - 1, u32Size);

		if (1 == u32Ren % ODD) /* if size is odd, swap first and last element*/
		{
			PERM__vSwap(0, (u32Ren - 1), pps8Matrix);
		}
		else/* If size is even, swap ith and last element */
		{
			PERM__vSwap(u8count, (u32Ren - 1), pps8Matrix);
		}
			
	}
}


void main(int argc, char *argv[])
{
	char **pps8InputMAtrix;
	unsigned int u32Ren;
	unsigned char u8Count;

	_Bool boMemInvalid = 0;

#pragma warning(disable : 4996).
	printf("\n Program to generate permutations of n numbers \n");

	printf("\n Introduce number of elemnts 1<= N <= 9 to calculate their permutations:");
	scanf("%d", &u32Ren);
	pps8InputMAtrix = (char **) calloc(u32Ren, sizeof(char*)); /*Reserve u32Ren strings. heap memory */

	if (NULL != pps8InputMAtrix)
	{
		printf("\n Introduce the characters \n");

		for (u8Count = 0; u8Count < u32Ren; u8Count++)
		{
			pps8InputMAtrix[u8Count] = (char *)calloc(NUMCHARS, sizeof(char)); /*Reserve u32Ren strings of 11 characters*/
			                                                                   /*Calloc sets 0 to all of them*/
			if (NULL == pps8InputMAtrix[u8Count])
			{
				boMemInvalid = 1;
			}
		}

		if (0 == boMemInvalid) /*Memory reserved correctly*/
		{
			for (u8Count = 0; u8Count < u32Ren; u8Count++)
			{
				printf(":");
				scanf("%s", pps8InputMAtrix[u8Count]);
			}

			heapPermutation(pps8InputMAtrix, u32Ren, u32Ren);


			for (u8Count = 0; u8Count < u32Ren; u8Count++)
				free(pps8InputMAtrix[u8Count]);
		}

		else {
			printf("\n  failure of allocation.");
		}
		

		free(pps8InputMAtrix);
	}

	else {
		printf("\n  failure of allocation.");
	}

	_getch();
}