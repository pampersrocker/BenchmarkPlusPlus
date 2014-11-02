BenchmarkPlusPlus
=================

BenchmarkPlusPlus is a simple but powerful Benchmarking and comparison Framework for C++ Code.

Setup
=================

To get up and running all you need to do is to download the contents of the bpp directory
and add it to your additional include directories, then you are ready to go.

Writing Benchmarks
=================

A typical Benchmark would look like this:

```cpp
// My_benchmark.cpp
#include <bpp.hpp>

BPP_BEGIN_BENCHMARK( MyScope, MyBenchmark )

	BPP_BENCHMARK
	{
		// Your benchmarked code here
	}

BPP_END_BENCHMARK
```

All benchmarks in one scope are grouped together, which enables comparison between different
benchmarks:

```cpp
// My_benchmark.cpp
#include <bpp.hpp>

BPP_BEGIN_BENCHMARK( MyScope, MyOldCode )

	BPP_BENCHMARK
	{
		// Your old code
	}

BPP_END_BENCHMARK

BPP_BEGIN_BENCHMARK( MyScope, MyNewCode )

	BPP_BENCHMARK
	{
		// Your new code
	}

BPP_END_BENCHMARK
```

Here the old code gets compared to the new code. The Scope and Name declaration together
must be unique over the whole project it is running in.

Initialization, Variables & Release
====================

You usually want to test your code on some data which should be already initialized before the actual benchmarking.
To achieve this you can define variables inside the ```BPP_BEGIN_BENCHMARK(...)``` and ```BPP_END_BENCHMARK```
and declare a Initialize and Release Method:

```cpp
// My_benchmark.cpp
#include <bpp.hpp>

BPP_BEGIN_BENCHMARK( MyScope, MyBenchmark )

	int myImportantBenchmarkValue;

	BPP_INITIALIZE_BENCHMARK
	{
		// do your initialization
		myImportantBenchmarkValue = 42;
	}

	BPP_BENCHMARK
	{
		// Your code
	}

	BPP_RELEASE_BENCHMARK
	{
		// release variables, maybe cleanup for upcoming iterations
		myImportantBenchmarkValue = 0;
	}

BPP_END_BENCHMARK
```

These variables are defined in a class scope and are only available in those three methods.


Benchmarking
==================

The actual Benchmarker needs to be called in some sort of main function:

```cpp
#include "bpp.hpp"
#include "Logging/BPPDefaultConsoleLogger.hpp" //Include the default logger

using namespace bpp;

int _tmain(int argc, _TCHAR* argv[])
{

	Benchmarker& instance = Benchmarker::Instance(); // Get the global Benchmarker

	DefaultConsoleLogger logger; // Create some logger for the Benchmarker, to actually get some output

	instance.AddLogger( &logger ); // Add the logger to the benchmarker

	instance.Run(); // Run the tests

	instance.Log(); // Log the results

	instance.Release(); // Release any heap data allocated by the benchmarker

	return 0;
}
```

Implementing a custom Logger
===========================

If the default loggers are not up to the task as you desire them, you can easily create a custom Logger if you want to:

```cpp
#include "bpp.hpp"

class MyLogger : public bpp::ILogger
{
public:

	virtual void Initialize(void) override; //Optional, if initialization is needed

	virtual void Log( const std::vector< bpp::ResultScope* >& scopes ) override;

	virtual void Release(void) override; //Optional, if release is needed

private:

};
```

The argument on the Log call contains all results of all Scopes.
You usually want to iterate over all Scopes and iterate over all different ResultContainer in the scopes, which contain
all iteration of a benchmark.
So to log every benchmark that has been done, you would create a loop like the following:
```cpp
void MyLogger::Log( const std::vector< ResultScope* >& scopes )
{
	for( ResultScope* scope : scopes )
	{
		// TODO: Output the scope here
		for( const ResultContainer& resultContainer : scope->Results() )
		{
			// TODO: Output the Benchmark name here
			for( const Result& result : resultContainer.Results() )
			{
				// TODO: Output each individual result here
			}
		}
	}
}
```

There are some helper methods in the ResultContainer: ```ResultContainer::AverageResult()```,
```ResultContainer::ShortestResult``` and ```ResultContainer::LongestResult```

Filtering the output
=======================
It is possible to filter the output by setting a filter on a ResultContainer.
The filter is then asked on every log result if it should be considered in the output or not.
Filters can be applied by using the ```ResultContainer::Filter(myFilterPtr)``` Method.

## Custom Filters

To create a custom filter you need to implement the ```bpp::IResultFilter``` interface:

```cpp
class MyFilter : public bpp::IResultFilter
{
public:
	//Optional, can be used to prepare filtering which is relative to the results
	virtual void PrepareFilter( const std::vector<Result>& /* container */ ) override;

	// Return true, if the result should be filtered out and not be considered while logging, false otherwise
	virtual bool FilterResult( const Result& result ) override;

};
```
