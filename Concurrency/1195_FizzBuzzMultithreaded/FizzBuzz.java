// Your runtime beats 100.00 % of java submissions

class FizzBuzz
{
    private int n;
    private final Object monitor = new Object();
    private boolean runFizz = false;
    private boolean runBuzz = false;
    private boolean runFizzBuzz = false;
    private boolean outputNum = true;
    private int i = 1;

    public FizzBuzz(int n)
    {
        this.n = n;
    }

    public void check(int i)
    {
        if (i > n)
        {
            runFizz = true;
            runBuzz = true;
            runFizzBuzz = true;
            outputNum = true;
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            runFizz = false;
            runBuzz = false;
            runFizzBuzz = true;
            outputNum = false;
        }
        else if (i % 3 == 0)
        {
            runFizz = true;
            runBuzz = false;
            runFizzBuzz = false;
            outputNum = false;
        }
        else if (i % 5 == 0)
        {
            runFizz = false;
            runBuzz = true;
            runFizzBuzz = false;
            outputNum = false;
        }
        else
        {
            runFizz = false;
            runBuzz = false;
            runFizzBuzz = false;
            outputNum = true;
        }
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException
    {
        synchronized (monitor)
        {
            while (i <= n)
            {
                while (!runFizz)
                {
                    monitor.wait();
                }
                if (i > n)
                {
                    return;
                }
                printFizz.run();
                check(++i);
                monitor.notifyAll();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException
    {
        synchronized (monitor)
        {
            while (i <= n)
            {
                while (!runBuzz)
                {
                    monitor.wait();
                }
                if (i > n)
                {
                    return;
                }
                printBuzz.run();
                check(++i);
                monitor.notifyAll();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException
    {
        synchronized (monitor)
        {
            while (i <= n)
            {
                while (!runFizzBuzz)
                {
                    monitor.wait();
                }
                if (i > n)
                {
                    return;
                }
                printFizzBuzz.run();
                check(++i);
                monitor.notifyAll();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException
    {
        synchronized (monitor)
        {
            while (i <= n)
            {
                while (!outputNum)
                {
                    monitor.wait();
                }
                if (i > n)
                {
                    return;
                }
                printNumber.accept(i);
                check(++i);
                monitor.notifyAll();
            }
        }
    }
}