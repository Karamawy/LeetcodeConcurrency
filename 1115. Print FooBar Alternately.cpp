class FooBar {
private:
    int n;
    mutex barm;
    mutex foom;
public:
    FooBar(int n) {
        this->n = n;
        this->barm.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	this->foom.lock();
        	printFoo();
            this->barm.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	this->barm.lock();
        	printBar();
            this->foom.unlock();
        }
    }
};