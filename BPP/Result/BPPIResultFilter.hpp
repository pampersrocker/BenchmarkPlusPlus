#pragma once
#ifndef BPPIResultFilter_h__
#define BPPIResultFilter_h__

namespace bpp
{
	/**
	\brief Base Interface for Filtering Results from a Container.
	This can be useful to filter out spikes in the benchmarking.

	The filter is asked for every result whether this result should be filtered out or not.
	To make relative decisions based on the Result collection, 
	the PrepareFilter Method will be called before any actual filtering, passing the (yet) unfiltered container.
	
	*/
	class IResultFilter
	{
	public:

		/**
		\brief Prepares the filter for actual filtering.
		This method can be implemented if relative filtering based on the results is needed.
		
		\param const std::vector< Result >& the unsorted list of Results.
		*/
		inline virtual void PrepareFilter( const std::vector<Result>& /* container */ ) {};

		/**
		\brief Check if a Result needs to be filtered or not
		
		\param const Result & result The result to be checked
		\return bool \c True, if the result should be filtered out, \c false if the result should be kept.
		*/
		virtual bool FilterResult( const Result& result ) = 0;

	private:

	};

}
#endif // BPPIResultFilter_h__
