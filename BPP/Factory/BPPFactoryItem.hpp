#pragma once
#ifndef BPPFactoryItem_h__
#define BPPFactoryItem_h__

namespace bpp
{

	class IFactoryItem
	{
	public:

		inline IFactoryItem() :curScenario(nullptr) { }


		virtual void Initialize( void ) = 0;

		virtual void Run( void ) = 0;

		virtual void Release( void ) = 0;

	protected:

		BenchmarkScenario* curScenario;

	private:
		
		friend class Benchmarker;
		
		inline void SetScenario( BenchmarkScenario* scenario )
		{
			curScenario = scenario;
		}
	};
}

#endif // BPPFactoryItem_h__
