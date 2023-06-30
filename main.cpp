#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���ȎQ�ƍ\����
typedef struct CELL
{
	char str[100];
	CELL *next;
}CELL;

enum Scene
{
	START,
	INDEX,
	INSERT,
	DELETE
};

//���X�g�̈ꗗ��\������֐�
void Index(CELL *endCell, bool &processEnd);
//�Ō���ɃZ����ǉ�����֐�
void Create(CELL *endCell, const char *buf, const int strSize,bool &processEnd);
//���X�g�̍Ō�����폜
void Delete(CELL *endCell, bool &processEnd);

int main()
{
	const int strSize = 100;
	char str[strSize];
	float strVal = 0;
	bool processEnd = false;

	Scene scene = START;
	float select = 0;
	int val = 0;
	//�擪�ɓ��e����̃Z����錾
	CELL head;
	head.next = nullptr;

	while (true)
	{
		switch (scene)
		{
		case START://�������j���[

			printf("[�v�f�̑���]\n");
			printf("[1.�v�f�̈ꗗ�\��]\n");
			printf("[2.�Ō���ɗv�f�̑}��]\n");
			printf("[3.�Ō���̗v�f�̍폜]\n\n");
			printf("----------------------\n");
			printf("�����I�����Ă�������\n");
			scanf_s("%f", &select);

			if (select == 1.0f)
			{
				processEnd = false;
				scene = INDEX;
			}
			else if (select == 2.0f)
			{
				processEnd = false;
				scene = INSERT;
			}
			else if (select == 3.0f)
			{
				processEnd = false;
				scene = DELETE;
			}

			break;

		case INDEX://�v�f�̕\��

			if (!processEnd)
			{
				Index(&head,processEnd);
				printf("9.�v�f����ɖ߂�\n");
			}
			
			scanf_s("%f", &select);
			if (select == 9.0f)
			{
				scene = START;
			}
			else
			{
				printf("9��I��ł�������\n");
			}

			break;

		case INSERT://�}��

			if (!processEnd)
			{
				printf("[���X�g�v�f�̑}��]\n\n");
				printf("�ǉ�����v�f�̒l����͂��Ă�������\n");

				scanf_s("%s", &str, 20);
				//�Ō���ɃZ����ǉ�
				printf("�v�f[%s]�����X�g�̍Ō���ɑ}������܂���\n", str);
				printf("----------------------\n");
				Create(&head, str, strSize,processEnd);
			}			

			printf("9.�v�f����ɖ߂�\n");
			scanf_s("%f", &select);
			if (select == 9.0f)
			{
				scene = START;
			}
			else
			{
				printf("\n9��I��ŉ�����\n\n");
			}

			break;

		case DELETE:

			if (!processEnd)
			{
				printf("[�v�f�̍폜]\n\n");
				printf("�Ō���̗v�f���폜���܂���\n");
				printf("----------------------\n");
				Delete(&head, processEnd);
			}

			printf("9.�v�f����ɖ߂�\n");
			scanf_s("%f", &select);
			if (select == 9.0f)
			{
				scene = START;
			}
			else
			{
				printf("\n9��I��ŉ�����\n\n");
			}

			break;

		default:

			printf("�Ӑ}���Ȃ����͂��s���܂����B�������j���[�ɖ߂�܂�\n");

			scene = START;

			break;
		}
	}

	return 0;
}

void Index(CELL *endCell, bool &processEnd)
{
	int cellNumber = 0;

	printf("[�v�f�̈ꗗ�\��]\n");

	printf("�v�f�ꗗ : {\n");
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
	printf("\n}\n");

	if (cellNumber == 0)
	{		
		printf("�v�f�ꗗ : �v�f����\n");
	}
	printf("�v�f�� : %d\n", cellNumber);
	printf("----------------------\n");
	processEnd = true;
}

void Create(CELL* endCell, const char* buf, const int strSize, bool& processEnd)
{
	/*Step1.�V�K�ɃZ����ǉ�*/
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, strSize, buf);
	newCell->next = nullptr;

	/*Step2.�ǉ�����O�̍Ō��������*/
	while (endCell->next != NULL)
	{
		endCell = endCell->next;
	}

	/*Step3.�ǉ�����O�̍Ō���ɐV�K�Z���̃|�C���^����*/
	endCell->next = newCell;

	processEnd = true;
}

void Delete(CELL *endCell, bool &processEnd)
{
	CELL *prevCell;
	prevCell = (CELL*)malloc(sizeof(CELL));
	while (endCell->next != NULL)
	{
		prevCell = endCell;
		endCell = endCell->next;
	}
	free; endCell;
	prevCell->next = nullptr;
}