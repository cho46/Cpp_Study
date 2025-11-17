#pragma once
#include <iostream>
#include "CharacterContainer.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	Charatercontainer cc;
	cc.addCharacter("Player1",87,-3);
	cc.addCharacter("Enermy1", 1545, 28);
	cc.addCharacter("NPC1", 3478, 22);

	cout << "생성된 캐릭터는 " << cc.getCharacterCount() << "개 입니다.";

	cc.displayCharacter();
	cc.displayAllDistance();
	return 0;
}