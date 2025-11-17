#pragma once
#include "Student.h"

class ScoreContainer
{
public:
	void addScore(const char* name, int lan, int mat, int eng);//추가
	void displayScore() const;//보여주기
	void searchStudent(const char*find);//찾기
	void averageScore();//토탈평균
	int highScore();//최고 점수 학생의 평균
	int lowScore();//최저 점수 학생의 평균
public:
	~ScoreContainer();
private:
	static const int SCORE_SIZE = 100;
	Score* p[SCORE_SIZE] = { nullptr };
	int index = 0;
};