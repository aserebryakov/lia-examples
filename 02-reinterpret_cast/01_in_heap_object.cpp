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
    auto ptr = std::make_unique<FooBar>();

    (static_cast<BarBase*>(ptr.get()))->bar();
    (static_cast<FooBase*>(ptr.get()))->foo();
    (reinterpret_cast<BarBase*>(ptr.get()))->bar();
    (reinterpret_cast<FooBase*>(ptr.get()))->foo();

    return 0;
}
