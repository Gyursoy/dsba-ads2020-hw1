#include "multiplicator.h"

std::ostream& operator<< (std::ostream& out, const Multiplicator& numbers)
{
out << "First number: " << numbers.getFirstNumber() << "\n";
out << "Second number: " << numbers.getSecondNumber() << "\n";
return out;
}

void Multiplicator::addZeroesInFront()
{
    _first.getNumber() = "0" + _first.getNumber();
    _second.getNumber() = "0" + _second.getNumber();
}

Number Multiplicator::randomNumber(int k)
{
    Number number;
    int a = rand() % 10;
    if (a < 9)
        a++;
    number.push(a + 48);
    for (int i = 1; i < k; ++i)
    {
        a = rand() % 10;
        number.push(a + 48);
    }
    return number;
}

void Multiplicator::fillNumbers(int k)
{
    _first = randomNumber(k);
    _second = randomNumber(k);
}

Number Multiplicator::gradeSchoolAlg(int k)
{
    std::vector<Number> multRes;
    Number finRes("0");
    for (int i = k - 1; i >= 0; --i)
    {
        int counter = 1;
        std::string oneRes;
        for (int j = k - 1; j >= 0; --j)
        {
            int a;
            a = (_first[i] - 48) * (_second[j] - 48);
            if (j == k - 1)
                oneRes = std::to_string(a);
            else
            {
                if (oneRes.size() == counter)
                {
                    oneRes[0] += (a % 10);
                }
                else
                {
                    oneRes = std::to_string(a % 10) + oneRes;
                }
                if (oneRes[0] > 57)
                {
                    oneRes[0] -= 10;
                    oneRes = "1" + oneRes;
                    oneRes[0] += (a / 10);
                }
                else if (a >= 10)
                {
                    oneRes = std::to_string(a / 10) + oneRes;
                }
            }
            counter++;
        }
        for (int n = k - 1; n > i; --n)
            oneRes += "0";
        Number a(oneRes);
        multRes.push_back(a);
    }
    for (int i = 0; i < multRes.size(); ++i)
        finRes += multRes[i];
    return finRes;
}


Number Multiplicator::divideAndConquerAlg(int k)
{
    if (k == 1)
    {
        Number base(std::to_string((_first[0] - 48) * (_second[0] - 48)));
        return base;
    }

    if (k % 2 != 0)
    {
        k++;
        this->addZeroesInFront();
    }

    std::pair<Number, Number> temp = _first.split(k);
    Number a = temp.first;
    Number b = temp.second;
    temp = _second.split(k);
    Number c = temp.first;
    Number d = temp.second;

    Multiplicator ac(a, c);
    Multiplicator ad(a, d);
    Multiplicator bc(b, c);
    Multiplicator bd(b, d);

    a = ac.divideAndConquerAlg(k / 2);
    b = ad.divideAndConquerAlg(k / 2);
    c = bc.divideAndConquerAlg(k / 2);
    d = bd.divideAndConquerAlg(k / 2);

    for (int i = 0; i < k; ++i)
        a.getNumber() += "0";
    for (int i = 0; i < (k / 2); ++i)
        b.getNumber() += "0";
    for (int i = 0; i < (k / 2); ++i)
        c.getNumber() += "0";

    return (a + b + c + d);
}


Number Multiplicator::karatsubaAlg(int k, Number one, Number two)
{
    int size1(one.getSize()), size2(two.getSize());
    while (size1 > size2)
    {
        two.addZerosInFrontOfOneNum();
        size2++;
    }
    while (size2 > size1)
    {
        one.addZerosInFrontOfOneNum();
        size1++;
    }
    while (size1 > k)
        k++;

    if (k == 1)
    {
        Number base(std::to_string((one[0] - 48) * (two[0] - 48)));
        return base;
    }

    std::pair<Number, Number> temp = one.split(k);
    Number a = temp.first;
    Number b = temp.second;
    temp = two.split(k);
    Number c = temp.first;
    Number d = temp.second;
    Number sum1 = a + b;
    Number sum2 = c + d;

    Number ac = karatsubaAlg(k / 2, a, c);
    Number bd = karatsubaAlg(k / 2, b, d);
    Number thirdVal = karatsubaAlg(k / 2, sum1, sum2) - ac - bd;

for (int i = 0; i < (k); ++i)
ac.getNumber() += "0";
for (int i = 0; i < (k / 2); ++i)
thirdVal.getNumber() += "0";

return (ac + bd + thirdVal);
}
