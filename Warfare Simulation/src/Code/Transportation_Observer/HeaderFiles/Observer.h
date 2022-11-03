#ifndef __Observer_h__
#define __Observer_h__
using namespace std;

class Observer
{
	public:
		virtual void update() = 0;
		Observer();
		~Observer();
};

#endif
