#pragma once
#ifndef BPPTimePoint_hpp__
#define BPPTimePoint_hpp__

namespace bpp
{


	inline TimePointWin32::TimePointWin32() : 
		m_TimePoint()
	{
	}

	inline TimePointWin32::~TimePointWin32()
	{

	}

	inline bpp::TimePointWin32 TimePointWin32::Now()
	{
		TimePointWin32 point;
		QueryPerformanceCounter( &(point.m_TimePoint) );
		return point;
	}


	inline bpp::TimeSpan TimePointWin32::operator-( const TimePointWin32& rhs ) const
	{
		return TimeSpan( m_TimePoint.QuadPart - rhs.m_TimePoint.QuadPart );
	}


	inline bool TimePointWin32::operator==( const TimePointWin32& rhs ) const
	{
		return m_TimePoint.QuadPart == rhs.m_TimePoint.QuadPart;
	}

	inline bool TimePointWin32::operator!=( const TimePointWin32& rhs ) const
	{
		return m_TimePoint.QuadPart != rhs.m_TimePoint.QuadPart;

	}

	inline bool TimePointWin32::operator<( const TimePointWin32& rhs ) const
	{
		return m_TimePoint.QuadPart < rhs.m_TimePoint.QuadPart;

	}

	inline bool TimePointWin32::operator>( const TimePointWin32& rhs ) const
	{
		return m_TimePoint.QuadPart > rhs.m_TimePoint.QuadPart;

	}

	inline bool TimePointWin32::operator<=( const TimePointWin32& rhs ) const
	{
		return m_TimePoint.QuadPart <= rhs.m_TimePoint.QuadPart;

	}

	inline bool TimePointWin32::operator>=( const TimePointWin32& rhs ) const
	{
		return m_TimePoint.QuadPart >= rhs.m_TimePoint.QuadPart;

	}




}
#endif // BPPTimePoint_hpp__
