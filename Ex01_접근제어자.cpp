#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class RGB
{
public: //공개: 어디서든 접근 가능
	void init(int r, int g, int b)
	{
		//유효성 체크
		/*if(isValidRange(r))
			red = r;
		if (isValidRange(g))
			green = g;
		if (isValidRange(b))
			blue = b;	*/
		setRed(r);
		setRed(g);
		setRed(b);
	}
	void showColor()
	{
		cout << "RGB(" << red << " , " << green << " , " << blue << ")" << endl;
	}
public:
	int getRed() // getter 매서드: 값을 얻어옴
	{
		return red;
	}
	int getGreen()
	{
		return green;
	}
	int getBlue()
	{
		return blue;
	}
public:
	void setRed(int a)
	{
		if (isValidRange(a))
			red = a;
	}
	void setGreen(int a)
	{
		if (isValidRange(a))
			green = a;
	}
	void setBlue(int a)
	{
		if (isValidRange(a))
			blue = a;
	}
private:
	bool isValidRange(int color)
	{
		/*if (color >= 0 && color <= 255)
			return true;
		else
			return false;
			*/
		return(color >= 0 && color <= 255);
	}
private: //비공개: 클래스 내에서만 접근 가능
	int red = 255, green = 255, blue = 255;
};




int main()
{
	RGB rgb, rgb2;
	
	rgb.init(334, 855, 35);
	rgb.setRed(12);

	rgb.showColor();

	cout << "설정된 blue 값은?"<<rgb.getBlue();




	rgb2.init(34, 67, 25);
	rgb2.showColor();
	return 0;
}