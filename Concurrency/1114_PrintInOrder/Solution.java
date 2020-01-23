import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Foo
{
    private final Lock lock = new ReentrantLock();
    private final Condition cond = lock.newCondition();
    private final int NUM = 3;
    private volatile int threadId = 0;

    public Foo(){}

    public void printInOrder(Runnable printGeneral, int id) throws InterruptedException
    {
        lock.lock();
        try
        {
            while (threadId % NUM != id)
            {
                cond.await();
            }
            threadId = (threadId + 1) % NUM;
            printGeneral.run();
            cond.signalAll();
        }
        finally
        {
            lock.unlock();
        }
    }

    public void first(Runnable printFirst) throws InterruptedException
    {
        printInOrder(printFirst, 0);
    }

    public void second(Runnable printSecond) throws InterruptedException
    {
        printInOrder(printSecond, 1);
    }

    public void third(Runnable printThird) throws InterruptedException
    {
        printInOrder(printThird, 2);
    }
}