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

		if( count == 0 )
		{
			count = 1;
		}

		return Result( TimeSpan( ticks / count ), m_Item, m_Scope);
	}


	inline bpp::Result ResultContainer::ShortestResult( void ) const
	{
		if( m_Results.size() > 0 )
		{
			Result shortest = m_Results[ 0 ];
			for( auto& result : m_Results )
			{
				if( result.Span() < shortest.Span() )
				{
					shortest = result;
				}
			}

			return shortest;
		}
		else
		{
			return Result( TimeSpan(), m_Item, m_Scope );
		}
	}

	inline bpp::Result ResultContainer::LongestResult( void ) const
	{
		if( m_Results.size() > 0 )
		{
			Result longest = m_Results[ 0 ];
			for( auto& result : m_Results )
			{
				if( result.Span() > longest.Span() )
				{
					longest = result;
				}
			}

			return longest;
		}
		else
		{
			return Result( TimeSpan(), m_Item, m_Scope );
		}
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
