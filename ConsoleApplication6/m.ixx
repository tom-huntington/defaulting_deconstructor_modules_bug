module;
#include "pch.h"
#include <memory>
#include <iostream>
export module m;
export struct Impl;

export
class S {
public:
	S();
	~S();
	void do_stuff();
	Impl* get() const { return impl.get(); }
private:
	std::unique_ptr<Impl> impl;
};

module :private; // Everything beyond this point is not available to importers of 'm'.

struct Impl {
	void do_stuff() {
		std::cout << "hello Modules\n";
	}
};

S::S() :
	impl{ std::make_unique<Impl>() }
{
}

// works
//S::~S() { }
// doesn't
S::~S() = default;

void S::do_stuff() {
	impl->do_stuff();
}