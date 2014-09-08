#pragma once
#ifndef BPPScope_inl__
#define BPPScope_inl__

namespace bpp
{
	inline BenchmarkScope::BenchmarkScope( const std::string& name ) : 
		m_Name( name )
	{
		
	}

	inline void BenchmarkScope::AddItemToScope( IFactoryItem* item )
	{
		m_Items.push_back( item );
	}

	inline const std::vector< IFactoryItem* >& BenchmarkScope::Items( void ) const
	{
		return m_Items;
	}

	inline const std::string& BenchmarkScope::Name( void ) const
	{
		return m_Name;
	}
}

#endif // BPPScope_inl__
