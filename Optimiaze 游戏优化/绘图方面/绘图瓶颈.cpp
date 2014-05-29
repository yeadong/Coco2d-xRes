绘图瓶颈
  影响绘图的因素有很多，我们不可能对其进行十分详细的分析。然而在Cocos2d-x中，影响游戏性能的瓶颈通常只有以下
几个方面。
  纹理过小：OpenGL在显存中保存的纹理的长宽像素数一定是2的幂，对于大小不足的纹理，则在其余部分填充空白，这无
疑是对显存极大的浪费；另一方面，同一个纹理可以容纳多个精灵，把内容相近的精灵拼合到一起是一个很好的选择。
  纹理切换次数过多：当我们连续使用两个不同的纹理绘图时，GPU不得不进行一次纹理切换，这是开销很大的操作，然而当
我们不断地使用同一个纹理进行绘图时，GPU工作在同一个状态，额外开销就小了很多，因此，如果我们需要批量绘制一些
内容相近的精灵，就可以考虑利用这个特点来减少纹理切换的次数。
  纹理过大：显存是有限的，如果在游戏中不加节制地使用很大的纹理，则必然会导致显存紧张，因此要尽可能减少纹理的
尺寸以及色深。