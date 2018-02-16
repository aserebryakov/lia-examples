#include <iostream>


class FooBase {
    public:
        virtual void foo() const {
            std::cout << "Executing command : rm -rf /" << std::endl;
        }
};


class BarBase {
    public:
        virtual void bar() const {
            std::cout << "Executing command : ls" << std::endl;
        }
};


class FooBar : public FooBase, public BarBase {
};


int main() {
    FooBar foobar;

    ((BarBase*)(&foobar))->bar();
    ((FooBase*)(&foobar))->foo();
    (reinterpret_cast<BarBase*>(&foobar))->bar();
    (reinterpret_cast<FooBase*>(&foobar))->foo();

    std::cout << static_cast<BarBase*>(&foobar) << std::endl;
    std::cout << static_cast<FooBase*>(&foobar) << std::endl;
    std::cout << (BarBase*)(&foobar) << std::endl;
    std::cout << (FooBase*)(&foobar) << std::endl;
    std::cout << reinterpret_cast<BarBase*>(&foobar) << std::endl;
    std::cout << reinterpret_cast<FooBase*>(&foobar) << std::endl;

    return 0;
}
