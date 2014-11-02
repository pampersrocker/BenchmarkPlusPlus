#include "stdafx.h"
#include "bpp.hpp"
#include <vector>
#include <random>
#include <functional>
#include <algorithm>


static std::vector<int> g_Numbers;
static bool initialized = false;

void Initialize()
{
	if( !initialized )
	{
		initialized = true;
		g_Numbers = std::vector<int>();
		std::default_random_engine generator;
		std::uniform_int_distribution<int> range( 1, 1000 );
		auto rand = std::bind( range, generator );
		for( size_t i = 0; i < 1000; i++ )
		{
			g_Numbers.push_back( rand() );
		}
	}
}



BPP_BEGIN_BENCHMARK( TestScope1, Sort )

std::vector<int> sorted;

BPP_INITIALIZE_BENCHMARK
{
	::Initialize();

	sorted = g_Numbers;
}

BPP_BENCHMARK
{
		
	std::sort( sorted.begin(), sorted.end() );
}


BPP_END_BENCHMARK

BPP_BEGIN_BENCHMARK( TestScope1, StableSort )


std::vector<int> sorted;

BPP_INITIALIZE_BENCHMARK
{
	::Initialize();
	sorted = g_Numbers;

}

BPP_BENCHMARK
{
	std::stable_sort( sorted.begin(), sorted.end() );
}


BPP_END_BENCHMARK