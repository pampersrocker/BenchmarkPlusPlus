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
		TimeSpan( void );
		~TimeSpan();

		double Seconds( void ) const;
		LONGLONG Ticks( void ) const;
		double Microseconds( void ) const;

		TimeSpan operator +( const TimeSpan& rhs ) const;
		TimeSpan& operator +=( const TimeSpan& rhs );

		bool operator <( const TimeSpan& rhs ) const;
		bool operator >( const TimeSpan& rhs ) const;
		bool operator <=( const TimeSpan& rhs ) const;
		bool operator >=( const TimeSpan& rhs ) const;
		bool operator ==( const TimeSpan& rhs ) const;
		bool operator !=( const TimeSpan& rhs ) const;

		TimeSpan operator -( const TimeSpan& rhs ) const;
		TimeSpan& operator -=( const TimeSpan& rhs );

	private:
		LONGLONG m_Span;
	};

}

#include "BPPTimeSpan.inl"


#endif // BPPTimeSpan_h__
