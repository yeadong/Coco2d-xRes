如果你用cocos2d项目模板创建过项目，那么你已经看过它的效果了，就是左下角显示帧率的数字。
因为帧率一直在变，使用CCLabelTTF的话效率太低，因为只是数字所以也犯不上使用 CCLabelBMFont 加载那么大的文字图像，所以使用这个比较合适。