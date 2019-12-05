class Foo {
public:
    mutex firstm;
    mutex secondm;
    Foo() {
        firstm.lock();
        secondm.lock();
    }
    

    void first(function<void()> printFirst) {
        
        printFirst();
        firstm.unlock();
    }

    void second(function<void()> printSecond) {
        firstm.lock();
        printSecond();
        secondm.unlock();
    }

    void third(function<void()> printThird) {
        
        secondm.lock();
        printThird();
    }
};