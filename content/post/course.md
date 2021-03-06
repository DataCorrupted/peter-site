+++
title = "高级交通工具研发与制造"

date = 2020-05-17T12:36:00
lastmod = 2020-05-17T23:59:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["Life"]
summary = "本课程将教授高级交通工具的研发和制造, 请同学们系好安全带, 火箭要发射了"

+++

### 前言

事情是从前两天的一个朋友圈开始的.

<figure>
  <img src="/img/post/course/moment.jpg" width = 50%/>
</figure>


然后我回顾了一下我本科上过的课熬过的夜, 当年开过的"上课作业考试项目四维正交"的玩笑. 
遂扩充了一下写成下文.

以下内容纯属虚构.

## 课程基本信息

编号: CAR250

标题: 高级交通工具研发与制造

先修要求: 深入基础交通工具的研发, 制造与使用

课程简介: 本课程专注于高级交通工具的研发, 尤其是现阶段火热的可复用火箭制造. 
本课程将以马斯克的猎鹰系列为蓝图给学生讲解可复用火箭的现状和前景.
本课程注重实践, 故大部分分数被安排在了课程项目上. 
课程项目四人一组, 将着重把课程内容应用到实际生活中去, 且提供了相当的奖励分数供学有余力的同学.

教授: 一研究**自行车**的

课程评分:

- 作业: 3% * 10
- Quiz: 1% * 10
- 期中考试: 5%
- 期末考试: 15%
- 课程项目: 40%(+20%)

## 授课内容

- SpaceX 简介
- SpaceX 的财务状况和商业前景
- 使用高级交通工具移民火星的可行性
- ......

## 作业

- 请算出以下21速自行车的最高时速和骑行者的能量消耗
- 阅读"低功耗极快速两轮交通工具: 一种全新的方法"(一篇把自行车铝制车身换成碳纤维车身的水逼论文)并写paper review.
- 课上我们探索了月球上交通工具的特殊性, 请设计一辆月球自行车, 并指出和地球自行车的不同

## Quiz

- 我们介绍了逃逸地球引力的临界速度, 请设计能逃逸银河系的飞船
- 我们刚刚讲了如何用火箭发射卫星, 请写出马斯克的天链计划(Sky link, 是不是这么翻译啊hhh)实现一箭60星的具体操作方法

## 考试

- 我们讲过开火箭不需要方向盘, 请说说为什么汽车需要方向盘?
- 为什么不能把汽车加速到20km/s? 40km/呢?(提示: 两个问题的原因并不相同)
  
## 课程项目

### 题目

造一辆汽车

- 研发: 拥有完整的设计蓝图(10%)
- 制造: 完成一辆汽车(10%)
- 使用: 可以驾驶(10%)
- 性能: 时速可以超过90km/h(10%)

奖励目标:

- 你的汽车时速可以超过120km/h (+10%)
- 你的汽车时速可以超过200km/h (+10%)

### 头脑风暴

你: 要造车的话我们得先造一个轮子诶

队友们:  

- <span style="color:black">**普通队友**</span>: 轮毂我熟我可以负责造这个
- <span style="color:blue">**精良队友**</span>: 我们可以先造一个**128边形**近似一个轮子来应对π的数值计算过于复杂的问题
- <span style="color:purple">**史诗队友**</span>: 车上的四个轮子有不同的功能啊, 我们得造**4个**功能不同的轮子
- <span style="color:orange">**传说队友**</span>: 每个轮子都得有**跑马灯**且形状各异

<figure>
  <img src="/img/post/course/mess.jpg" width = 50%/>
</figure>

摸鱼怪们:  

- <span style="color:black">**普通摸鱼怪**</span>: 你们说的对
- <span style="color:blue">**精良摸鱼怪**</span>: (使用**百度搜索**网上冲浪了**10分钟**都找不到**百家号**以外的内容, 你们都已经开始讨论轮子是要128边形还是256边形的时候, 通过阅读**百度知道**搞明白了什么是轮子) 你们说的对
- <span style="color:purple">**史诗摸鱼怪**</span>: (在和男朋友/女朋友聊QQ/WeChat, 面带笑容, 一言不发)
- <span style="color:orange">**传说摸鱼怪**</span>: (没来)

### 工程难题

- 你的<span style="color:black">**普通队友**</span>以前做过轮毂所以造出了一个非常优秀的轮毂, 但是没有队员会生产轮胎
- 所以你们决定在256边形轮毂的基础上上一起造轮胎, 但你们不知道π用3.14159好还是3.14好, 你的<span style="color:orange">**传说队友**</span>坚持要用到小数点后100位.
- 但是无论用小数点后多少位你们的轮子都不怎么好转(因为你们的轮毂是256边形的!)
- 你在CarOverflow上看到有人说π取3可以造出一个完美的**齿轮**, 你寻思这玩意儿和轮胎差不多都是圆的, 于是说服了队友问题是**小数点**导致的, 应该用**π = 3**才对
- <span style="color:purple">**史诗队友**</span>以你们现有的轮子为蓝图造出了四个**大小不一**的轮子, 坚持认为转向轮要比其他轮子小才能应对车身颠簸的问题, 丝毫没有意识到这个世界上有个东西叫减震器.
- 你的<span style="color:black">**普通摸鱼怪**</span>参与了你们的研发, 但是什么都没干
- 你的<span style="color:blue">**精良摸鱼怪**</span>试图参与到研发中混参与分, 但是一不小心扎破了你们好不容易生产出来的轮胎.
- 其他摸鱼怪**从来没有**出现过

### 明天死线

