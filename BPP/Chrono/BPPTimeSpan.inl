#pragma once
#ifndef BPPTimeSpan_inl__
#define BPPTimeSpan_inl__

namespace bpp
{

	inline TimeSpan::TimeSpan( const LONGLONG& span ) : 
		m_Span( span )
	{

	}

	inline TimeSpan::TimeSpan( const TimeSpan& span ) :
		m_Span( span.m_Span )
	{

	}


	inline TimeSpan::TimeSpan( void ) :
		m_Span( 0 )
	{

	}

	inline bpp::TimeSpan TimeSpan::operator+( const TimeSpan& rhs ) const
	{
		return TimeSpan( m_Span + rhs.m_Span );
	}

	inline TimeSpan& TimeSpan::operator+=( const TimeSpan& rhs )
	{
		m_Span += rhs.m_Span;
		return *this;

	}

	inline bpp::TimeSpan TimeSpan::operator-( const TimeSpan& rhs ) const
	{
		return TimeSpan( m_Span - rhs.m_Span );
	}

	inline TimeSpan& TimeSpan::operator-=( const TimeSpan& rhs )
	{
		m_Span -= rhs.m_Span;
		return *this;
	}


	inline TimeSpan::~TimeSpan()
	{

	}

	inline double TimeSpan::Seconds( void ) const
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency( &freq );
		return ( double ) m_Span / ( double ) freq.QuadPart;
	}

	inline LONGLONG TimeSpan::Ticks( void ) const
	{
		return m_Span;
	}

	inline double TimeSpan::Microseconds( void ) const
	{
		LARGE_INTEGER freq;
		QueryPerformanceFrequency( &freq );

		LONGLONG tmp = m_Span * 1000000;
		return ( double ) tmp / ( double ) freq.QuadPart;
	}
}

#endif // BPPTimeSpan_inl__
