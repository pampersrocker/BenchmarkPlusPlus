// BPPExamples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "bpp.hpp"
#include "Logging/BPPDefaultConsoleLogger.hpp"

using namespace bpp;

class DummyScenario : public BenchmarkBaseScenario
{
public:
	DummyScenario(const std::string& name) : m_Name(name) { }

	virtual std::string ToString() const override
	{
		return m_Name;
	}


private:

	std::string m_Name;

};

int _tmain(int argc, _TCHAR* argv[])
{

	Benchmarker& instance = Benchmarker::Instance();

	DefaultConsoleLogger logger;

	DummyScenario scenario1( "Scenario1" );
	DummyScenario scenario2( "Scenario2" );

	instance.AddScenario( &scenario1 );
	instance.AddScenario( &scenario2 );

	instance.AddLogger( &logger );

	instance.Run();

	logger.UseColor(true);

	instance.Log();

	logger.UseColor(false);

	instance.Log();

	instance.Release();


	return 0;
}

