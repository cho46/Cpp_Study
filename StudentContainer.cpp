#include "StudentContainer.h"
#include <iostream>
#pragma warning(disable:4996)
using std::cout;
using std::endl;

void ScoreContainer::addScore(const char* name, int lan, int mat, int eng)
{
	if (index < SCORE_SIZE)
		p[index++] = new Score(name, lan, mat, eng);
}

void ScoreContainer::displayScore() const
{
	for (int i = 0; i < index; i++)
		p[i]->displayScore();
}

void ScoreContainer::searchStudent(const char* find)
{
	int checkfind = 0;
	char* finder = new char[strlen(find) + 1];
	strcpy(finder, find);
	for (int i = 0; i < index; i++)
	{
		if (strcmp(p[i]->getName(),finder)==0)
		{
			cout << "해당 학생을 찾았습니다. 성적을 표시합니다.\n" << "이름: " << p[i]->getName() << "\n[국어]: " << p[i]->getLan() << "\n[수학]: " << p[i]->getMat() << "\n[영어]: " << p[i]->getEng();
			checkfind = 1;
		}
	}
	if (checkfind == 0)
		cout << "해당학생은 존재하지 않습니다.";
}

void ScoreContainer::averageScore()
{
	double tlan = 0;
	double tmat = 0;
	double teng = 0;
	for (int i = 0; i < index; i++)
	{
		tlan += p[i]->getLan();
		tmat += p[i]->getMat();
		teng += p[i]->getEng();
	}
	tlan = tlan / index;
	tmat = tmat / index;
	teng = teng / index;
	cout << "모든 학생들의 총 평균입니다.\n" << "[국어] : " << tlan <<"\t" << "[수학] : " << tmat <<"\t" << "[영어] : " << teng;
}

int ScoreContainer::highScore()
{
	int highScore = 0;
	for (int i = 0; i < index; i++)
	{
		int sScore = (p[i]->getEng() + p[i]->getLan() + p[i]->getMat()) / 3;
		if (highScore < sScore)
			highScore = sScore;
	}
	return highScore;
}

int ScoreContainer::lowScore()
{
	int lowScore = 100;
	for (int i = 0; i < index; i++)
	{
		int sScore = (p[i]->getEng() + p[i]->getLan() + p[i]->getMat()) / 3;
		if (lowScore > sScore)
			lowScore = sScore;
	}
	return lowScore;
}

ScoreContainer::~ScoreContainer()
{
	for (int i = 0; i < index; i++)
		delete p[i];
}
