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
	AirCompany aCop;
	aCop.addPlanes(airplanes1);

	
	enum Tastks { Print = 1, SortByRangeOfFlight, SortByFuel,FindPlaneByFuel, ChangeName, Exit };
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "Enter\n1.Print airplanes\n2.Sort by range of flight\n3.Sort by fuel consumption\n";
		cout << "4.Find airplanes by fuel consumption\n5.Change name of the plane\n6.Exit\n";
		size_t task;
		cin >> task;
		switch (task)
		{
		case Print:
		{
			system("cls");
			cout << "Airplanes:\n";
			std::copy(airplanes1.begin(), airplanes1.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"));
			system("pause");
		}
		break;
		case SortByRangeOfFlight:
		{
			system("cls");
			cout << "Airplanes:\n";
			std::sort(airplanes1.begin(), airplanes1.end(), // сортировка по дальности полета
				[](BaseAirplane* b1, BaseAirplane* b2)
				{
					if (b1->getRange() < b2->getRange())
						return true;
					else
						return false;
				}
			);
			std::copy(airplanes1.begin(), airplanes1.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"));
			system("pause");
		}
		break;
		case FindPlaneByFuel:
		{
			system("cls");
			double from = 0, to = 0;
			cout << "Enter range from\n";
			cin >> from;
			cout << "to\n";
			cin >> to;
			cout << "Airplanes:\n";
			aCop.findAirplaneByFuel(from,to);
			system("pause");
		}
		break;
		case SortByFuel:
		{
			system("cls");
			cout << "Airplanes:\n";
			std::sort(airplanes1.begin(), airplanes1.end(), // сортировка по дальности полета
				[](BaseAirplane* b1, BaseAirplane* b2)
				{
					if (b1->getFuelConsumption() < b2->getFuelConsumption())
						return true;
					else
						return false;
				}
			);
			std::copy(airplanes1.begin(), airplanes1.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"));
			system("pause");
		}
		break;
		case ChangeName:
		{
			system("cls");
			string oldName,newName;
			cout << "Enter old name\n";
			cin.ignore();
			getline(cin,oldName);
			cout << "Enter new name\n";
			cin.ignore();
			getline(cin, newName);
			aCop.change(oldName,newName);
			system("pause");
		}
		break;
		case Exit:
		{
			flag = false;
			break;
		}

		default:
			cout << "There is no such point of menu\n";
			break;
		}
	}
}