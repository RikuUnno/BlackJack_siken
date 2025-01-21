#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//

// ★★★★★★★★★★★★★★★★
static void showResult(Person* p, Person* dealer)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	cout << p->getName() << endl;
	p->showHand();
	cout << "============================" << endl;
	cout << dealer->getName() << endl;
	dealer->showHand();
	cout << "============================" << endl;

	if (p->getScore() > dealer->getScore()) {
		cout << "Player Win!" << endl;
	}
	else if (p->getScore() < dealer->getScore()) {
		cout << "Player Lose" << endl;
	}
	else {
		cout << "Push" << endl;
	}
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================" << endl;
	p->showHand();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	// test

	srand((unsigned int)time(NULL));

	enum PERSON
	{
		DEALER,
		PLAYER1,
		PLAYER2,
		PLAYER3
	};

	//各オブジェクトの生成
	Shoe shoe;
	Person* persons[] = {new Dealer("Dealer"), 
		new Player("player1"), new Player("player2"), new Player("player3"), };
	const int num = sizeof(persons) / sizeof(Person*);

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(&shoe);
		showHand(persons[i]);
	}

	//マジックナンバーになっちゃいました
	//iは0がディラー、1がプレイヤー１、2がプレイヤー２、3がプレイヤー３
	for (int i = 0; i < 4; i++)
	{
		//プレイヤーに2枚目を配布
		persons[i]->hit(&shoe);
		showHand(persons[i]);
	}

	// ----　勝負開始
	//プレイヤーの実行
	//バーストしているかどうか判別
	for (int i = 1; i < 4; i++)
	{
		if (persons[i]->play(&shoe)) {
			//バーストせずstandした

			//ディーラーの自動実行
			persons[DEALER]->play(&shoe);

			//結果の表示
			showResult(persons[i], persons[DEALER]);
		}
		else {
			cout << "Burst " << persons[i]->getName() << " Lose" << endl;
		}
	}

	cout << "====================" << endl;
	return 0;
}