### epoll
使用os提供的api如epoll，kqueue编写并发应用程序
*   epoll.cc，演示了epoll的通常用法，使用epoll的LT模式
*   epoll-et.cc，演示了epoll的ET模式，与LT模式非常像，区别主要体现在不需要手动开关EPOLLOUT事件

LT 和 ET本质的区别是：

LT模式状态时，主线程正在epoll_wait等待事件时，请求到了，epoll_wait返回后没有去处理请求(recv)，那么下次epoll_wait时此请求还是会返回（立刻返回了）；而ET模式状态下，这次没处理，下次epoll_wait时将不返回（所以我们应该每次一定要处理），可见很大程度降低了epoll的触发次数（记住这句话先）。