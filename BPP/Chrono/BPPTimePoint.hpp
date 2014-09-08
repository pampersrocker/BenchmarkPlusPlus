#pragma once
#ifndef BPPTimePoint_h__
#define BPPTimePoint_h__

namespace bpp
{
	class TimePointWin32
	{
	public:
		TimePointWin32();
		~TimePointWin32();

		static TimePointWin32 Now();

		TimeSpan operator -( const TimePointWin32& rhs ) const;
		bool operator ==( const TimePointWin32& rhs ) const;
		bool operator !=( const TimePointWin32& rhs ) const;
		bool operator <( const TimePointWin32& rhs ) const;
		bool operator >( const TimePointWin32& rhs ) const;
		bool operator <=( const TimePointWin32& rhs ) const;
		bool operator >=( const TimePointWin32& rhs ) const;

	private:
		LARGE_INTEGER m_TimePoint;
	};

	typedef TimePointWin32 TimePoint;

}

#include "BPPTimePoint.inl"
#endif // BPPTimePoint_h__