现在你们有了四个大小不一, 轮毂精良, 轮胎破破烂烂但是勉强能滚的轮子, 你们想起起来课题本来是造辆车, 而且明天死线.

- <span style="color:black">**普通队友**</span>: 我们只要把四个轮子连起来就可以得到一辆车, 为了获得驾驶分我们要加上座椅就可以了
- <span style="color:blue">**精良队友**</span>: 大小不同的轮子是不能跑到90km/h的, 最好在轮子外面**搓圈泥**, 这样轮子半径就一样了
- <span style="color:purple">**史诗队友**</span>: 虽然我们没有引擎可以把轮子加速到那么快, 但是只要初速度够大就行了, 我建议在车子后面绑一些炸药, 然后我们可以解释我们的方法和内燃机的原理是一样的, **都是爆炸**.
- <span style="color:orange">**传说队友**</span>: 我想摸到200km/h的奖励分, 我觉得我们需要研究一下炸药用什么材料比较好. 你记得课上讲的航空燃料吗?

你们熬夜爆肝了一晚上(外加一个白天)

<figure>
  <img src="/img/post/course/light.jpg" width = 50%/>
</figure>

### 展示当天

- <span style="color:purple">**史诗摸鱼怪**</span>要求参与车辆驾驶测试混展示分, 你的队友们很开心因为**没人敢坐自己造的东西**; <span style="color:orange">**传说摸鱼怪**</span>还是没来
- 因为~~炸药~~高能燃料安装角度问题车子以300km/h的速度飞上了天, 你的<span style="color:orange">**传说队友**</span>和助教争论项目要求里并**没有指明汽车要朝哪个方向加速**到这么快所以应该得分, 甚至试图多要一点分因为速度实在是太快了.
- 助教很难办让你们把轮子拆下来看看能不能转, 于是你派剩下两个摸鱼怪当着全班的面滚轮子
- 你热情洋溢的解释这个由 **256边形轮毂, π = 3造出来的轮胎和糊了一圈泥巴的轮子** 有什么工业轮子都解决不了的高端功能
- 还非要说在车底加高能燃料是对内燃机的一种**重大改进**.
- 面对同学质疑你硬说糊的一圈泥巴是**高性能陶瓷** 并且口胡了一个要把**高性能陶瓷**搓在轮胎外面的原因, 虽然泥巴是今天**早上五点**才糊上的, 而且你自己都不知道你在说啥.

<figure>
  <img src="/img/post/course/pre.png" width = 50%/>
</figure>

### 教授提问

**你们到底造了个啥? 汽车形的火箭?**

## 成绩

多亏了你<span style="color:orange">**传说队友**</span>关于论项目要求里并**没有指明汽车要朝哪个方向加速**的争论, 你们获得了全部的项目分(60%)

倒不是你们做的有多好, 而是你们是为数不多的能动的车子; 其他组能做个**车子模型**就算不错的了.

<span style="color:orange">**传说摸鱼怪**</span>连作业和考试都没去, 但是队友太厉害了正好过关.

<span style="color:black">**普通摸鱼怪**</span>正在因为作业抄袭被学术诚信委员会调查

其他摸鱼怪低分飞过

<span style="color:black">**普通队友**</span>摸到了A-他很开心

杀千刀的教务处不允许超过20%的人得A所以你和另外<span style="color:black">**三**</span><span style="color:blue">**个**</span><span style="color:purple">**队**</span><span style="color:orange">**友**</span>疯狂内卷, 最终你因为期末考试没看到最后一道大题(真人真事)只得了117%, 其他人获得了120%满分.

教务处不得不让步给了他们每人一个A+, 你得了A.

最终评分结果是一个双峰分布: 是一半人刚好过关, 一半人是A-, A和A+.

助教含恨在项目要求里加上了"在地面上加速到200km/h"的要求, 希望下一年别再出什么幺蛾子.  
(你猜下一年会不会有人魔改星球的引力值: "加速到200km/h, 你没说是在地球上还是在月球上啊?")

## 说点别的

我开始建这个号只是为了连接我不同的朋友, 既不用把一些琐事都在朋友圈广而告之, 又可以不用在高中朋友, 大学朋友和父母之间复读.
所以我以为关注的人不会超过10个. 所以我在后台都小心的给每个人备注了姓名.

我那天发了养娃焦虑截图以后看了下后台猛然发现已经57关注了.
这个数量不多但是远超我的想象. 很多人我完全备注不了, 不认识.

我后来和高雅开玩笑, "这些人都没有我的好友怎么找到这个号的, 难道腾讯也和知乎一样给我塞粉吗". 
她解释说应该是从她点的再看点进来的. 我寻思那情况应该就是"嘿我朋友看的这沙雕看着有点意思关注了". 

但我更希望你们谨慎点再看, 我早就认识到我的观点和主流观点有出入, 而很不幸我们不在一个能容纳的下不同的声音是环境.
我也已经过了那个想把什么东西都广而告之恨不得全天下都知道的年纪. 
树大招风, 小圈子乐呵挺好的.
~~觉得好看想支持就直接打红包呗(狗头~~

我倒是很希望你们能加上我的微信, 我可以知道你们想看什么, 也可以听到你们的故事.(这个二维码七日有效)

<figure>
  <img src="/img/post/course/QR.png"/>
</figure>


现在这个关注量注定我要开始发些阳间人看的东西了. 
本来在酝酿的一篇需根解损的文章准备这周六写的, 结果**xbox太好玩了**(狗头 * 2), 遂在负罪感的驱动下在周日晚上敲下了这一篇.

最近还有催更星际争霸的朋友, 嗨呀写东西很累的一周一篇最多了, 慢慢等哦, **咕咕咕**.
