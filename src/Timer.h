#ifndef __TIMER__
#define __TIMER__

#include <chrono>

class Timer
{
public:
	void Start();
	__int64 Elapsed() const;
private:
	std::chrono::high_resolution_clock::time_point _clock;
};

#endif // __TIMER__