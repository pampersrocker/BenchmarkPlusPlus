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
			for( Result result : scope->Results() )
			{
				cout << "\t" << result.GetItem()->Name() << "\t" << result.Span().Seconds() << std::endl;
			}
		}
	}
}

#endif // BPPDefaultConsoleLogger_inl__
