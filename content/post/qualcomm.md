+++
title = "高通Compiler岗面经"

date = 2021-12-06T10:58:00
lastmod = 2021-12-06T12:48:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = []
summary = ""

+++

地里居然完全没有高通的面经就离谱。当然我们这个岗位人少也是一个原因吧。

高通大概花了半个月才给我来约面试。 
还是一个聊天机器人来约的立马下头，更神秘的是，周四下午来约周五， 下周一/二的面试。这时间也太磕巴了。
幸好我第二天周五早上有空，给了八点的时间。
更奇妙的来了， 给我发了个面试confirmation的模板， 上面的面试官没写。
这波啊， 这波是不许背景调查面试官（？）

<figure>
  <img src="/img/post/qualcomm/confirmation.png"/>
</figure>

最后更更更奇妙的是， 聊天机器人过了一个小时又给我约了一次， 我还是选的第二天八点。（复习不存在的）
然后我就收到两封confirmation 模板， 两个teams链接， 面试的时候根本不知道点哪个（？）

好了八点早起一杯美式下肚， 选择第一个teams link， 等了五分钟没人。
面试官打电话给我，说是第二个链接，我直接笑死， 贵司还是招点hr吧机器人真的屑。
面试官是个中国人， 口音挺重一度让我觉得这个哥们大不了我几岁。 但是网上搜了一圈也找不到这个人，搞不好他也在地里就不报名字了（

开始面试， 起手还是介绍一下组里干什么的。
编译器组基本就是跟进每一代芯片， 只不过这次是arm cortex。
基本在中后端优化，还得在每代芯片上编译安卓。
同时要和所有customer对接。
这里给我说傻了， 可能是中式英语一下子“用户 = customer”， 搞得我以为贵司编译器也是个对外业务， 结果一问customer指公司内部用编译器的组， which基本就是所有组（？）

常规介绍一下自己的第一个项目。
这个面试官听的比较认真， 也有follow up questions。
除了具体实现细节不表以外， 还问我修改了哪些pass， 我说没有我的pass是“from scratch”， 面试官悦。
所以第二个项目压根没讲， “我知道你懂LLVM”了， 此处有伏笔。

下面激情的来了， “Let me ask you something about architecture.” 此处还是伏笔
我内心： 你是把我当造芯片的怎么的？要不你还是顺着英伟达的面试官问Loop unrolling吧？
四年前的本科两年前的研究生课程是我体系结构的全部知识，就凭着记忆答了基本。

Pipeline的五个阶段。 是不是所有指令都走完五个阶段？
问了Sotre， ALU， Branch几个指令， 分别哪些阶段没走完。
我一开始还没反应过来ALU指令是啥， 然后才想起来。
Branch我说有长jump和短jump， MIPS是有区别的，也解释了区别， 其他结构我不知道。
具体的答案都是本科体系结构自己去找吧， 我答出来了懒得再写。

走不完的阶段会有bubble， 我们该怎么办。
这里我从优化的角度回答了可以减少jump啦， reorder instruction啦。
有没有bubble的案例？有没有非jump的bubble案例？
第二个我不知道了， 但他一说ADD STORE我就想起来了。
那体系结构层面有什么办法处理bubble？
我说有forwarding。
好， 那ADD STORE 是从哪forward到哪。

内存很慢的， 有什么办法来缓解？Cache。
好， L1 Cache要不要write through？
前面还算过的快， 但是到这里我基本san值已经掉完了，我冷静了五秒， 问了一句， 额我没做过太多体系结构， L1是离处理器最近的是吧？
他说是， 我说那就是要的， L1只在一个核心上，为了多核之间能获取同样内存要write through。
解释了一大堆，面试官提起一个遥远的术语“Yes， for memory coherence”。
哦，我说了半天就是重新发明了memory coherence。

他说看来你确实在体系结构上工作很少。
我说不是很少， 我就没有做过体系结构的工作， 我也不知道你为什么要问这么多体系结构， 说实话我刚刚给你的所有答案都在我从几年前的专业课上记住的东西。
他说：

“I READ YOUR POSTS.”

那一刻是真的绝望。
前面的伏笔来了， 他不问LLVM我猜就是读完我的[面](../nvidia)[经](../nvidia_2)基本认定我会了， 听一下第一个项目确定我没在吹逼就行。

他说我看了你的面经， 本来准备和你深♂入交流一下， 结果manager不同意，说要标准化面试流程。
潜台词“编译器我也没啥好问的你大概都会， 只好搞点体系结构来‘标准化’面试了”。

说得好，那你为什么不问操作系统（大写的冷漠在脸上）
虽然我操作系统也菜，但总是比体系结构强一点

好了还剩五分钟了你还有没有什么觉得我没问道的想说的？
这个问法也太怪了， 但我还是把编译器流程走了一遍， 其实没什么必要他知道我知道， 但是当时没反应过来。
然后因为我说到assembler就结束了他follow up了一下linker的问题。 
assembler之后还有什么工具吗， linker具体是做什么的。
显然他认为linker是compiler的一部分， 但是这个问题在stackoverflow的[discussion](https://stackoverflow.com/questions/33712987/is-the-preprocessor-assembler-and-linker-a-part-of-the-compiler)里也没什么定论。
我倾向于认为linker是一个体系结构相关的binary tools而不是compiler的一部分but who knows。

这就面试完啦撒花。