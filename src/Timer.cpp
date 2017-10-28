#include "Timer.h"

using namespace std::chrono;

void Timer::Start()
{
	_clock = high_resolution_clock::now();
}

__int64 Timer::Elapsed() const
{
	return duration_cast<milliseconds> (high_resolution_clock::now() - _clock).count();
}
