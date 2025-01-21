#pragma once

#include "Person.h"

//ディーラークラス
class Dealer : public Person 
{
protected:
	//ゲーム実行
	void playBase(Shoe* shoe);

};