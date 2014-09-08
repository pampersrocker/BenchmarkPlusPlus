#pragma once
#ifndef BPPBenchmarkableItem_h__
#define BPPBenchmarkableItem_h__
#include "BPPFactoryItem.hpp"
#include <string>
namespace bpp
{
	/**
	\brief Default implements thee Initialize and Release Methods of the IFactoryItems so they are optional
	
	*/
	class BenchmarkarbleItem : public IFactoryItem
	{
	public:

		BenchmarkarbleItem( const std::string& name );

		inline virtual void Initialize( void ) override { }

		inline virtual void Release( void ) override { }

		const std::string Name( void ) const;

	protected:
	private:

		std::string m_Name;

	};

	inline BenchmarkarbleItem::BenchmarkarbleItem( const std::string& name ) :
		m_Name( name )
	{

	}

}

#endif // BPPBenchmarkableItem_h__
