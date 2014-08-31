#pragma once
#ifndef BPPBenchmarker_inl__
#define BPPBenchmarker_inl__

namespace bpp
{
	inline BenchmarkScope* Benchmarker::Scope( const std::string& name ) const
	{
		const std::vector<BenchmarkScope*>& items = Benchmarker::ScopeContainer::Instance().FactoryItems();
		for (BenchmarkScope* item : items)
		{
			if (item->Name() == name)
			{
				return item;
			}
		}

		BenchmarkScope* newScope = new BenchmarkScope( name );
		Benchmarker::ScopeContainer::Instance().AddItem( newScope );

		return newScope;
	}

	inline void Benchmarker::Release( void )
	{
		Benchmarker::ScopeContainer::Release();
		Benchmarker*& instance = InternalInstance( false );
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}

	inline Benchmarker& Benchmarker::Instance( void )
	{
		return *InternalInstance();
	}

	inline Benchmarker*& Benchmarker::InternalInstance( bool createIfNotInstanced /*= true */ )
	{
		static Benchmarker* instance = nullptr;
		if (instance == nullptr && createIfNotInstanced)
		{
			instance = new Benchmarker();
		}
		return instance;
	}
}

#endif // BPPBenchmarker_inl__
