#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace az
{

	class Timer
	{
	public:

		using ns = std::chrono::nanoseconds;
		using mcs = std::chrono::microseconds;
		using ms = std::chrono::milliseconds;
		using s = std::chrono::seconds;

		Timer() = delete;
		Timer(Timer&) = delete;
		Timer(Timer&&) = delete;

		template <class _Scale, class _T, class... _Args>
		static long long timer(_T caller, _Args&&... args)
		{
			_TP _start = _HRC::now();

			caller(std::forward<_Args>(args)...);

			return std::chrono::duration_cast<_Scale>(_HRC::now() - _start).count();
		}
	protected:
		using _HRC = std::chrono::high_resolution_clock;
		using _TP  = std::chrono::high_resolution_clock::time_point;
	};
}

#endif//TIMER_H
