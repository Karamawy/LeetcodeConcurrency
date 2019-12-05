class ZeroEvenOdd {
private:
    int n;
public:
    mutex zm;
    mutex om;
    mutex em;
    ZeroEvenOdd(int n) {
        this->n = n;
        zm.lock();
        om.lock();
        em.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
         printNumber(0);
         if(i&1){
            om.unlock();
            zm.lock();
         }
            else {
            em.unlock();    
            zm.lock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            if(!(i&1)){
                em.lock();
                printNumber(i);
                zm.unlock();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            if(i&1){
                om.lock();
                printNumber(i);
                zm.unlock();
            }
        }
    }
};