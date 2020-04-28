#ifndef WORKSHOP20ADS_MULTIPLICATOR_H
#define WORKSHOP20ADS_MULTIPLICATOR_H

#include "number.h"



class Multiplicator
{
public:

    Multiplicator() = default;

    Multiplicator(const std::string& str1, const std::string& str2) : _first(str1), _second(str2) {}

    Multiplicator(const Number& num1, const Number& num2) : _first(num1), _second(num2) {}

    Multiplicator(const std::pair<Number, Number>& number) : _first(number.first), _second(number.second) {}

    ~Multiplicator() = default;

public:

    Multiplicator operator+(const Multiplicator& rhv)
    {
        Multiplicator res;
        res._first = _first + rhv._first;
        res._second = _second + rhv._second;
        return res;
    }

    Multiplicator operator+=(const Multiplicator& rhv)
    {
        return (*this + rhv);
    }

public:

    void addZeroesInFront();

    std::string getFirstNumber() const { return _first.getNumber(); }

    std::string getSecondNumber() const { return _second.getNumber(); }

    Number getFirstOfTypeNumber() const { return _first; }

    Number getSecondOfTypeNumber() const { return _second; }

    static Number randomNumber(int k);

    void fillNumbers(int k);

    Number gradeSchoolAlg(int k);

    Number divideAndConquerAlg(int k);

    static Number karatsubaAlg(int k, Number one, Number two);


protected:
    Number _first;
    Number _second;
};

std::ostream& operator<< (std::ostream& out, const Multiplicator& numbers);


#endif //WORKSHOP20ADS_MULTIPLICATOR_H
