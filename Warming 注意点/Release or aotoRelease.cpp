2014-03-24
	实际上，autorelease()并不是毫无代价的，其背后的垃圾池机制同样需要占用内存和CPU资源，每次执行autorelease()
的过程，实际上对应的是执行成对的retain()和release()，以及一次成对的容器存取，还包括其他的逻辑判断。过多不
必要的autorelease()将导致垃圾池臃肿膨胀，在存在大量内存操作的程序中会尤为严重地挤占本来就紧张的系统资源。
  此外，autorelease()只有在自动释放池被释放时才会进行一次释放操作，如果对象释放的次数超过了应有的次数，则这个
错误在调用autorelease()时并不会被发现，只有当自动释放池被释放时（通常也就是游戏的每一帧结束时），游戏才会崩
溃。在这种情况下，定位错误就变得十分困难了。例如，在游戏中，一个对象含有1个引用计数，但是却被调用了两次
autorelease()。在第二次调用autorelease()时，游戏会继续执行这一帧，结束游戏时才会崩溃，很难及时找到出错的地
点。
	因此，我们建议在开发过程中应该避免滥用autorelease()，只在工厂方法等不得不用的情况下使用，尽量以release()来
释放对象引用。
