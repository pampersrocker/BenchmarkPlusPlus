#pragma once
#ifndef BPPBaseScenario_h__
#define BPPBaseScenario_h__
#include <string>

namespace bpp
{
	/**
	\brief The dummy class for any Scenario used on the benchmarking process.
	
	*/
	class BenchmarkDummyScenario
	{
	public:

		/**
		\brief Used for Identification of this Scenario
		
		*/
		inline std::string ToString() const
		{
			return std::string();
		}

	private:

	};
}

#endif // BPPBaseScenario_h__
