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
		
		/**
		\brief Returns the unfiltered results of the container. 
		
		Is going to be the same as the Results Method if no filter is set or no Elements are filtered, 
		but will be faster in those cases, since no vector is being copied.
		
		\return const std::vector<Result>& All results in this container.
		*/
		const std::vector<Result>& UnfilteredResults( void ) const;
		
		BenchmarkScope* Scope() const;
		BenchmarkarbleItem* Item() const;

		/**
		\brief Returns the filtered average result of the container.
		
		If there are no results, or all results are filtered, a Result with a TimeSpan of 0 Ticks will be returned
		\return bpp::Result The average result, or a Result with 0 Ticks TimeSpan, if no results are available.
		*/
		Result AverageResult( void ) const;

		/**
		\brief Returns the shortest result, of all filtered results, or a Result with 0 Ticks if no Result applies.
		
		\return bpp::Result The shortest result, or a Result with 0 Ticks TimeSpan, if no results are available.
		*/
		Result ShortestResult( void ) const;

		/**
		\brief Returns the longest result, of all filtered results, or a Result with 0 Ticks if no Result applies.

		\return bpp::Result The longest result, or a Result with 0 Ticks TimeSpan, if no results are available.
		*/
		Result LongestResult( void ) const;

		/**
		\brief Gets the current filter.
		If no filter is set, nullptr will be returned.
		
		\return IResultFilter*
		*/
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
