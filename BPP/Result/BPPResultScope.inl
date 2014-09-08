#pragma once
#ifndef ResultScope_inl__
#define ResultScope_inl__

namespace bpp
{

	inline ResultScope::ResultScope( const std::string& scopeName ) :
		m_ScopeName(scopeName)
	{

	}

	inline ResultScope::~ResultScope()
	{

	}

	inline void ResultScope::AddResult( const Result& result )
	{
		m_Results.push_back( result );
	}

	inline const std::vector<Result>& ResultScope::Results( void ) const
	{
		return m_Results;
	}
}

#endif // ResultScope_inl__
