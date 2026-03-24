#include <iostream>
#include <cmath>
#include <string>

const double PI = acos(-1.0);

double radToDeg(double rad)
{
	return rad * 180 / PI;
}

class Triangle
{
private:
	double a, b, c; // стороны
	double A, B, C; // углы
	bool isValid;
	double perimeter;
	double semiperimeter;
	double area;
	double h_a, h_b, h_c;

public:
	Triangle() : a(0), b(0), c(0), A(0), B(0), C(0), isValid(false), perimeter(0), semiperimeter(0), area(0), h_a(0), h_b(0), h_c(0) {}

	Triangle(double a, double b, double c, double A, double B, double C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}

	void DoesExist()
	{
		std::string tmp;
		if (a < 0 || b < 0 || c < 0 || ((a + b) <= c) || ((b + c) <= a) || ((a + c) <= b))
		{
			std::cout << "Error! Bad sides!\n";
			this->isValid = false;
		}
		else if (((A < 0 || B < 0 || C < 0 || A + B + C != 180)) || ((a == b && b == c) && (A != 60 || B != 60 || C != 60)))
		{
			std::cout << "Error! Bad angles!\n";
			std::cout << "Do you want to recalculate the angles? (y/n): ";
			std::cin >> tmp;
			if (tmp == "y")
			{
				if ((a == b && b == c) && (A != 60 || B != 60 || C != 60))
				{
					A = 60;
					B = 60;
					C = 60;
					isValid = true;
				}
				else
				{
					this->A = radToDeg(acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)));
					this->B = radToDeg(acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)));
					this->C = radToDeg(acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)));
					std::cout << "right angles: a = " << A << "; b = " << B << "; c = " << C << ";\n";
					this->isValid = true;
				}
				std::cout << "right angles: a = " << A << "; b = " << B << "; c = " << C << ";\n";
			}
			else
			{
				this->isValid = false;
			}
		}
		else
		{
			this->isValid = true;
<<<<<<<<< Temporary merge branch 1
			/*this->A = A_valid;
			this->B = B_valid;
			this->C = C_valid;*/
=========
>>>>>>>>> Temporary merge branch 2
		}
	}

	void EnterData()
	{
		std::cin >> this->a;
		std::cin >> this->b;
		std::cin >> this->c;
		std::cin >> this->A;
		std::cin >> this->B;
		std::cin >> this->C;
		DoesExist();
	}

	void EditData()
	{
		std::string tmp;
		std::cout << "Do you want to edit anything? (y/n): ";
		std::cin >> tmp;
		if (tmp == "y")
		{
			char choice;
			std::cout << "Which one? (a/b/c/A/B/C): ";
			std::cin >> choice;
			bool valid = (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'A' || choice == 'B' || choice == 'C');
			valid ? std::cout << "Enter new value: " : std::cout << "Invalid choice!\n";
			switch (choice)
			{
			case 'a': std::cin >> a; break;
			case 'b': std::cin >> b; break;
			case 'c': std::cin >> c; break;
			case 'A': std::cin >> A; break;
			case 'B': std::cin >> B; break;
			case 'C': std::cin >> C; break;
			default: break;
			}
		}
		DoesExist();
	}

	void TriangleType()
	{
		if (a == b && b == c && this->isValid)
		{
			std::cout << "Our triangle is equilateral!\n";
		}
		else if ((a == b || b == c || a == c) && this->isValid)
		{
			std::cout << "Our triangle is isosceles!\n";
		}
		else if (pow(a, 2) == pow(b, 2) + pow(c, 2))
		{
			std::cout << "Our triangle is right-angled!\n";
		}
		else
		{
			std::cout << "Our triangle isn't equilateral, isosceles or right-angled.\n";
		}
	}

	void CalculatePerimeter()
	{
		this->perimeter = a + b + c;
		std::cout << "Perimeter is: " << this->perimeter << "\n";
		this->semiperimeter = this->perimeter / 2;
	}

	void CalculateArea()
	{
		this->area = sqrt(this->semiperimeter * (this->semiperimeter - a) * (this->semiperimeter - b) * (this->semiperimeter - c));
		std::cout << "Area is: " << this->area << "\n";
	}

	void CalculateHeights()
	{
		this->h_a = 2 * area / a;
		this->h_b = 2 * area / b;
		this->h_c = 2 * area / c;
		std::cout << "heights (a, b, c): " << h_a << ", " << h_b << ", " << h_c << ";\n";
	}

	bool IsValid() const
	{
		return isValid;
	}
};

int main()
{
	int i = 0;
	Triangle t(5, 5, 5, 60, 60, 60), u;
	t.DoesExist();
	t.CalculatePerimeter();
	t.CalculateArea();
	t.CalculateHeights();
	t.TriangleType();
	std::cout << " .C" << std::endl;
	std::cout << " |\\" << std::endl;
	std::cout << "b| \\ a" << std::endl;
	std::cout << " |  \\" << std::endl;
	std::cout << "A|___\\B" << std::endl;
	std::cout << "   c" << std::endl;
	std::cout << "It's our triangle.\nEnter the variables in this order: a, b, c, A, B, C.\n";
	u.EnterData();
	u.EditData();
	if (u.IsValid())
	{
		u.CalculatePerimeter();
		u.CalculateArea();
		u.CalculateHeights();
		u.TriangleType();
	}
	else
	{
		std::cout << "Triangle is invalid!\n";
	}
}

