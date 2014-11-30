#pragma once
#ifndef ResultScenario_inl__
#define ResultScenario_inl__

namespace bpp
{

	inline
	ResultScenario::ResultScenario(const BenchmarkScenario* scenario ) :
		m_Scenario( scenario ),
		m_Scopes()
	{

	}

	inline
	ResultScenario::~ResultScenario()
	{
		for( auto it : m_Scopes )
		{
			delete it;
		}
		m_Scopes.clear();
	}

	inline
	const BenchmarkScenario* ResultScenario::Scenario( void ) const
	{
		return m_Scenario;
	}

	inline
	const std::vector< ResultScope* >& ResultScenario::ResultScopes( void ) const
	{
		return m_Scopes;
	}

	inline
	void ResultScenario::AddResult( ResultScope* resultScope )
	{
		m_Scopes.push_back( resultScope );
	}
}

#endif // ResultScenario_inl__
