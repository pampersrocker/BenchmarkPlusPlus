#pragma once
#ifndef BPPResult_inl__
#define BPPResult_inl__

namespace bpp
{

	Result::Result( const TimeSpan& span, const BenchmarkarbleItem* item, const BenchmarkScope* scope ):
		m_Item(item),
		m_Scope(scope),
		m_Span(span)
	{

	}

	inline Result::~Result()
	{

	}

	inline const Result::BenchmarkarbleItem* GetItem() const
	{
		return m_Item;
	}
	inline const Result::BenchmarkScope* Scope() const
	{
		return m_Scope;
	}

	inline const Result::TimeSpan& Span() const
	{
		return m_Span;
	}

}

#endif // BPPResult_inl__
