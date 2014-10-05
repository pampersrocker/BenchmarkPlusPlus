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

		/**
		\brief Returns the filtered Results of this container.
		The unfiltered results can be accessed using the UnfilteredResults Method.
		
		\return std::vector<Result> The list of filtered results.
		*/
		std::vector<Result> Results( void ) const;
		BenchmarkScope* Scope() const;
		BenchmarkarbleItem* Item() const;

		Result AverageResult( void ) const;

		Result ShortestResult( void ) const;

		Result LongestResult( void ) const;

		IResultFilter* Filter( void ) const;
		/**
		\brief Sets the filter for the container and prepares it.
		This method should be called, AFTER the actual benchmarking, when the results are present, since the preparing
		of the filter might depend on it.
		
		\param IResultFilter * filter The filter to set, or nullptr if no filter is wanted
		*/
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
