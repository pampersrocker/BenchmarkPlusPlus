#pragma once
#ifndef BPPTimeSpan_h__
#define BPPTimeSpan_h__

namespace bpp
{
	class TimeSpan
	{
	public:
		TimeSpan(const LONGLONG& span);
		TimeSpan( const TimeSpan& span );
		~TimeSpan();

		double Seconds( void ) const;
		LONGLONG Ticks( void ) const;
		double Microseconds( void ) const;
	private:
		LONGLONG m_Span;
	};
}

#include "BPPTimeSpan.inl"


#endif // BPPTimeSpan_h__
