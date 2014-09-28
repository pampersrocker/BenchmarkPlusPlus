#pragma once
#ifndef BPPBenchmarker_inl__
#define BPPBenchmarker_inl__

namespace bpp
{
	inline Benchmarker::Benchmarker( void ) :
		m_CurrentScope( nullptr ),
		m_Logger(),
		m_Results(),
		m_Iterations( 1U )
	{
	}


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


	inline BenchmarkScope* Benchmarker::CurrentScope( void ) const
	{
		return m_CurrentScope;
	}

	inline void Benchmarker::CurrentScope( BenchmarkScope* scope )
	{
		m_CurrentScope = scope;
	}


	inline void Benchmarker::Iterations( unsigned int val )
	{
		if( val > 1U )
		{
			m_Iterations = val;
		}
		else
		{
			m_Iterations = 1U;
		}
	}

	inline unsigned int Benchmarker::Iterations( void ) const
	{
		return m_Iterations;
	}

	inline void Benchmarker::Run( void )
	{
		for( BenchmarkScope* scope : ScopeContainer::Instance().FactoryItems() )
		{
			ResultScope* resultScope = new ResultScope( scope->Name() );
			for( IFactoryItem* item : scope->Items() )
			{
				ResultContainer resultContainer( static_cast< BenchmarkarbleItem* >( item ), scope, m_Iterations );
				for( size_t i = 0; i < m_Iterations; i++ )
				{
					item->Initialize();
					TimePoint startPoint = TimePoint::Now();
					item->Run();
					TimePoint endPoint = TimePoint::Now();
					item->Release();
					Result result( ( endPoint - startPoint ), static_cast< BenchmarkarbleItem* >( item ), scope );
					resultContainer.AddResult( result );
				}
				resultScope->AddResult( resultContainer );
			}
			m_Results.push_back( resultScope );
		}
	}


	inline void Benchmarker::AddLogger( ILogger* logger )
	{
		m_Logger.push_back( logger );
	}

	inline void Benchmarker::Log( void )
	{
		for( ILogger* logger : m_Logger )
		{
			logger->Initialize();
			logger->Log( m_Results );
			logger->Release();
		}
	}


	inline void Benchmarker::Release( void )
	{
		Benchmarker::ScopeContainer::Release();

		
		Benchmarker*& instance = InternalInstance( false );
		if (instance != nullptr)
		{
			for( auto* it : instance->m_Results )
			{
				delete it;
			}
			instance->m_Results.clear();
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
