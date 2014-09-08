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

		const std::vector< IFactoryItem* >& Items( void ) const;

		const std::string& Name( void ) const;

	protected:
	private:

		std::vector < IFactoryItem* > m_Items;
		std::string m_Name;
	};
}

#include "BPPScope.inl"

#endif // BPPScope_hpp__
