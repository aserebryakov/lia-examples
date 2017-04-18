#include <iostream>
#include <memory>
#include <vector>


class Data {
	public:
		Data() = default;

		~Data() {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		};
};


class Base {
	public:
		Base() = default;

		virtual ~Base() {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		};
};


class Derived : public Base {
	public:
		Derived() : data(2) {
		}

		virtual ~Derived() override {
			std::cout << __PRETTY_FUNCTION__ << std::endl;
		};

	private:
		std::vector<Data> data;
};


int main() {
	std::unique_ptr<Base> p = std::make_unique<Derived>();
	return 0;
};

