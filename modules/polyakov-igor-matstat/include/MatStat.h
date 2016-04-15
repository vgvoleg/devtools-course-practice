// Copyright 2016 Polyakov Igor

class Sample
{

private:

    int sample_size; // Размер выборки
    double* sample; // Значения выборки, которые может принимать случ.величина
    double* probabilities; // Вероятности

    bool AreProbabilitiesCorrect(double* _probabilities);
    bool IsSampleCorrect(double* _sample);
    bool IsSampleSizeCorrect(int _sample_size);

public:

    Sample();
    Sample(int _sample_size, double* _sample, double* _probabilities);

    ~Sample();

    Sample(const Sample& S);

    Sample& operator=(const Sample& S);

    int GetSampleSize();
    double* GetSample();
    double* GetProbabilities();

    double CalcMathematicalExpectation();
    double CalcDispersion();
    double CalcAverageQuadraticDeviation();
    double CalcMoment(double relative_point, int exponent);
    double CalcElementaryMoment(int exponent);
    double CalcCentralMoment(int exponent);
};