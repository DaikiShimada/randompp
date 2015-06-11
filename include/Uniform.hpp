#ifndef RANDPP_UNIFORM
#define RANDPP_UNIFORM

#include "Random_base.hpp"

namespace Random
{

template <typename T>
class Uniform : public Random<T>
{
public:
	Uniform();
	Uniform(const Uniform& obj);
	Uniform(unsigned int seed);
	Uniform(T min, T max);
	~Uniform();

	const T getMin() const {return min;}
	const T getMax() const {return max;}

	T random();
	T random(T min, T max);

private:
	T min;
	T max;
};

template <typename T>
Uniform<T>::Uniform()
: Random<T>()
{
	min = (T)0;
	max = (T)1;
}

template <typename T>
Uniform<T>::Uniform(const Uniform& obj)
: Random<T>(obj)
{
	min = obj.getMin();
	max = obj.getMax();
}

template <typename T>
Uniform<T>::Uniform(unsigned int seed)
: Random<T>(seed)
{
	min = (T)0;
	max = (T)1;
}

template <typename T>
Uniform<T>::Uniform(T min, T max)
: Random<T>()
{
	this->min = min;
	this->max = max;
}

template <typename T>
Uniform<T>::~Uniform()
{
	/* nop */
}

template <typename T>
T Uniform<T>::random()
{
	return (T)Random<T>::random() * (max - min) + min;
}

template <typename T>
T Uniform<T>::random(T min, T max)
{
	return (T)Random<T>::random() * (max - min) + min;
}

}
#endif
