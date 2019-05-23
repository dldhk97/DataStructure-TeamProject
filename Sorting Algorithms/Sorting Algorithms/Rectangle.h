#pragma once
class Rectangle
{
private:
	double width, height, area;
public:
	Rectangle();
	Rectangle(double width, double height);

	void calculateArea();					//calculateArea를 void로 선언해서 면적을 자체적으로 저장해버릴지, 아니면 double로 반환해서 setArea메소드 만들어서 설정 해줄지 고민
	double getArea();
};

