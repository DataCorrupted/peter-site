+++
title = "UCD课程感受"

date = 2021-06-04T17:58:00
lastmod = 2021-06-05T08:58:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["Life"]
summary = "UCD课程感受"

+++

## 起因

想到写这个东西的原因有俩。
一个是看到一个CMU的朋友毕业了写了一篇[CMU课程感受](https://mp.weixin.qq.com/s/jmpZiA-vX5xvYywwKxbzzw)，看到他们的课程羡慕的不行。
另一方面，明天最后一场期末考试意味着我在UCD的课程也确实结束了，九门课上完开始准备QE了， 确实应该写个小结。

实际上博士生需要读十门课的， 但是我从上科大transfer了一门CS283 Robotics过来， Danka, Sören.

<figure>
  <img src="/img/memes/no-problem.jpg"/>
</figure>


那么坐和放宽， 我们要开始了。

## 课程感受

### ECS240 Programming Languages

这门课虽然叫Programming languages， 但是和编程语言倒是关系不大...
我本来是当做加强版编译原理打算的， 以为会学到很多设计编程语言的细节， 类型理论， GC之类的东西
结果教授Thakur是做程序分析的，所以课程内容也以静态分析偏多， 基本的静态分析技术都讲了一遍。
课程工作量不是很大， 基本上听课写作业考试就可以了。
真人真事， 期末考试我最早把卷子写完寻思这帮人怎么这么慢等了他们十分钟还是先交卷跑了，然后发现最后还有一页...

### ECS289I Networks

我本来以为会是讲当代网络结构， 没想到教授是个搞物理出生的， 来给我们讲图论。
这门课也很轻松， 考试都没有就四次作业， 基本就是把课上的结论延伸推导一下， 给分蛮友好的。
课上介绍了一些基本的图论算法， 推导了一些有意思的结论， 六度分隔理论理论（你和任何一个陌生人之间所间隔的人不会超过六个）， 友谊悖论（一个人的朋友数量往往比他朋友的朋友数量要少）， 传染病的稳态， 用线性计算来模拟图论计算， etc。
总之不是很计算机...更像是应用数学课。

<figure>
  <img src="/img/post/ucd/Denethor-LOTR.jpg"/>
  <figcaption>想象一下这个悲痛的摄政王给你讲线性系统</figcaption>
</figure>

值得一提的是这个老师非常像John Noble演的刚铎摄政王, 所以听他讲课还是挺有意思的？

### ECS399 Teaching in Computer Science

这是要当TA必须要选的一门课。
一个系里面做了很多年TA的学生给我们开的课， 个人觉得没有特别大的收获， 尤其是有很多小组讨论环节， 本社恐直接自爆。
这门课讨论了很多教学小朋友的时候会遇到的问题，但是我大部分时候在摸鱼所以没听很认真， 实在是太摸鱼了以至于这门课挂了一次...（丢人

### ECS251 Operating Systems

我心中的两大浪漫：操作系统和编译原理。
学这种东西总像是流浪地球， 一千行就可以跑， 一百万行也写不完。
随便挑一个小话题都有无限可以挖掘的空间。

其实我在本科就读过UCD的操作系统了...那个时候我老板还在国内教职， 直接把davis的研究生操作系统搬到了我本科，我还就学了。
但是我那时候学的很摸鱼的， 这次就认真学了一遍。

操作系统的展开是我比较认可的“读论文， 讲论文， 做project， 写presentation”的形式， 科研要用的基本能力都有训练到。
所以一开始还是挺激动的。尤其是刚开学的时候Sam亲自讲了几篇古早文章， 真的非常激动人心。
不过随着时间的推进， 大家实在是太摸鱼了Sam不断降低课程标准， 也就莫名其妙的变成了划水课。
Sam本以为搞一篇论文帮大家复习一下OS就可以了，没想到复习了两个星期...
即使如此， Sam亲手挑出的大部分paper我都读了，在这样一个庞大的领域即使有人指个方向也是极好的。

另外我很喜欢Sam的一点是他在项目上给的指导挺好的， 虽然我们开题很宏大的要用rust写一个树莓派操作系统， 最后写成了一个千把行的bare bone， 才把内存管理写了个大概就结束了。
（参考我写的[高级交通工具研发与制造](https://mp.weixin.qq.com/s/K-MiDZNbvHFEaN4JHh5RQQ)）
但还是觉得有不少收获， 一来是**被迫**读了ARM架构的开发指南， 甚至借机给开源库贡献了4行代码（没错真的只有4行，还有两行是注释...）， 然后有机会玩了下树莓派， 感受一下五六十年代在没有虚拟内存的情况下写（瞎）代（搞）码的感受，顺便从底层研究了一些内存相关的内容。
不过最终项目评分直接给了全A， “我看到了大家这学期的努力blabla”。

<figure>
  <img src="/img/post/ucd/ECS251.png"/>
  <figcaption>说出来你可能不信...这是我在davis所有课程里写过最多的代码了</figcaption>
</figure>

### ECS201A Computer Architecture

这是我在UCD体感最糟糕的一门课了，很难说我学到了什么东西。
评分只有quiz和考试， quiz只开卷课本， 不可以用笔记。所有答案都是literal的， i.e. 必须是原文， 原话， 写错三个单词基本就拜拜了。
实际的试题也就那些翻来覆去的问，你上不上课都没什么区别， 考前把那些题目背一下就好了。
然后Farren 张嘴就是“convey understanding”， 这简直和毛主席语录差不多了。

所以你问我这门课最后学到了什么， 无。 真的是一丁点都无。十个星期的课非常痛苦。
准备了一本[cheatsheet](https://github.com/DataCorrupted/ECS201A-Computer-Architecture)， 需要的朋友自取顺便求star。

### ECS220 Theory Of Computation

计算理论这门课一向是我心中的白月光。
难吗， 难， 想都想不明白， 但是你看完那些证明就是很有意思。
这些理论放在心里会给我一种莫名其妙的踏实感， 知道自己在写的代码有理论支撑。
一条代码可以被拆成十条指令， 再被拆成诸多~~我学不会~~的电路，而电路的基础是图灵机，不是玄学。
（真不是玄学吗？）

高阶的计算理论是直接从P和NP讲起的。
NPC几大问题激情互证， 记是不可能记住的， 也就每次都看下维基百科勉强维持生存的样子。

<figure>
  <img src="/img/post/ucd/Relative_NPC_chart.svg.png"/>
  <figcaption>几个NPC问题的规约方式， 图源维基百科</figcaption>
</figure>

（有点超纲了， 但是这一点不爽我一定要说）
我不太喜欢Doty用P time verifier定义NP的方式。 
NP字面义代表的是Nondeterministic Polynomial time。
你用P time verifier定义NP， 证明NPC 的时候就必须做出“我们假设SAT是NPC的”这种奇怪的假设； 用后者定义你可以直接用非确定性图灵机证明SAT是NPC的。

另一点就是我觉得Doty上课的顺序反了。
先说P， NP，再绕回来说可计算性， 然后再跑回去讲计算空间， 绕来绕去感觉挺奇怪的。

最最最后， 这门课只有作业， 作业是组队一起做， 但是**不要组路人局， 不要组路人局， 不要组路人局**。
真的， 作业不是很多， 一次也就四五题， 自己做也没有很累， **不要组路人局， 不要组路人局， 不要组路人局**。
我在UCD发现的一件事就是你永远不知道你的队友有多水。
我人生第一次被拉进SJA就是队友抄了网上的答案，而我对此完全不知情， 被连坐了...

这么想，在上科大随手一抓就是个肝帝的日子可能真的是世外桃源（？

<figure>
  <img src="/img/post/ucd/250px-Polynomial_time_hierarchy.svg.png"/>
  <figcaption>冷知识： 如果P=NP， 这个无限高的塔会被压平， 图源维基百科</figcaption>
</figure>

### ECS230 Applied Numerical Linear Algebra

很难说我一个数学渣为什么要选这个， 可能是出于意识到数学太差了的自我救赎（个屁）

前半个学期简单回顾了一下本科的数学知识， which我大概听了两三节觉得我自学也可以。
提到的另一个很有意思但我从来没想过的问题， IEEE754标准是有损的， 所以float和double类型的计算顺序（顺序！）会影响精度。
作业里会有精度分析。

课程最后两三周才来了干货， 介绍了一些对计算机友好的矩阵分解， 特征值、特征向量提取。
也有coding， 虽然是C+Fortran， 虽然写的是本科生就写过的“我们来看一看怎么算矩阵乘法最快”。
最后也介绍了迭代式求特征向量方法，[“两百五十亿美元的特征向量”](https://www.math.arizona.edu/~glickenstein/math443f08/bryanleise.pdf)， 早期google搜索驯服排序算法的珍贵论文， 写的非常洋洋洒洒， 很喜欢的一篇。

以及我的发言， “我又不是弱智”（注意发言的时间戳）

<figure>
  <img src="/img/post/ucd/0.jpg"/>
  <img src="/img/post/ucd/1.jpg"/>
  <img src="/img/post/ucd/2.jpg"/>
</figure>


### ECS235B Computer & Info Security

这门课给我的印象也不是非常深， Bishop照本宣科的讲自己写的书... 只有作业， 写完完事儿。

### ECS252 Computer Networks

这次是正经的计算机网络了。
然而颇为失望的是这是本科生的计网 _再 放 送_。

好吧没有那么无聊， 教授试图从概率论的角度分析congestion control之类的算法为什么工作。
~~什么？ 概率论，啪，我死了~~
但他确实是把所有协议重讲了一边， which... 这些东西网上都有有什么好说的吗.

所以我确实一节课都没去， 写作业， 考试。
考试非常无聊， 闭卷考试， 根本记不得各种公式。

我大约十个星期只学会了~~没有~~怎么用马尔科夫链？

### ECS222A Design & Analysis of Algorithm

我看了syllabus之后就觉得是一门摸鱼的课， 本来的计划是讲分治， 字符串算法， 随机算法和P，NP（再讲一遍...）。
结果到最后随机算法没讲，我唯一想听的随机算法没讲； 分治和PNP不需要听， 忘了就去维基百科再学~~亿~~遍； 字符串算法是用网络资源先学的..
Frid本人也只是lecturer， 类似于讲师， 所以讲的东西都蛮常规的， 而且速度很慢， 这就是最后没空讲随机算法的原因吧。
无作业， 只有quiz和考试， 时间很充分， 基本每次考试前~~量子速~~读一下需要考的知识点就可以了。

整堂课印象最深的是Frid的戒指是真的大（

## 写在最后

如果要我分类的话，davis的课大约可以分成三类：

- 激动人心： ECS251, ECS240， 这门课让我非常兴奋， 很想在教授探讨的话题上继续深入
- 还不错： ECS289I，ECS235B， ECS220， ECS230； 我觉得上这些课有点无聊， 可能是我以前学过的东西， 可能只是内容不能引起我的兴趣， 但是最终我能从课上学到一些东西， 在以后能不能用上不知道
- 浪费时间： ECS201A，ECS222A， ECS252。 这门课完全是在浪费学生和教授的时间，仅仅是为了完成学业所需而已，你不需要， 也不应该在这门课上花费任何经历， 我也不愿意和别人提起说UCD的计算机教育是这样糟糕的

再和CMU比较会觉得， 我的整个学生生涯都很欠缺工程训练。 
类似的训练， 如果有的话， 是我本科计算机网络， 我们用Java构建了五六千行的 __声音网络__， 而其中我们犯的各种错误也从来没有人指出来过， 往往是写了诸多代码以后发现屎山地下压着的是我的珍珠翡翠大白**菜**。
尤其是现在开始管理上万行的fuzzer以后， 时常在写代码的时候感到无力。

所以我在davis居然只写了...like 2000行代码， 我本科随便抓一门课出来都不止这些。
我的朋友甚至可以和我吹“读完了ms一行代码没写过”， 这是非常失望的。
老板的一个经典理论“多写代码不一定就会写， 但是行数不够的人一定写不好”， 但愿davis的课程这一点能改改， 有CMU一半肝都好。

另一方面就是我们讲的太杂了， 很多本应该深入的话题最终被涵盖在某一门课的某一个discussion里。
比如CMU有的Storage Systems， 我们只在OS里简单提了下就过了。
Sam要在十周课里面帮大家复习一下操作系统， 然后在每个分支里沾花捻草的讲一两周就过而没法深入， 是非常遗憾的一件事。

最后就是很多课程的缺失。
compiler相关的课程没有， 课程委员会可能以为240就是compiler（摊手
CMU有的web design， api design， 我们都没有， 可能这些都涵盖在了ECS265里面（？
Davis把课程分成“体系结构”， “系统”， “理论”， 和“应用” 四个方向， 我一开始觉得是很好的。
但是现实很骨感， 除了“应用”， which本来就应该有很多课程， 前三个方向往往只有1~2门课可以选， 未免过于寒碜。
