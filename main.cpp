#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//自己参照構造体
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

//最後尾にセルを追加する関数
void Create(CELL *endCell, const char *buf, const int strSize);
//リストの一覧を表示する関数
void Index(CELL *endCell);

int main()
{
	const int strSize = 20;
	char str[strSize];
	int strVal = 0;

	Scene scene = START;
	int select = 0;
	//先頭に内容が空のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		switch (scene)
		{
		case START:

			printf("[要素の操作]\n");
			printf("[1.要素の一覧表示]\n");
			printf("[2.最後尾に要素の挿入]\n");
			printf("[3.最後尾の要素の削除]\n\n");
			printf("----------------------\n");
			printf("操作を選択してください\n");
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
				printf("1~3の整数で選んで下さい\n");
				scanf_s("%d", &select);
				break;
			}

			break;

		case INDEX:

			Index(&head);
			printf("9.要素操作に戻る\n");
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
		//printf("好きなお寿司を入力してください\n_\n");
		//scanf_s("%s", &str, 20);
		////最後尾にセルを追加
		//Create(&head, str,strSize);
		////リスト一覧を表示
		//Index(&head);
	}

	return 0;
}

void Create(CELL *endCell, const char *buf, const int strSize)
{
	/*Step1.新規にセルを追加*/
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->str, strSize, buf);
	newCell->next = nullptr;

	/*Step2.追加する前の最後尾を検索*/
	while (endCell->next !=NULL)
	{
		endCell = endCell->next;
	}

	/*Step3.追加する前の最後尾に新規セルのポインタを代入*/
	endCell->next = newCell;
}

void Index(CELL *endCell)
{
	int cellVal = 0;
	int cellNumber = 0;

	printf("[要素の一覧表示]");
	while (endCell->next != NULL)
	{
		cellVal++;
	}
	printf("要素数 : %d\n", cellVal);
	if (cellVal == 0)
	{
		printf("要素一覧 : 要素無し\n");
	}
	else
	{
		printf("要素一覧 : {");
		while (endCell->next != NULL)
		{
			//nextに何か値が入っている間出力
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