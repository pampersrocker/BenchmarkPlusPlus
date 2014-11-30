#pragma once
#ifndef BPPBenchmarker_h__
#define BPPBenchmarker_h__
#include <string>
#include <map>
namespace bpp
{
	class BenchmarkScope;
	template < class T >
	class FactoryContainer;

	typedef BenchmarkBaseScenario BenchmarkScenario;


	/**
	\brief The main class for benchmarking. Contains all scopes used for benchmarking, runs the benchmarks itself
	and uses writers to print the output.

	Typical Usage:
	\code{.cpp}
	void main()
	{
		Benchmarker& instance = Benchmarker::Instance();

		MyLogger logger("SomeFile.log"); //Placeholder for your logger
		instance.AddLogger(&logger);
		instance.Run();
		instance.Log();

		instance.Release();
	}
	\endcode
	
	*/
	class Benchmarker
	{
	public:


		typedef FactoryContainer<BenchmarkScope*> ScopeContainer;

		/**
		\brief Gets the scope with the given name or a new Scope if none is existent with that name
		
		*/
		BenchmarkScope* Scope( const std::string& name ) const;

		/**
		\brief Cleans up all data used by the benchmarker, the added scopes and writers added to the benchmarker.
		
		*/
		static void Release( void );

		/**
		\brief Returns a valid instance of the benchmarker as long as there is enough memory available.
		
		Creates a new valid instance if none is yet created.
		
		*/
		static Benchmarker& Instance( void );

		/**
		\brief Runs the registered Tests in the scopes and saves the results for the logger.
		
		*/
		void Run( void );

		BenchmarkScope* CurrentScope( void ) const;
		void CurrentScope( BenchmarkScope* scope );

		/**
		\brief Adds a logger to the logging queue.

		The logger will be initialized, called and released in the Log() Method.
		The ownership of the logger is kept by the caller of this method.
		
		*/
		void AddLogger( ILogger* logger );

		/**
		\brief Logs the results using the logger which were added.
		Calling this method only makes sense after the Benchmarks has been performed using the Run() Method.

		Loggers are going to be initialized, called and released during this process.

		This is basically a NOP if no loggers were added to the Benchmarker.
		
		*/
		void Log( void );

		
		/**
		\brief Sets the iterations of the Benchmarker

		The iterations determines how often the benchmarks are repeated to reduce side effects of spontaneous spikes
		Keep in mind that if set to greater than 1 the tests need to be repeatable. If the tests are not repeatable, 
		set the iteration to 1
		
		\param val How often the tests will be repeated, value of 0 or 1 has the same effect
		*/
		void Iterations( unsigned int val );

		/**
		\brief Returns the current iteration of the Benchmarker, 
		this can be changed by using the Iterations( unsigned int ) Method
		
		*/
		unsigned int Iterations( void ) const;

		/**
		\brief Adds a new scenario, which will be benchmarked on all of the benchmarks and scopes.
		The ownership for the benchmark remains at the caller.
		
		*/
		void AddScenario( BenchmarkScenario* scenario );


	protected:
	private:

		std::vector< BenchmarkScenario* > m_Scenarios;

		unsigned int m_Iterations;
		Benchmarker( const Benchmarker& ) {};
		Benchmarker( void );

		std::vector< ILogger* > m_Logger;

		std::vector<ResultScenario*> m_Results;

		BenchmarkScope* m_CurrentScope;

		static Benchmarker*& InternalInstance( bool createIfNotInstanced = true );

	};

}

#include "BPPBenchmarker.inl"

#endif // BPPBenchmarker_h__
