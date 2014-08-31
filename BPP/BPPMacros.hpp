#pragma once
#ifndef BPPMacros_h__
#define BPPMacros_h__

#define BPP_TO_STRING2( param ) #param
#define BPP_TO_STRING( param ) BPP_TO_STRING2( param )

#define BPP_CONCAT2( x, y ) x ## y
#define BPP_CONCAT( x, y ) BPP_CONCAT2( x, y )

#define BPP_BEGIN_BENCHMARK( scope, benchmarkName )															\
	class BPP_##scope##benchmarkName : public ::bpp::BenchmarkarbleItem										\
	{																										\
		public:																								\
			inline BPP_##scope##benchmarkName( const std::string name) : ::bpp::BenchmarkarbleItem( name )	\
			{																								\
				::bpp::Benchmarker::Instance().Scope( BPP_TO_STRING(scope) )->AddItemToScope( this );						\
			}																								\

#define BPP_INITIALIZE_BENCHMARK	\
	inline virtual void Initialize() override

#define BPP_BENCHMARK				\
	inline virtual void Run() override

#define BPP_RELEASE_BENCHMARK		\
	inline virtual void Release() override

#define BPP_END_BENCHMARK(scope, benchmarkName )								\
	};																			\
	BPP_##scope##benchmarkName BPP_CONCAT(global_##BPP_##scope##_##benchmarkName##_, __LINE__)  ( BPP_TO_STRING(benchmarkName) );


#endif // BPPMacros_h__
