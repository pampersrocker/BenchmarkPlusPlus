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

	/**
	\brief The main class for benchmarking. Contains all scopes used for benchmarking, runs the benchmarks itself
	and uses writers to print the output.
	
	*/
	class Benchmarker
	{
	public:

		Benchmarker( void );

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



	protected:
	private:

		std::map<std::string, ResultScope*> m_Results;

		BenchmarkScope* m_CurrentScope;

		static Benchmarker*& InternalInstance( bool createIfNotInstanced = true );

	};

}

#include "BPPBenchmarker.inl"

#endif // BPPBenchmarker_h__
