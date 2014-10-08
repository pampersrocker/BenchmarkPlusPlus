#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "bpp.hpp"
#include "Logging/BPPDefaultConsoleLogger.hpp"

using namespace bpp;

namespace BPPUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Benchmarker& instance = Benchmarker::Instance();

			DefaultConsoleLogger logger;

			instance.AddLogger( &logger );
			instance.Run();

			instance.Log();

			instance.Release();
		}

	};
}