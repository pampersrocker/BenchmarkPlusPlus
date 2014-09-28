#pragma once
#ifndef ResultContainer_inl__
#define ResultContainer_inl__

namespace bpp
{

	inline ResultContainer::ResultContainer(BenchmarkarbleItem* item, BenchmarkScope* scope,  int reserveSize ) :
		m_Results(),
		m_Item( item ),
		m_Scope( scope )
	{
		m_Results.reserve( reserveSize );
	}

	inline ResultContainer::~ResultContainer()
	{
		m_Results.clear();
	}

	inline int ResultContainer::Count( void ) const
	{
		return m_Results.size();
	}

	inline void ResultContainer::AddResult( const Result& result )
	{
		m_Results.push_back( result );
	}


	inline bpp::Result ResultContainer::AverageResult( void ) const
	{
		unsigned int count = 0;
		unsigned long long ticks = 0;

		for( auto& result : m_Results )
		{
			ticks += result.Span().Ticks();
			count++;
		}

		return Result( TimeSpan( ticks / count ), m_Item, m_Scope);
	}



	inline const std::vector<Result>& ResultContainer::Results( void ) const
	{
		return m_Results;
	}

	inline BenchmarkScope* ResultContainer::Scope() const
	{
		return m_Scope;
	}

	inline BenchmarkarbleItem* ResultContainer::Item() const
	{
		return m_Item;
	}
}

#endif // ResultContainer_inl__
