#include <stdio.h>
#include <stdlib.h>

//双方向リスト用自己参照構造体
typedef struct CELL
{
	int val;
	CELL *prev;
	CELL *next;
}CELL;

//最後尾にセルを追加する関数
void Create(CELL *currentCell, int val);
//一覧出力
void Index(CELL *endCell);
//
CELL *GetInsertListAddress(CELL *endCell,int iterator);

int main()
{
	int iterator;
	int inputVal;
	CELL* insertCell;

	//先頭のセルの宣言
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	while (true)
	{
		printf("何番目のセルの後ろに挿入しますか?\n");
		scanf_s("%d", &iterator);

		printf("挿入する値を入力してください\n");
		scanf_s("%d", &inputVal);

		//挿入する箇所のアドレスを取得
		insertCell = GetInsertListAddress(&head,iterator);
		//任意のセルの後ろに追加
		Create(insertCell, inputVal);

		//リスト一覧の表示
		Index(&head);
	}

	return 0;
}

void Create(CELL* currentCell, int val)
{
	//新規にセルを作成
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	/*指定したセルの次のセルの
	「前のセルのポインタ」に新規セルのアドレスを代入*/
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
		//nextに何か入ってる間出力
		endCell = endCell->next;
		printf("%d", no);
		printf("%p", endCell->prev);
		printf("%5d", endCell->val);//5桁まで右揃え
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
			//最後尾まできたらブレイク
			break;
		}
	}
	return endCell;
}
