

#ifndef WORKSHOP20ADS_TESTBED_H
#define WORKSHOP20ADS_TESTBED_H

#include "multiplicator.h"


class TestBed
{
public:
    typedef std::vector<float> GsRes;
    typedef std::vector<float> DacRes;
    typedef std::vector<float> KarRes;

public:

    static void testOfAlgorithms();
    static void fillDataInFile(const GsRes& a, const DacRes& b, const KarRes& c);
    static float measuringTimeOfGs(int k, Multiplicator& a);
    static float measuringTimeOfDac(int k, Multiplicator& a);
    static float measuringTimeOfKar(int k, Multiplicator& a);
};

#endif //WORKSHOP20ADS_TESTBED_H
