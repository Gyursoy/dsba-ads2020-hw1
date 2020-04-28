#include "testbed.h"

#include <fstream>



float TestBed::measuringTimeOfGs(int k, Multiplicator& a)
{
    clock_t t = clock();
    a.gradeSchoolAlg(k);
    t = clock() - t;
    return (((float)t * 1000)/ CLOCKS_PER_SEC);
}

float TestBed::measuringTimeOfDac(int k, Multiplicator& a)
{
    clock_t t = clock();
    a.divideAndConquerAlg(k);
    t = clock() - t;
    return (((float)t * 1000) / CLOCKS_PER_SEC);
}

float TestBed::measuringTimeOfKar(int k, Multiplicator& a)
{
    clock_t t = clock();
    Multiplicator::karatsubaAlg(k, a.getFirstOfTypeNumber(), a.getSecondOfTypeNumber());
    t = clock() - t;
    return (((float)t * 1000) / CLOCKS_PER_SEC);
}


void TestBed::testOfAlgorithms()
{
    std::ofstream outfile(R"(C:\Users\Windows\CLionProjects\workshop20ADS\data.csv)");
    outfile << "n-digits,Grade School,Divide and Conquer,Karatsuba" << "\n";
    int k = 0;
    int step = 1;
    int counter = 0;
    while (k <= 1000)
    {
        if (k >= 1000)
            step = 1000;k += step;
        int n = k;
        outfile << k << ",";
        Multiplicator a;
        a.fillNumbers(k);
        outfile << measuringTimeOfGs(n, a) << ",";
        n = k;
        a.fillNumbers(n);
        outfile << measuringTimeOfDac(n, a) << ",";
        n = k;
        a.fillNumbers(n);
        outfile << measuringTimeOfKar(n, a) << "\n";
        counter++;
    }
}
