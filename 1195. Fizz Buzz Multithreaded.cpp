class FizzBuzz {
private:
    int n;
public:
    mutex nm;
    mutex fizzm;
    mutex buzzm;
    mutex fizzbuzzm;
    FizzBuzz(int n) {
        this->n = n;
        fizzm.lock();
        buzzm.lock();
        nm.lock();
        fizzbuzzm.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i=1;i<=this->n;i++){
        if(i%3==0&&i%5){
        fizzm.lock();
        printFizz();
        nm.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i=1;i<=this->n;i++){
            if(i%5==0&&i%3){
            buzzm.lock();
            printBuzz();
            nm.unlock();
            }
        }
    }
    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i=1;i<=this->n;i++){
            if(i%15==0){
            fizzbuzzm.lock();
            printFizzBuzz();
            nm.unlock();
    }
    }
    }
    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i=1;i<=this->n;i++){
        if(i%15==0){
            fizzbuzzm.unlock();
            nm.lock();
        }
        else if (i%3==0){
            fizzm.unlock();
            nm.lock();
        }
        else if (i%5==0){
            buzzm.unlock();
            nm.lock();
        }
        else {
            printNumber(i);
        }
    }
}
};