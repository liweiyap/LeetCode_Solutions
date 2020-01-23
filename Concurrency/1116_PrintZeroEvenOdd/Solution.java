// Your runtime beats 100.00 % of java submissions

class ZeroEvenOdd
{
    private int n;
    private final Object monitor = new Object();
    private boolean firstDigit = true;
    private boolean isOdd = false;
    private boolean isEven = false;

    public ZeroEvenOdd(int n)
    {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException
    {
        synchronized (monitor)
        {
            for (int i = 1; i <= n; ++i)
            {
                while (!firstDigit)
                {
                    monitor.wait();
                }

                // if (i < 10)
                // {
                printNumber.accept(0);
                // }

                if (i % 2 == 0)
                {
                    isEven = true;
                }
                else if (i % 2 == 1)
                {
                    isOdd = true;
                }

                firstDigit = false;
                monitor.notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException
    {
        synchronized (monitor)
        {
            for (int i = 2; i <= n; i += 2)
            {
                while (!isEven)
                {
                    monitor.wait();
                }

                printNumber.accept(i);
                isEven = false;
                firstDigit = true;
                monitor.notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException
    {
        synchronized (monitor)
        {
            for (int i = 1; i <= n; i += 2)
            {
                while (!isOdd)
                {
                    monitor.wait();
                }

                printNumber.accept(i);
                isOdd = false;
                firstDigit = true;
                monitor.notifyAll();
            }
        }
    }
}