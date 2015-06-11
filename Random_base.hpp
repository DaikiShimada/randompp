#ifndef RANDPP_BASE
#define RANDPP_BASE

#include <limits>
#include <ctime>


namespace rpp
{

template <typename T>
class Random
{
public:
	Random();
	Random(const Random& obj);
	Random(unsigned int seed);
	virtual ~Random();

	virtual T random();	

	const unsigned int getSeed() const {return seed;}
	const void getXorSeeds(unsigned int xorSeeds[]) const {for(int i=0; i<4; ++i)xorSeeds[i]=this->xorSeeds[i];}

private:
	unsigned int seed;
	unsigned int* xorSeeds;

	unsigned int xorShift();
};


template <typename T>
Random<T>::Random()
{
	seed = (unsigned int)time(0);
	xorSeeds = new unsigned int[4];

	// init XorShift
	xorSeeds[0] = 123456789U;
	xorSeeds[1] = 362436069U;
	xorSeeds[2] = 521288629U;
	xorSeeds[3] = 88675123U;
	for (int i=0; i<4; i++)
	{
		xorSeeds[i] = seed = 1812433253U * (seed ^ (seed >> 30)) + i;
	}
}

template <typename T>
Random<T>::Random(const Random& obj)
{
	seed = obj.getSeed();
	xorSeeds = new unsigned int[4];
	obj.getXorSeeds(xorSeeds);

}

template <typename T>
Random<T>::Random(unsigned int seed)
{
	this->seed = seed;
	xorSeeds = new unsigned int[4];

	// init XorShift
	xorSeeds[0] = 123456789U;
	xorSeeds[1] = 362436069U;
	xorSeeds[2] = 521288629U;
	xorSeeds[3] = 88675123U;
	for (int i=0; i<4; i++)
	{
		xorSeeds[i] = seed = 1812433253U * (seed ^ (seed >> 30)) + i;
	}
}

template <typename T>
Random<T>::~Random()
{
	delete[] xorSeeds;
}

template <typename T>
T Random<T>::random()
{
	unsigned int v = xorShift();
	return (T)v / (1.0 + std::numeric_limits<unsigned int>::max());
}

template <typename T>
unsigned int Random<T>::xorShift()
{
	unsigned int t = xorSeeds[0]^(xorSeeds[0]<<11);
	xorSeeds[0] = xorSeeds[1];
	xorSeeds[1] = xorSeeds[2];
	xorSeeds[2] = xorSeeds[3];
	return xorSeeds[3] ^= (xorSeeds[3]>>19)^t^(t>>8);
}

}
#endif
