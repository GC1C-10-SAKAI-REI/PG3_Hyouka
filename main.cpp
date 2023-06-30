#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//自己参照構造体
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

//最後尾にセルを追加する関数
void Create(CELL *endCell, const char *buf, const int strSize,bool &processEnd);
//リストの一覧を表示する関数
void Index(CELL *endCell, bool &processEnd);
//
void Delete(CELL *endCell, bool &processEnd);

int main()
{
	const int strSize = 100;
	char str[strSize];
	float strVal = 0;
	bool processEnd = false;

	Scene scene = START;
	float select = 0;
	//先頭に内容が空のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		switch (scene)
		{
		case START://初期メニュー

			select = 0;
			printf("[要素の操作]\n");
			printf("[1.要素の一覧表示]\n");
			printf("[2.最後尾に要素の挿入]\n");
			printf("[3.最後尾の要素の削除]\n\n");
			printf("----------------------\n");
			printf("操作を選択してください\n");
			
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
			else
			{
				printf("\n1~3の整数で選んで下さい\n\n");
			}

			break;

		case INDEX://要素の表示

			if (!processEnd)
			{
				Index(&head,processEnd);
				printf("9.要素操作に戻る\n");
			}
			
			scanf_s("%f", &select);
			if (select == 9.0f)
			{
				scene = START;
			}
			else
			{
				printf("9を選んでください\n");
			}

			break;

		case INSERT://挿入

			if (!processEnd)
			{
				printf("[リスト要素の挿入]\n\n");
				printf("追加する要素の値を入力してください\n");

				scanf_s("%s", &str, 20);
				//最後尾にセルを追加
				printf("要素[%s]がリストの最後尾に挿入されました\n", str);
				printf("----------------------\n");
				Create(&head, str, strSize,processEnd);
			}
			

			printf("9.要素操作に戻る\n");
			scanf_s("%f", &select);
			if (select == 9.0f)
			{
				scene = START;
			}
			else
			{
				printf("\n9を選んで下さい\n\n");
			}

			break;

		case DELETE:



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

void Index(CELL *endCell, bool &processEnd)
{
	int cellNumber = 0;

	printf("[要素の一覧表示]\n");

	printf("要素一覧 : {\n");
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
	printf("\n}\n");

	if (cellNumber == 0)
	{		
		printf("要素一覧 : 要素無し\n");
	}
	printf("要素数 : %d\n", cellNumber);
	printf("----------------------\n");
	processEnd = true;
}

void Delete(CELL* endCell, bool& processEnd)
{
}

void Create(CELL *endCell, const char *buf, const int strSize, bool &processEnd)
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

	processEnd = true;
}