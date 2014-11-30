#pragma once
#ifndef BPPILogger_h__
#define BPPILogger_h__
#include <vector>
namespace bpp
{
	class ResultScenario;

	class ILogger
	{
	public:
		
		/**
		\brief Gets called before the logging is invoked.
		
		Can be used to setup stuff for the actual logging
		
		*/
		inline virtual void Initialize( void ) {};

		/**
		\brief Gets called when all Benchmarks has been performed.

		All information that is available can be found in the scopes list
		
		*/
		virtual void Log( const std::vector< ResultScenario* >& scopes ) = 0;

		/**
		\brief Gets called after the logging process. 

		Can be used to clean up handles or whatever else was acquired for the logging process.
		
		*/
		inline virtual void Release( void ) {};

	private:

	};
}

#endif // BPPILogger_h__
