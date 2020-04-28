
#ifndef WORKSHOP20ADS_NUMBER_H
#define WORKSHOP20ADS_NUMBER_H


#include <iostream>
#include <ctime>
#include <string>
#include <utility>
#include <vector>
#include <cstddef>


class Number
{
public:
    Number() : _number("") {}

    explicit Number(const std::string&  val) : _number(val) {}

public:

    Number operator+(const Number& rhv) const
    {
        Number res, temp;
        int lhvLen = _number.size();
        int rhvLen = rhv._number.size();
        int min, max;
        if (lhvLen > rhvLen)
        {
            res._number =  _number;
            temp._number = rhv._number;
            min = rhvLen;
            max = lhvLen;
        }
        else
        {
            res._number = rhv._number;
            temp._number = _number;
            min = lhvLen;
            max = rhvLen;
        }
        int j = max - 1;
        for (int i = min - 1; i >= 0; --i)
        {
            int currNum = (res[j] - 48) + (temp[i] - 48);
            res[j] = (currNum) + 48;
            if (currNum > 9)
            {
                int m = 0;
                while (res[j - m] >= 58)
                {
                    if (j - m <= 0)
                    {
                        res[0] -= 10;
                        res._number = "1" + res._number;
                    }
                    else
                    {
                        res[j - m] -= 10;
                        res[j - m - 1] += 1;
                    }
                    m++;
                }
            }
            --j;
        }
        res._number.erase(0,res._number.find_first_not_of('0'));
        if (res._number.empty())
            res.addZerosInFrontOfOneNum();
        return res;
    }

    Number operator+=(const Number& rhv)
    {
        *this = *this + rhv;
        return (*this);
    }


    Number operator-(const Number& rhv)
    {
        Number res;
        int len2 = rhv._number.size();
        int len1 = _number.size();
        int j = len1 - 1;
        for (int i = len2 - 1; i >= 0; --i)
        {
            int digit = (_number[j] - 48) - (rhv[i] - 48);
            if (digit >= 0)
                res._number.insert(0, std::to_string(digit));
            else
            {
                int n = j - 1;
                while (n >= 0)
                {
                    _number[n]--;
                    if (_number[n] >= 48)
                        break;
                    _number[n] += 10;
                    n--;
                }
                res._number.insert(0, std::to_string(digit + 10));
            }
            --j;
        }
        while (j >= 0)
        {
            res._number.insert(0, std::to_string(_number[j] - 48));
            j--;
        }
        while((res[0] - 48) == 0)
            res._number.erase(0, 1);
        if (res._number.empty())
            res.addZerosInFrontOfOneNum();
        return res;
    }

    Number operator*(const Number& rhv) // for base case
    {
        Number res;
        res.push((_number[0] - 48) * (rhv[0] - 48) + 48 );
        return res;
    }

    const char& operator[](int i) const { return _number[i]; }

    char& operator[](int i) { return _number[i]; }



public:

    Number subStr(int from, int to)
    {
        Number a(_number.substr(from, to));
        return a;
    }

    void insert(const std::string& a) { _number.insert(0, a); }

    void addZerosInFrontOfOneNum() { _number = "0" + _number;}

    int getSize() { return _number.size();}

    int getSize() const { return _number.size();}

    char& top() {return _number[0];}

    const std::string& getNumber() const { return _number; }

    std::string& getNumber() {return _number;}

    void push(char a) { _number.push_back(a); }

    std::pair<Number, Number> split(int n)
    {
        std::pair<Number, Number> res;
        if (_number.empty())
            return res;
        int k = n / 2;
        res.first._number = _number.substr(0, k);
        res.second._number = _number.substr(k, n);
        return res;
    }

protected:
    std::string _number;
};

#endif //WORKSHOP20ADS_NUMBER_H
