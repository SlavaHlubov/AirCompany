#pragma once
#include"Header.h"

class TransportPlane: public BaseAirplane
{
public:
	TransportPlane();
	~TransportPlane();
	void read(std::istream&) override;
	std::ostream& print()override;
private:
	double carryingCapacity;
};

TransportPlane::TransportPlane()
{
}

TransportPlane::~TransportPlane()
{
}
void TransportPlane::read(std::istream& in)
{
	BaseAirplane::read(in);
	in >> carryingCapacity;

}
std::ostream& TransportPlane::print()
{
	BaseAirplane::print();
	std::cout << " capacity(kg): " << carryingCapacity;
	return std::cout;
}