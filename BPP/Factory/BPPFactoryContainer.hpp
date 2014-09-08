#pragma once
#ifndef BPPFactoryContainer_h__
#define BPPFactoryContainer_h__
#include <vector>
namespace bpp
{
	class IFactoryItem;

	/**
	\brief Container class storing Factory items at startup for later use.
	
	This class gets instanced on the Instance() call. 
	Subsequent calls will return the same instance, 
	unless Release() is being called in which the instance is being destroyed
	and another call is going to create another instance. 
	
	*/
	template < class T >
	class FactoryContainer
	{
	public:

		void AddItem( const T& item );

		const std::vector< T >& FactoryItems( void ) const;

		/**
		\brief Returns a new instance of the FactoryContainer if no instance was yet created 
		or the previously created instance.
		
		Will generated a new instance if the old one was deleted using the Release() method.
		
		*/
		static FactoryContainer<T>& Instance();

		/**
		\brief Destroys the current instance, if any.
		
		*/
		static void Release();

	protected:
	private:

		static FactoryContainer<T>*& InternalInstance( bool createIfNotInstanced = true );

		std::vector< T > m_Items;
	};
}

#include "BPPFactoryContainer.inl"

#endif // BPPFactoryContainer_h__
