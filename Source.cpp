#include "Header.h"
class MyException {};
BaseAirplane* getptr(char marker)
{
	if (marker == 'p') return new PassengerPlane();
	else if (marker == 't') return new TransportPlane();
}

int main()
{
	vector<BaseAirplane*> airplanes1;
	std::ifstream in("airplanes.txt");
	while (!in.eof())
	{
		char s;
		in >> s;
		BaseAirplane* ptr = getptr(s);
		airplanes1.push_back(ptr);
		airplanes1.back()->read(in);
	}
	std::copy(airplanes1.begin(), airplanes1.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n")); // вывод
	std::sort(airplanes1.begin(), airplanes1.end(), // сортировка по дальности полета
		[](BaseAirplane* b1, BaseAirplane* b2)
		{
			if (b1->getRange() < b2->getRange())
				return true;
			else
				return false;
		}
	);
	cout << endl;
	std::copy(airplanes1.begin(), airplanes1.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"));// вывод
	AirCompany aCop;
	aCop.addPlanes(airplanes1);
	cout << endl;
	aCop.findAirplaneByFuel(5, 15);

}