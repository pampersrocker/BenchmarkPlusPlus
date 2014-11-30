#pragma once
#ifndef BPPDefaultConsoleLogger_inl__
#define BPPDefaultConsoleLogger_inl__
#include <vector>
#include <iostream>

using namespace std;

namespace bpp
{

	inline DefaultConsoleLogger::DefaultConsoleLogger() : 
		m_UseColor(true)
	{

		hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

		m_Colors.resize(NUM);
		m_Colors[Normal] = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		m_Colors[Fastest] = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		m_Colors[Slowest] = FOREGROUND_RED | FOREGROUND_INTENSITY;
	}



	inline void DefaultConsoleLogger::Log( const std::vector< ResultScenario* >& scenarios )
	{
		for( auto scenario : scenarios )
		{
			if( scenario->Scenario() != nullptr )
			{
				cout << "Scenario: " << scenario->Scenario()->ToString() << std::endl;
			}
			
			for( ResultScope* scope : scenario->ResultScopes() )
			{
				cout << scope->ScopeName() << ":" << std::endl;

				Result shortest = scope->Results()[ 0 ].AverageResult();
				Result longest = scope->Results()[ 0 ].AverageResult();

				if( m_UseColor )
				{


					for( auto& result : scope->Results() )
					{
						if( result.AverageResult().Span() < shortest.Span() )
						{
							shortest = result.AverageResult();
						}
						if( result.AverageResult().Span() > longest.Span() )
						{
							longest = result.AverageResult();
						}
					}
				}

				for( auto& result : scope->Results() )
				{
					if( m_UseColor )
					{

						if( result.Item() == longest.GetItem() )
						{
							SetConsoleTextAttribute( hstdout, m_Colors[ Slowest ] );
						}
						else if( result.Item() == shortest.GetItem() )
						{
							SetConsoleTextAttribute( hstdout, m_Colors[ Fastest ] );

						}
						else
						{
							SetConsoleTextAttribute( hstdout, m_Colors[ Normal ] );
						}
					}
					cout << "\t" << result.Item()->Name() << "\t" << result.AverageResult().Span().Seconds() << std::endl;
					if( m_UseColor )
					{

						SetConsoleTextAttribute( hstdout, m_Colors[ Normal ] );
					}
				}
			}
		}
	}
}

#endif // BPPDefaultConsoleLogger_inl__
