#pragma once
#ifndef ResultContainer_h__
#define ResultContainer_h__
#include <array>
namespace bpp
{
	class ResultContainer
	{
	public:
		ResultContainer(BenchmarkarbleItem* item, BenchmarkScope* scope, int reserveSize);
		~ResultContainer();

		int Count( void ) const;

		void AddResult( const Result& result );

		const std::vector<Result>& Results( void ) const;
		BenchmarkScope* Scope() const;
		BenchmarkarbleItem* Item() const;

		Result AverageResult( void ) const;

	private:

		BenchmarkarbleItem* m_Item;
		BenchmarkScope* m_Scope;
		std::vector<Result> m_Results;
	};
}

#include "ResultContainer.inl"
#endif // ResultContainer_h__
