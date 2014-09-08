#pragma once
#ifndef BPPResult_h__
#define BPPResult_h__

namespace bpp
{
	class Result
	{
	public:
		Result( const TimeSpan& span, const BenchmarkarbleItem* item, const BenchmarkScope* scope );
		~Result();

		const BenchmarkarbleItem* GetItem() const;
		const BenchmarkScope* Scope() const;

		const TimeSpan& Span() const;


	private:
		const BenchmarkarbleItem* m_Item;
		const BenchmarkScope* m_Scope;

		TimeSpan m_Span;
		
	};


}

#include "BPPResult.inl"

#endif // BPPResult_h__
