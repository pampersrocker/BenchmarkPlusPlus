#pragma once
#ifndef ResultScenario_h__
#define ResultScenario_h__
#include <vector>

namespace bpp
{
	class ResultScope;

	/**
	\brief A ResultScenario is the top most Structure of the Result Hierarchy.
	A ResultScenario stores the benchmarked Scenario and its Scopes which were tested using this scenario.
	If no Scenarios were declared there will be only one ResultScenario with a nullptr as the "tested" Scenario.
	
	*/
	class ResultScenario
	{
	public:
		/**
		\brief Creates a new ResultScenario with the given BenchmarkScenario.
		The given BenchmarkScenario is immutable and cannot be changed later.
		
		\param scenario The scenario which was benchmarked in the ResultScopes, may be nullptr if now Scenario was used.
		*/
		ResultScenario( const BenchmarkScenario* scenario );
		~ResultScenario();

		/**
		\brief Gets the benchmarked scenario or nullptr if no scenario was used.
		
		*/
		const BenchmarkScenario* Scenario( void ) const;

		/**
		\brief All the Scopes which was benchmarked using the given Scenario.
		
		*/
		const std::vector< ResultScope* >& ResultScopes( void ) const;

	protected:
	private:

		friend class Benchmarker;

		/**
		\brief Adds a result to the ResultScenario, may only be called from the Benchmarker itself.
		
		*/
		void AddResult( ResultScope* resultScope );

		std::vector<ResultScope*> m_Scopes;

		const BenchmarkScenario* m_Scenario;


	};

}

#include "BPPResultScenario.inl"

#endif // ResultScenario_h__
