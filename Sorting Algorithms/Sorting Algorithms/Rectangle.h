#pragma once
class Rectangle
{
private:
	double width, height, area;
public:
	Rectangle();
	Rectangle(double width, double height);

	void calculateArea();					//calculateArea�� void�� �����ؼ� ������ ��ü������ �����ع�����, �ƴϸ� double�� ��ȯ�ؼ� setArea�޼ҵ� ���� ���� ������ ���
	double getArea();
};

