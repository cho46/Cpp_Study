#pragma once

class Score
{

public:
	Score();
	Score(const char* name, int lan, int mat, int eng);
	~Score();
	Score(const Score& other);

	void displayScore();
public:
	inline const char* getName() const { return name; }
	inline int getLan() const { return lan; }
	inline int getMat() const { return mat; }
	inline int getEng() const { return eng; }

public:
	inline void setName(const char*name);
	inline void setLan(int lan);
	inline void setMat(int mat);
	inline void setEng(int eng);


private:
	char* name = nullptr;
	int lan = 0;
	int mat = 0;
	int eng = 0;
};