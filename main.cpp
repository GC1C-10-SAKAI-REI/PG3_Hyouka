#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���ȎQ�ƍ\����
typedef struct CELL
{
	char str[20];
	CELL *next;
}CELL;

enum Scene
{
	START,
	INDEX,
	INSERT,
	DELETE
};

//�Ō���ɃZ����ǉ�����֐�
void Create(CELL *endCell, const char *buf, const int strSize);
//���X�g�̈ꗗ��\������֐�
void Index(CELL *endCell);

int main()
{
	const int strSize = 20;
	char str[strSize];
	int strVal = 0;

	Scene scene = START;
	int select = 0;
	//�擪�ɓ��e����̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		switch (scene)
		{
		case START:

			printf("[�v�f�̑���]\n");
			printf("[1.�v�f�̈ꗗ�\��]\n");
			printf("[2.�Ō���ɗv�f�̑}��]\n");
			printf("[3.�Ō���̗v�f�̍폜]\n\n");
			printf("----------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%d", &select);

			if (select == 1)
			{
				scene = INDEX;
				break;
			}
			else if (select == 2)
			{
				scene = INSERT;
				break;
			}
			else if (select == 3)
			{
				scene = DELETE;
				break;
			}
			else
			{
				printf("1~3�̐����őI��ŉ�����\n");
				scanf_s("%d", &select);
				break;
			}

			break;

		case INDEX:

			Index(&head);
			printf("9.�v�f����ɖ߂�\n");
			scanf_s("%d", &select);
			if (select == 9)
			{
				scene = START;
			}

			break;
		case INSERT:
			break;
		case DELETE:
			break;
		default:
			break;
		}
		//printf("�D���Ȃ����i����͂��Ă�������\n_\n");
		//scanf_s("%s", &str, 20);
		////�Ō���ɃZ����ǉ�
		//Create(&head, str,strSize);
		////���X�g�ꗗ��\��
		//Index(&head);
	}

	return 0;
}

void Create(CELL *endCell, const char *buf, const int strSize)
{
	/*Step1.�V�K�ɃZ����ǉ�*/
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, strSize, buf);
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
	int cellVal = 0;
	int cellNumber = 0;

	printf("[�v�f�̈ꗗ�\��]");
	while (endCell->next != NULL)
	{
		cellVal++;
	}
	printf("�v�f�� : %d\n", cellVal);
	if (cellVal == 0)
	{
		printf("�v�f�ꗗ : �v�f����\n");
	}
	else
	{
		printf("�v�f�ꗗ : {");
		while (endCell->next != NULL)
		{
			//next�ɉ����l�������Ă���ԏo��
			endCell = endCell->next;
			printf("%d : [%s]", cellNumber, endCell->str);
			if (endCell->next != NULL)
			{
				printf(",\n");
			}
			cellNumber++;
		}
		printf("}\n");
	}
	printf("----------------------\n");
}