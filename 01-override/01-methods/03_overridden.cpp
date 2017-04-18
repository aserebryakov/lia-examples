#include <iostream>
#include <memory>


class Base {
	public:
		Base() = default;

		virtual void f1() {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}

		virtual void f2() const {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}

		virtual int f3(const int& arg) {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return arg;
		}

		virtual double f4(const double& arg) {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return arg;
		}
};


class Derived : public Base{
	public:
		Derived() = default;

		virtual void f1() override {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}

		virtual void f2() const override {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		}

		virtual int f3(const int& arg) override {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return arg;
		}

		virtual double f4(const double& arg) override {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
			return arg;
		}
};


int main() {
	std::unique_ptr<Base> p = std::make_unique<Derived>();
	p->f1();
	p->f2();
	p->f3(42);
	p->f4(3.14);

	return 0;
};

