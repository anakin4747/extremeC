# Multithreading

Every thread is initiated by a process. Every process has a main thread. Since all threads are from the same process they all share the same PID. A thread inherits all of its owner process's properties. Each thread has its own Thread ID (TID). All the threads in a process have access to all the same file descriptors. This also goes for socket descriptors and open sockets.

A threads lifetime is bound to the owner process's lifetime.

For more info:

    $ man pthreads 

