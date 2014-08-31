#pragma once
#ifndef BPPMacros_h__
#define BPPMacros_h__

#define BPP_TO_STRING2( param ) #param
#define BPP_TO_STRING( param ) BPP_TO_STRING2( param )

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
	BPP_##scope##benchmarkName global##BPP_##scope##benchmarkName##__LINE__##(BPP_TO_STRING(BPP_CURRENT_BENCHMARK_NAME) );


#endif // BPPMacros_h__
