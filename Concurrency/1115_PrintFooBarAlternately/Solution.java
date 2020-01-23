// Your runtime beats 33.62 % of java submissions.

class FooBar
{
    private int n;
    private final Object monitor = new Object();
    private boolean runFoo = true;

    public FooBar(int n)
    {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException
    {
        synchronized (monitor)
        {
            for (int i = 0; i < n; ++i)
            {
                while (!runFoo)
                {
                    monitor.wait();
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                runFoo = false;
                monitor.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException
    {
        synchronized (monitor)
        {
            for (int i = 0; i < n; ++i)
            {
                while (runFoo)
                {
                    monitor.wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                runFoo = true;
                monitor.notifyAll();
            }
        }
    }
}