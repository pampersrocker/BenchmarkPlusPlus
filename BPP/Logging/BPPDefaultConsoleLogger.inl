#pragma once
#ifndef BPPDefaultConsoleLogger_inl__
#define BPPDefaultConsoleLogger_inl__
#include <vector>
#include <iostream>

using namespace std;

namespace bpp
{
	inline void DefaultConsoleLogger::Log( const std::vector< ResultScope* >& scopes )
	{
		for( ResultScope* scope : scopes )
		{
			cout << scope->ScopeName() << ":" << std::endl;
			for( ResultContainer result : scope->Results() )
			{
				cout << "\t" << result.Item()->Name() << "\t" << result.AverageResult().Span().Seconds() << std::endl;
			}
		}
	}
}

#endif // BPPDefaultConsoleLogger_inl__
