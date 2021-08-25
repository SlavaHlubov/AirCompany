#pragma once
#include"Header.h"
class PassengerPlane: public BaseAirplane
{
public:
	 PassengerPlane();
	~ PassengerPlane();
	void read(std::istream&) override;
	std::ostream& print()override;
private:
	double passCapacity;
};

 PassengerPlane:: PassengerPlane()
{
}

 PassengerPlane::~ PassengerPlane()
{
}

 void PassengerPlane::read(std::istream& in)
 {
	 BaseAirplane::read(in);
	 in >> passCapacity;
 }
 std::ostream& PassengerPlane::print()
 {
	 BaseAirplane::print();
	 std::cout << " Passenger capacity: " << passCapacity;
	 
	 return std::cout;
 }
