#pragma once
#ifndef BPPFactoryItem_h__
#define BPPFactoryItem_h__

namespace bpp
{
	class IFactoryItem
	{
	public:

		virtual void Initialize( void ) = 0;

		virtual void Run( void ) = 0;

		virtual void Release( void ) = 0;

	protected:
	private:
	};
}

#endif // BPPFactoryItem_h__
