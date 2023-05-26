#include <stdio.h>
#include <stdlib.h>

//�o�������X�g�p���ȎQ�ƍ\����
typedef struct CELL
{
	int val;
	CELL *prev;
	CELL *next;
}CELL;

//�Ō���ɃZ����ǉ�����֐�
void Create(CELL *currentCell, int val);
//�ꗗ�o��
void Index(CELL *endCell);
//
CELL *GetInsertListAddress(CELL *endCell,int iterator);

int main()
{
	int iterator;
	int inputVal;
	CELL* insertCell;

	//�擪�̃Z���̐錾
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	while (true)
	{
		printf("���Ԗڂ̃Z���̌��ɑ}�����܂���?\n");
		scanf_s("%d", &iterator);

		printf("�}������l����͂��Ă�������\n");
		scanf_s("%d", &inputVal);

		//�}������ӏ��̃A�h���X���擾
		insertCell = GetInsertListAddress(&head,iterator);
		//�C�ӂ̃Z���̌��ɒǉ�
		Create(insertCell, inputVal);

		//���X�g�ꗗ�̕\��
		Index(&head);
	}

	return 0;
}

void Create(CELL* currentCell, int val)
{
	//�V�K�ɃZ�����쐬
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	/*�w�肵���Z���̎��̃Z����
	�u�O�̃Z���̃|�C���^�v�ɐV�K�Z���̃A�h���X����*/
	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void Index(CELL* endCell)
{
	int no = 1;
	while (endCell->next != nullptr)
	{
		//next�ɉ��������Ă�ԏo��
		endCell = endCell->next;
		printf("%d", no);
		printf("%p", endCell->prev);
		printf("%5d", endCell->val);//5���܂ŉE����
		printf("(%p)", endCell);
		printf("%p\n", endCell->next);
		no++;
	}
}

CELL* GetInsertListAddress(CELL* endCell, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (endCell->next)
		{
			endCell = endCell->next;
		}
		else
		{
			//�Ō���܂ł�����u���C�N
			break;
		}
	}
	return endCell;
}
