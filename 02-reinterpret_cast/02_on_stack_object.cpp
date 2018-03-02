#include <iostream>
#include <memory>


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
    FooBar obj;

    (static_cast<BarBase*>(&obj))->bar();
    (static_cast<FooBase*>(&obj))->foo();
    (reinterpret_cast<BarBase*>(&obj))->bar();
    (reinterpret_cast<FooBase*>(&obj))->foo();

    return 0;
}
