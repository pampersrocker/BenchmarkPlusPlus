#pragma once
#ifndef BPPScope_hpp__
#define BPPScope_hpp__
#include <vector>
#include <string>
namespace bpp
{
	class IFactoryItem;

	class BenchmarkScope
	{
	public:

		BenchmarkScope( const std::string& name );

		void AddItemToScope( IFactoryItem* item );

		std::vector< IFactoryItem* >& Items( void ) const;

		const std::string& ScopeName( void ) const;

	protected:
	private:

		std::vector < IFactoryItem* > m_Items;
		std::string m_Name;
	};
}

#endif // BPPScope_hpp__
