#include <stdio.h>
#include <stdlib.h>

//���ȎQ�ƍ\����
typedef struct CELL
{
	int val;
	CELL *next;
}CELL;

//�Ō���ɃZ����ǉ�����֐�
void Create(CELL *endCell,int val);
//���X�g�̈ꗗ��\������֐�
void Index(CELL *endCell);

int main()
{
	int val;
	//�擪�ɓ��e����̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		scanf_s("%d", &val);
		//�Ō���ɃZ����ǉ�
		Create(&head, val);
		//���X�g�ꗗ��\��
		Index(&head);
	}

	return 0;
}

void Create(CELL *endCell, int val)
{
	/*Step1.�V�K�ɃZ����ǉ�*/
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
	newCell->next = nullptr;

	/*Step2.�ǉ�����O�̍Ō��������*/
	while (endCell->next !=NULL)
	{
		endCell = endCell->next;
	}

	/*Step3.�ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����*/
	endCell->next = newCell;
}

void Index(CELL *endCell)
{
	printf("[");
	while (endCell->next != NULL)
	{
		//next�ɉ����l�������Ă���ԏo��
		endCell = endCell->next;
		printf("%d", endCell->val);
		if (endCell->next != NULL)
		{
			printf(",");
		}
	}
	printf("]\n");
}