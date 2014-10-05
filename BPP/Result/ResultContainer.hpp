#pragma once
#ifndef ResultContainer_h__
#define ResultContainer_h__
namespace bpp
{
	class IResultFilter;

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

		Result ShortestResult( void ) const;

		Result LongestResult( void ) const;

		IResultFilter* Filter( void ) const;
		void Filter( IResultFilter* filter );

	private:

		IResultFilter* m_Filter;

		BenchmarkarbleItem* m_Item;
		BenchmarkScope* m_Scope;
		std::vector<Result> m_Results;

	};
}

#include "ResultContainer.inl"
#endif // ResultContainer_h__
