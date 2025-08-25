#include <iostream>
#include <Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		Red = 0x000000FF,
		Green = 0x0000FF00,
		Blue = 0x00FF0000,
		Yellow = 0x0000FFFF,
		Orange = 0x0000A5FF,
		White = 0x00FFFFFF
	};

	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;
	public:
		const int MIN_START_X = 100;
		const int MIN_START_Y = 100;
		const int MAX_START_X = 1000;
		const int MAX_START_Y = 600;
		Shape(Color color) :color(color) {/*Тело конструктора*/ }
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь квадрата : " << get_area() << endl;
			cout << "Периметр квадрата: " << get_perimeter() << endl;
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
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) :Shape(color)
		{
			set_width(width);
			set_height(height);
		}
		void set_width(double widht)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw() const override
		{
			HWND hwnd = GetConsoleWindow();

			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			
			::Rectangle(hdc, 200, 200, 300, 300);
			
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Стороны: " << width << "x" << height << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	
	Geometry::Square square(5, Geometry::Color::Red);
	cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата : " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	cout << "\n-------------------------------------------\n" << endl;
	square.info();

	Geometry::Rectangle rect(15, 10, Geometry::Color::Blue);
	rect.info();
	while (true)
	{
		rect.draw();
	}
}