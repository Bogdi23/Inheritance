#include <iostream>
using namespace std;

enum Color
{
	Red		= 0x000000FF,
	Green	= 0x0000FF00,
	Blue	= 0x00FF0000,
	Yellow	= 0x0000FFFF,
	Orange	= 0x0000A5FF,
	White	= 0x00FFFFFF
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color) {/*Тело конструктора*/}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
	virtual void info()const
	{
		cout << "Площадь: " << get_area() << endl;
		cout << "Периметр: " << get_perimeter() << endl;
		draw();
	}
};

class Square :public Shape
{
	double side;
public:
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return 4 * side;
	}
	void draw()const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны квадрата: " << get_side() << endl;
		Shape::info();
	}
};
class Rectangle :public Shape
{
	double width, height;
public:
	Rectangle(double width, double height, Color color) :Shape(color)
	{
		set_width(width);
		set_height(height);
	}
	double get_width()const 
	{ 
		return width; 
	}
	double get_height()const 
	{ 
		return height; 
	}
	void set_width(double width) 
	{ 
		this->width = width; 
	}
	void set_height(double height) 
	{ 
		this->height = height; 
	}
	double get_area()const override 
	{ 
		return width * height; 
	}
	double get_perimeter()const override 
	{ 
		return 2 * (width + height); 
	}
	void draw()const override
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << "* ";
			cout << endl;
		}
		cout << endl;
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Ширина прямоугольника: " << get_width() << endl;
		cout << "Высота прямоугольника: " << get_height() << endl;
		Shape::info();
	}
};
class Equilateral_triangle :public Shape
{
	double side;
public:
	Equilateral_triangle(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	double get_side()const 
	{ 
		return side; 
	}
	void set_side(double side) 
	{ 
		this->side = side; 
	}
	double get_height()const
	{
		return (sqrt(3) / 2) * side;
	}
	double get_area()const override
	{
		return (sqrt(3) / 4) * side * side;
	}
	double get_perimeter()const override
	{
		return 3 * side;
	}
	void draw()const override
	{
		int n = (int)side;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i; j++) cout << " ";
			for (int j = 0; j <= i; j++) cout << "* ";
			cout << endl;
		}
		cout << endl;
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны равностороннего треугольника: " << get_side() << endl;
		cout << "Высота равностороннего треугольника: " << get_height() << endl;
		Shape::info();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	
	Square square(5, Color::Red);
	cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата : " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	cout << "\n-------------------------------------------\n" << endl;
	square.info();
	cout << "\n-------------------------------------------\n" << endl;
	Rectangle rectangle(7, 3, Color::Blue);
	rectangle.info();
	cout << "\n-------------------------------------------\n" << endl;
	Equilateral_triangle equilateral_triangle(6, Color::Yellow);
	equilateral_triangle.info();
	cout << "\n-------------------------------------------\n" << endl;

}