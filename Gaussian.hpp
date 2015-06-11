#ifndef RANDPP_GAUSSIAN
#define RANDPP_GAUSSIAN

#define _USE_MATH_DEFINES

#include <cmath>
#include <Random_base.hpp>

namespace Random 
{

template <typename T>
class Gaussian : public Random<T>
{
public:
	Gaussian();
	Gaussian(const Gaussian<T>& obj);
	Gaussian(unsigned int seed);
	Gaussian(T mean, T stddev);
	~Gaussian();

	const T getMean() const {return mean;}
	const T getStddev() const {return stddev;}

	T random();
	T random(T mean, T stddev);

private:
	T mean;
	T stddev;
};

template <typename T>
Gaussian<T>::Gaussian()
: Random<T>()
{
	mean = (T)0;
	stddev = (T)1;
}

template <typename T>
Gaussian<T>::Gaussian(const Gaussian<T>& obj)
: Random<T>(obj)
{
	mean = obj.getMean();
	stddev = obj.getStddev();
}

template <typename T>
Gaussian<T>::Gaussian(unsigned int seed)
: Random<T>(seed)
{
	mean = (T)0;
	stddev = (T)1;
}

template <typename T>
Gaussian<T>::Gaussian(T mean, T stddev)
{
	this->mean = mean;
	this->stddev = stddev;
}

template <typename T>
Gaussian<T>::~Gaussian()
{
	/* nop */
}


template <typename T>
T Gaussian<T>::random()
{
	T alpha = Random<T>::random();
	T beta = Random<T>::random();
	return (T)sqrt(-2*log(alpha)) * sin(2*M_PI*beta) * stddev +mean;
}

template <typename T>
T Gaussian<T>::random(T mean, T stddev)
{
	T alpha = Random<T>::random();
	T beta = Random<T>::random();
	return (T)sqrt(-2*log(alpha)) * sin(2*M_PI*beta) * stddev +mean;
}

}
#endif
