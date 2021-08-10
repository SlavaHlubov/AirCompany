#pragma once
#include"Header.h"
class BaseAirplane
{
public:
	BaseAirplane();
	virtual ~BaseAirplane();
	virtual void read(std::istream&);
	virtual std::ostream& print();
	string getName()const { return name; }
	double getSpeed()const{ return speed; }
	double getRange()const { return range; }
	double getFuelConsumption()const { return fuelConsumption; }
	void setName(const string& str) { name = str; }
private:
	string name;
	double speed;
	double range;
	double fuelConsumption;
};

BaseAirplane::BaseAirplane()
{
}

BaseAirplane::~BaseAirplane()
{
}
void BaseAirplane::read(std::istream& in)
{
	in >> name >> speed >> range >> fuelConsumption;
}
std::ostream& BaseAirplane::print()
{
	std::cout << " name: " << name << " speed(km/h): " << speed << " range(km): " << range << " fuel(t/h): "  << fuelConsumption <<  " ";
	return std::cout;
}
std::ostream& operator<<(std::ostream& out, BaseAirplane* bs)
{
	bs->print();
	return out;
}