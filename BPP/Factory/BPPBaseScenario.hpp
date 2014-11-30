#pragma once
#ifndef BPPBaseScenario_h__
#define BPPBaseScenario_h__
#include <string>

namespace bpp
{
	/**
	\brief The base class for any Scenario used on the benchmarking process.
	Features a ToString method for identification, which has to be overridden.
	
	*/
	class BenchmarkBaseScenario
	{
	public:

		/**
		\brief Used for Identification of this Scenario
		
		*/
		virtual std::string ToString() const = 0;

	private:

	};
}

#endif // BPPBaseScenario_h__
