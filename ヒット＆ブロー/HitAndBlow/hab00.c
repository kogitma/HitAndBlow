#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIGIT 4	//桁数
#define MAX 9 //1～使用する数字の範囲（設定できる最大は９）

void shuffle(int array[], unsigned int size) {	//フィッシャー-イェーツのシャッフル
	unsigned int i, j;
	int tmp;

	i = size - 1;

	while (i > 0) {
		j = rand() % (i + 1);

		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;

		i--;
	}
}

int main(void) {
	int n, hit = 0, blow = 0, cnt = 0;
	int gue[DIGIT], ans[MAX];

	srand((unsigned int)time(NULL));	//乱数の種を設定

	printf("ヒット＆ブローを開始します。\n");
	printf("1～%dまでの数字から並べられたランダムな%d桁の数字を予想してください。\n\n", MAX, DIGIT);

	//答えを作成
	for (int i = 0; i < MAX; i++) {
		ans[i] = i + 1;
	}
	shuffle(ans, MAX);

	/*
	//答え確認(テスト用)
	for (int i = 0; i < MAX; i++) {	
		printf("%d", ans[i]);
	}
	*/

	//桁の確認用変数を生成
	int k_short = 1, k_long;

	for (int i = 1; i < DIGIT; i++) {
		k_short *= 10;
	}
	k_long = k_short * 10;

	do
	{				
		//答えの数字を宣言
		printf("あなたの予想を%d桁で入力:", DIGIT);
		scanf("%d", &n);

		//入力された桁の確認
		if (n < k_short || n >= k_long) {
			printf("%d桁で入力してください。\n", DIGIT);
			continue;
		}

		//配列に変換
		for (int i = DIGIT - 1; i >= 0; i--)
		{
			gue[i] = n % 10;
			n /= 10;
		}

		//HITとBLOWを確認
		for (int i = 0; i < DIGIT ; i++)
		{
			if (gue[i] == ans[i])
				hit++;
			for (int j = 0; j < DIGIT; j++)
			{
				if (gue[i] == ans[j] && i != j) {
						blow++;
				}
			}
			
		}
		//試行回数をカウント
		cnt++;

		//もしHITが桁数と同じになった場合
		if (hit == DIGIT) {
			printf("正解！\n");
			printf("%d回でクリアできました！\n", cnt);
				break;
		}
		//HITとBLOWを表示
		printf("Hit:%d Blow:%d\n\n", hit, blow);

		//HITとBLOWをリセット
		hit = 0;
		blow = 0;

	} while (1);
}