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

BPP_END_BENCHMARK( MyScope, MyBenchmark )
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

BPP_END_BENCHMARK( MyScope, MyOldCode )

BPP_BEGIN_BENCHMARK( MyScope, MyNewCode )

	BPP_BENCHMARK
	{
		// Your new code
	}

BPP_END_BENCHMARK( MyScope, MyNewCode )
```

Here the old code gets compared to the new code. The Scope and Name declaration together
must be unique over the whole project it is running in.

Initialization, Variables & Release
====================

You usually want to test your code on some data which should be already initialized before the actual benchmarking.
To achieve this you can define variables inside the ```BPP_BEGIN_BENCHMARK(...)``` and ```BPP_END_BENCHMARK(...)```
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

BPP_END_BENCHMARK( MyScope, MyBenchmark )
```

These variables are defined in a class scope and are only available in those three methods.


Benchmarking
==================

The actual Benchmarker needs to be called in some sort of main function:

```cpp
#include "bpp.hpp"
#include "Logging/BPPDefaultConsoleLogger.hpp"

using namespace bpp;

int _tmain(int argc, _TCHAR* argv[])
{

	Benchmarker& instance = Benchmarker::Instance(); // Get the global Benchmarker

	DefaultConsoleLogger logger; // Create some logger for the Benchmarker, to actually get some output

	instance.AddLogger( &logger );

	instance.Run();

	instance.Log();

	instance.Release();


	return 0;
}
```
