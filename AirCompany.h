#pragma once
#include"Header.h"
class AirCompany
{
public:
	AirCompany();
	~AirCompany();
	void print();
    void addPlanes(vector<BaseAirplane*>);
    void findAirplaneByFuel (double, double);
	void change(const string&, const string&);
private:
	vector<BaseAirplane*> airplanes;
};

AirCompany::AirCompany()
{
}

AirCompany::~AirCompany()
{
}
void AirCompany::addPlanes(vector<BaseAirplane*> w)
{
    std::for_each(w.begin(), w.end(), [this](BaseAirplane* sw)
        {
                this->airplanes.push_back(sw); 
        }
    );
}
void AirCompany::findAirplaneByFuel(double fuel1, double fuel2)
{
    std::copy_if(this->airplanes.begin(), this->airplanes.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"), [fuel1, fuel2] (BaseAirplane* w)
        {
            return w->getFuelConsumption() < fuel2 && w->getFuelConsumption() > fuel1;
        }
    );
}
void AirCompany::change(const string& str1, const string& str2)
{
    int cnt = 0;
    vector<BaseAirplane*> transformAirplane;
    std::transform(airplanes.begin(), airplanes.end(), std::back_inserter(transformAirplane),[str1, str2](BaseAirplane* r)
        {
            if (r->getName() == str1) r->setName(str2);
            return r;
        }
    );
    cout << "Transform airplanes\n";
    std::copy(transformAirplane.begin(), transformAirplane.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"));
}
void AirCompany::print()
{
	cout << "\n Airplanes \n";
	std::copy(airplanes.begin(), airplanes.end(), std::ostream_iterator<BaseAirplane*>(cout, "\n"));
}