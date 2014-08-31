#pragma once
#ifndef BPPFactoryContainer_inl__
#define BPPFactoryContainer_inl__

namespace bpp
{
	
	template < class T >
	inline FactoryContainer<T*>*& bpp::FactoryContainer<T>::InternalInstance()
	{
		static FactoryContainer<T*>* instance = nullptr;
		if (instance == nullptr)
		{
			instance = new FactoryContainer<T*>();
		}

		return instance;
	}

	template < class T >
	inline void bpp::FactoryContainer<T>::Release()
	{
		FactoryContainer<T*>*& instance = InternalInstance();
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	template < class T >
	inline FactoryContainer<T*>& bpp::FactoryContainer<T>::Instance()
	{
		return *InternalInstance();
	}

	template < class T >
	inline const std::vector< T* >& bpp::FactoryContainer<T>::FactoryItems( void ) const
	{
		return m_List;
	}

	template < class T >
	inline void bpp::FactoryContainer<T>::AddFactoryItem( T* item )
	{
		if( item != nullptr )
		{
			m_List.push_back( item );
		}
	}
}

#endif // BPPFactoryContainer_inl__
