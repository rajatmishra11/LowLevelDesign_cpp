#include <bits/stdc++.h>
using namespace std;

class Inverter
{
protected:
    int rating;
    int operatingVoltage;
    Inverter(int rating, int operatingVoltage)
    {
        this->operatingVoltage = operatingVoltage;
        this->rating = rating;
    }

public:
    int getRating()
    {
        return rating * operatingVoltage;
    }
};

class SolarInverter : public Inverter
{
protected:
    int panel_numbers;
    SolarInverter(int rating, int operatingVoltage, int panel_number)
    {
        this->rating = rating;
        this->operatingVoltage = operatingVoltage;
        this->panel_numbers = panel_number;
    }
};

class PCU : public SolarInverter
{
protected:
    bool Battery = 1;
    PCU(int rating, int operatingVoltage, int panel_number)
    {
        this->rating = rating;
        this->operatingVoltage = operatingVoltage;
        this->panel_numbers = panel_number;
    }

public:
    bool hasBattery()
    {
        if (this->Battery == 1)
        {
            return 1;
        }
        else
            return 0;
    }

}

class GTI : public SolarInverter
{
private:
    bool GridOn = 1;

public:
    GTI(int rating, int operatingVoltage, int panel_number)
    {
        this->rating = rating;
        this->operatingVoltage = operatingVoltage;
        this->panel_numbers = panel_number;
    }
};

int main()
{

    return 0;
}