+++
title = "星际争霸的艰辛之路:为什么开发时游戏总在崩溃?"

date = 2020-03-01T12:36:00
lastmod = 2020-03-01T12:36:00
draft = true

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Patrick Wyatt"]

tags = ["Translate"]
summary = " "

+++

2012年7月, 由Patrick Wyatt, 161 评论.

我一直在写魔兽争霸早期开发的故事,但是我最近读的一篇文章激励我开始疯狂写星际争霸的故事.
最后就变成了这个分三个部分,长二十多页的文章,来讲讲星际争霸的开发历史,以及我关于如何开发更加可靠的游戏代码的思考.
我会在接下来几天发布后面的部分.

- 本篇: 为什么开发时游戏总在崩溃
- 第二部分: 为什么我们本可以修复一些常见错误
- 第三部分: 一些修复的实现细节

## 星际争霸的起源

星际争霸开发了大约两年半,其中发布前一年多都非常紧张.
在开发期间,这个游戏里的bug多的就和白蚁巢一样.
尽管它的先行者(魔兽争霸I和II)比他们的竞品都要稳定的多,星际争霸崩溃的如此频繁以至于游戏测试都很难进行,而这个状况一直持续到了发布前.
即便如此,这个游戏还是在发布后进行了许多修补工作.

为啥?有太太太太太多理由了.

## 太空魔兽

星际争霸最早有一个颇为合理的一年开发周期,这样就可以在1996年圣诞节期间发布.

领导这个项目的和发起[破碎国度(Shattered Nations)_(视频)](https://www.youtube.com/watch?v=QGZwGyKkIkw)的是一伙人.
_破碎国度_ 是个回合制的策略游戏,作为 [X-Com](https://en.wikipedia.org/wiki/X-COM) 这个世界观下面的一个游戏, 本来是暴雪(Blizzard)1995年5月宣布的但是几个月后就取消了.

团队就这样被重新组建起来,打造一款能快速上市的游戏,这样暴雪就不会在游戏发布之间有太大的间隔.

- 1994 第4季度 – 魔兽争霸
- 1995 第4季度 – 魔兽争霸 II
- 1996 第4季度 – 计划的星际争霸发行日期
- 1998 第2季度 – 实际发行日期
  
现在回想起来想急忙赶工出一个游戏这种决定挺可笑的,但是公司总裁艾伦(Allen Adham)承受着压力要增长收入.
因为尽管暴雪早起的游戏都比预计中要成功的多,这也提高了人们对未来增长的预期.

鉴于有限的时间和人力,星际争霸团队的目标是实现一个差不多的游戏: 最多也就是"太空魔兽"那种样子.
从这张照片可以看出来游戏团队当时想走的路, 这张照片截取自1996年第二季度的E3游戏展.

<figure>
  <img src="/img/post/tough-times-1-why-crash/Starcraft-orcs-in-space.png"/>
  <figcaption>星际争霸在1996年6月电子娱乐博览会的照片. 没错, 我也不想玩这种东西</figcaption>
</figure>

但是一个更要紧的项目压制了星际争霸,把开发者一个接一个的拉走了: 暗黑破坏神(Diablo)需要额外的帮助.
暗黑破坏神一个角色扮演游戏, 由当时位于加州红木城(Reedwood City)的神鹰工作室(Condor Studios)开发.
神鹰最早是Dave Brevik, Max Schaefer和他兄弟Erich Schaefer组建的公司,当时只有120万美元的预算: 即使是那个年代也是少的可怜的数目.

神鹰团队毫无希望能完成他们想做的游戏,但是他们做的前期开发工作实在是太有趣了.
对于暴雪来说将神鹰收入囊中是合情合理的, 遂收购之,改名北方暴雪(Blizzard North),并开始往这个急需帮助的游戏里投钱投人.

最早是一个星际争霸的程序员Collin Murray和我飞到红木城帮忙, 其他人在暴雪总部尔湾(Irvine)开发战网(battle.net)支持.
包括互联网,局域网,以及UI界面(在公司内叫"胶水屏")来支持角色选择,加入游戏和其他游戏前的准备功能.

随着暗黑破坏神的增长,最终所有在暴雪总部的人: 美工, 程序员, 设计师, 音效, 测试都来干活了,直到压根没人在干星际争霸.
甚至星际争霸的项目领导也开始兼职写暗黑的游戏安装器: 一个我写了一半但是太忙了没空完成的部分.

在暗黑破坏神在1996年底发布之后, 星际争霸的开发才重启. 
所有人都有了机会来重新看看这个游戏的未来, 而且未来并不好.
这个游戏已经逾期了,而且和让人眼前一亮没有半毛钱关系,尤其是和像 _多米诺风暴_(Dominion Storm)这样的项目比起来,后者在六个月前E3展的预演就看起来非常振奋人心了.

暗黑破坏神的巨大成功重设了我们对暴雪的价值观的期望: 星际争霸后来定下了"暴雪出品必属精品"的基调
但是为了证明这个基调我们走过了太多的痛苦.

## 去证明一些东西

每个人都用审慎的目光看着星际争霸.
显然这个而项目需要比先前的工作更加有野心,来重新定义即时战略游戏(RTS)的未来.
而魔兽争霸I和II都是RTS的一种.

在星际争霸重启期间,有超过80(80!!)个RTS游戏在开发.
这是Johnny Wilson, _电子游戏世界(Computer Gaming World)_首席编辑告诉我们的, 后者是当时世界上最大的游戏杂志.
这么多竞争对手中甚至包括西木工作室(Westwood Studios), 这家公司最早发明了现代RTS游戏机制.
我们需要做点真的让人耳目一新的东西出来.

我们并没有处于劣势,魔兽争霸和暗黑破坏神的成功充斥的新闻报道, 我们不至于受玩家和媒体的不待见.
但是在游戏领域你最多只和上一部作品一样好.
我们得做的比上一部作品好得多,而这要求我们承担更多的风险.

## 新面孔

魔兽争霸II只有六个核心程序员和两个支援程序员; 对于规模更大的星际争霸而言这完全不够,所以开发团队新添了一帮年轻且没啥经验的游戏程序员.
他们自己还需要学习怎么写游戏代码,却得不到多少指导.

我们项目的领导层也没有很强的领导力.
我们应该给没什么经验的程序员在项目早期提供指导所以他们可以在游戏发布前学到一些必要知识, 但那时我们尚不知道这件事有多重要.
所以对这帮绝地学徒而言,他们基本是自生自灭.
我们问题的很大一部分就是我们如履薄冰: 每个程序员都在疯狂写代码完成目标,却没有时间做代码审查,审计或者训练.

问题不仅仅是团队里没什么经验的年轻成员,星际争霸代码团队的精英也从没有构架过一个完整的游戏引擎.
Bob Fitch写过好几年的游戏,也有不少很棒的成果,但是他之前的经验都是在游戏端,他和已有的引擎打交道就可以写出魔兽争霸I和II,完全不需要大规模的引擎设计.
尽管他也又破碎国度的领导经验,那个项目毕竟是被取消了,所以完全没法知道他在那边做架构的时候的一些决定是否合理.

整个团队在项目上花了非常多的时间精力,这些闻所未闻的投入牺牲了团队成员的个人健康和家庭生活.
我从来没在那个项目里说每个人都这么拼命三郎.
但是项目中有几个关键的代码决策,我下面会讲的几个,会在整个开发周期里一直萦绕着代码团队,挥之不去.

## 有些事变了

在暗黑破坏神发布前干了几个月,以及之后又有些清理,补丁的几个月之后,我回去帮忙重启星际争霸.
我没打算再来一场Bug盛宴,但是事情就是这么发生了.

我以为我可以轻而易举的融入项目中, 毕竟我对魔兽争霸的代码太了解了: 每个部件的开发我都有参与过.
然而我却有点惊恐的发现引擎的很多部分都已经被扔掉或者部分重写了.

游戏中的单位类正在准备从零开始重写,并且单位调度器被扔掉了.
调度器是我在游戏中创建的一个机制,来确保每个单位都能有时间决定它要做什么.
每个单位都会周期性的询问:"当前动作执行完了,我应该干什么?", "我应该重新寻路去到我要去的地方吗?", "和我现在正在攻击的单位比起来有没有更好的单位可以攻击?", "玩家是不是给我一个新的命令了?", "我死了, 怎么清理我的尸体?", 这类的问题.

即使有风险, 也有很多理由去重写代码; 退一步讲, 现有代码也是有风险的.
(There are good reasons code needs to be rewritten, but excising old code comes with risks as well.)
Joel Spolsky在 _你永远不该做的事, 第一卷(Things You Should Never Do, Part I)_ 里说的最不容置喙(eloquently):

    你得记住, 当你重新开始的时候, 完完全全没有理由相信你会比第一次做的更好.
    首先, 你的工程团队可能和原来的不一样, 所以你并不见得"更有经验".
    事实上, 你只是会犯更多的老错误, 顺便引入第一版里本不存在的问题.

魔兽争霸的引擎花了几个月才编写好, 为了加入星际争霸特有的新的游戏特性现在要重做.
我们新组建的这个团队之后得话很多时间重新学习: 第一版的引擎为什么, 又是怎么编码才变成当时的构架的?

## 游戏引擎架构

我以前用C给微软DOS写过魔兽世界的游戏引擎,用的Watcom编译器.
现在我们转移到Windows了, Bob选择用Visual Studio编译器, 并且用C++重构游戏引擎.
编译器和C++都是合情合理的选择, 只有一个问题: 在那时团队里只有很少的人有C++的经验, 更别提C++的各种坑.

尽管C++很强, 它很容易被误用.
人尽皆知的C++语言的创造者, Bjarne Stroustrup说过: 
"用C很容易打到自己的脚, C++很难; 不过你如果一不小心打到了, 你的整条腿都得废掉."

历史的进程告诉我们程序员总是喜欢用在第一个项目里用上新语言的每一个特性, 所以写星际争霸的时候我们就滥用了类(class)和继承(inheritance).
代码老手看到我们给游戏单位设计的继承链的时候怕是不寒而栗:

    CUnit < CDoodad < CFlingy < CThingy

`CThingy` 是精灵图(sprites), 他会在地图的任何地方出现, 但是不会移动没什么行为.
`CFlingys` 则是创造粒子(particles)用的, 当游戏里什么东西炸了的时候会有一些粒子随机的四散开来.
`CDoodad`... 我寻思我们14年前当时是这么命名的.
这个类不能实例化, 只是对继承他的类封装了一些必要的方法.
最后`CUnit` 是最顶上一层. 
每个单位的行为都分散在各种模组里面, 你得对每个类都有深入的理解才能真正的写代码.

除了糟糕透顶的继承关系, `CUnit`类本身也是一坨屎山, 其定义甚至像下面这样横跨了好几个头文件.

```cpp
class CUnit ... {
    #include "header_1.h"
    #include "header_2.h"
    #include "header_3.h"
    #include "header_4.h"
};
```

每个头文件都有好几百行, 最终的类定义只能说是可笑至极.

直到很多年以后"要组合不要继承"的观念才在程序员中流行起来, 不过那些在星际争霸中写过代码的人则用更辛苦的方法亲身体悟到了.

## 只剩两个月就要发布了!

有这么一个混乱的起步, 重启团队要完成开发的压力很大.
在盘根错节的日程安排中却可以发现游戏还有两个月就要发布了.

考虑到游戏单位的数量庞大, 他们的行为更加浩如烟海; 游戏视角从俯视变成了斜视, 绘制工作也非常庞杂; 我们还要一个全新的地图编辑器; 得加上战网来支持在线游戏.
总而言之我们不太相信游戏能在两个月内做完 -- 即使艺术团队, 设计师, 音效师, 平衡组和测试组都如期交付也不行.
开发团队则总处在"还有两个月就要发布了"的压力下忙了14个月.

整个团队都在加班.
Bob那时一周工作80个小时, 然后是82, 88小时.
尽管每个人都加班很夸张, 但是我也不记得有谁像Bob那样努力到近乎自虐.

我在魔兽争霸开的夜车, 以及在暗黑破坏神上几乎007的经验告诉我, 开夜车是完全没必要的.
所有在夜里某个时间点以后提交\[哈!提交这个词太合适了\]的代码都只会在悔恨中和接下来几天的白天重写.

这么加班让人迷幻, 这对做需要大量知识的工作来说很糟糕, 因为我们的工作要很多创造力.
所以我们高处一大堆错误, 不合时宜的特性和漏洞也不奇怪.

无独有偶的是, 我们加的班不是强制的: 只是我们想做出很棒的游戏而已.
但是回头来看这又很蠢, 我们本可以用合理的精力做出更好的产品.

我最引以为傲的成就就是我在两年的时间里领导了4个 _激战(Guild Wars)_ 的战役, 而没有把我的团队带下星际争霸那条道.

## 星际争霸游戏崩溃的最常见原因

尽管我实现了星际争霸的很多特性: 战争迷雾, 视野, 飞行单位路径分离, 语音聊天, 加强AI还有些别的, 我的工作却被吸引到了修bug上.

等下: 语音聊天! 1998年?!? 是: 我1997年12月就全干好了.
我用了一个第三方语音转音素的压缩器, 写了代码把这些音素传过网络, 解压, 然后在其他七个玩家的电脑上播放.

但是我们办公室的每一个声卡都要升级一个驱动才能工作... 前提是这个声卡还得支持同时录音和播放.
所以我非常懊悔的建议团队还是别加这个功能.
要不然的话技术支持的压力会大到我们雇游戏客服的钱都比我们卖游戏来的多.

所以总之啦, 我修复了好多bug.
有些bug是我的, 但是大部分是其他精疲力尽的程序员写的捉摸不透的一些bug.
Brian Fitzgerald是和我合作过的最好的两个程序员之一. 
有一次他审计星际争霸的代码的时候, 惊异于我在整个代码库里做的修改, 给了我我收到过的高的赞扬.
尽管已经过去很久了, 但是至少我还是收了表扬的吗!

考虑到所有我们遇到的困难, 你可能会觉得很难找到一个大范围的漏洞.
但是就我的经验来看星际争霸当时最大的漏洞是用双链表(double linked list).

链表用来追踪有相同行为的单位, 这在引擎里用的很多,
魔兽争霸一局游戏最多只能有800个单位, 星际争霸翻了一倍.
1600这个数字使得用链表把特定类型的单位放在一起加速搜索至关重要.

我依稀记得每个玩家的单位和建筑都有一个链表, 生产建筑也有链表, 航母也有链表记录战斗机的数量, 还有好些其他的东西都用链表.

所以这些链表都是双向链表, 所以添加和删除元素都是O(1)的时间复杂度; 否则的话得走遍整个列表去找要删除的对象, 那就是O(N)的复杂度了.

很不幸的是, 每个链表都是手动维护的: 没有一个共享的函数来链接或者打断链接; 程序员在任何需要的地方手动把链接,断链接写到程序里.
而手动重写要比用一个早已修复过的函数更容易产生bug.

有些链表元素还被链接在了其他链表里面, 所以很有必要知道一个对象到底被链接在那些链表里了才能安全的断链.
还有一些元素甚至被存在了C的union里面来减少内存开销.

所有游戏总是崩溃.
总是.

## 但你为啥要这么做啊?

很不幸的是, 这种链表问题根本不应该存在.
我和Mike O’Brien还有 Jeff Strain一起创建的ArenaNet. 
我们写了一个库叫Storm.DLL, 这个库和暗黑破坏神一起发布的.
除了其他许许多多的特性, Storm包括了一个用模板(template)实现的非常好的双链表.

星际争霸最早开发的时候这个库是用了的.
但是游戏开发早起我们把整个代码都掀了重写了一份链表, 主要是为了让保存游戏的文件更好些.

我来说说保存游戏你就懂了.

## 保存游戏

我在开发魔兽争霸之前玩的很多游戏中保存游戏的功能都很糟糕.

所有玩过Origin家的游戏的人都记得写一个保存游戏的文件要多多多多多久.
我的意思是, 没错他们是在微处理器和机械硬盘上工作.
如果用现在的标准的话大概相当于三轮车对赛车.
但是他们也不应该做的这么糟啊, 所以我决定魔兽争霸一定不能有这种问题.

So Warcraft did some tricks to enable it to write large memory blocks to disk in one chunk instead of meandering through memory writing a bit here and there. 
The entire unit array (600 units times a few hundred bytes per unit) could be written to disk in one chunk. 
And all non-pointer-based global variables could similarly be written in one chunk, as could each of the game-terrain and fog-of-war maps.

But oddly enough, this ability to write the units to disk in one chunk wasn’t essential to the speed of writing save game files, though it did drastically simplify the code. 
But it worked primarily because Warcraft units didn’t contain “pointer” data.

StarCraft units, which as mentioned previously contained scads of pointers in the fields for linked lists, was an entirely different beast. 
It was necessary to fixup all the link pointers (taking special care of unioned pointer fields) so that all 1600 units could be written at once. 
And then unfixup the link pointers to keep playing. 
Yuck.

## 改回去!

So after fixing many, many linked list bugs, I argued vehemently that we should switch back to using Storm’s linked lists, even if that made the save-game code more complicated. 
When I say “argued vehemently”, I should mention that was more or less the only way we knew how to argue at Blizzard — with our youthful brashness and arrogant hubris, there was no argument that wasn’t vehement unless it was what was for lunch that day, which no one much wanted to decide.

我输了那场争论.
Since we were only “two months” from shipping, making changes to the engine for the better was regularly passed over for band-aiding existing but sub-optimal solutions, which led to many months of suffering, so much that it affected my approach to coding (for the better) ever since, which is what I’ll discuss in part two of this article.

## 再加点创可贴: 星际争霸的寻路算法

I wanted to mention one more example of patching over bugs instead of fixing the underlying problem: when StarCraft switched from top-down artwork to isometric artwork, the background tile-graphics rendering engine, which dated back to code I had written in 1993/4, was left unchanged.

Rendering isometric-looking tiles using a square tile engine isn’t hard, though there are difficulties in getting things like map-editors to work properly because laying down one map tile on another requires many “edge fixups” since the map editor is trying to place diagonally-shaped images drawn in square tiles.

While rendering isn’t so bad, isometric path-finding on square tiles was very difficult. 
Instead of large (32×32 pixel) diagonal tiles that were either passable or impassable, the map had to be broken into tiny 8×8 pixel tiles — multiplying the amount of path-searching by a factor of 16 as well as creating difficulties for larger units that couldn’t squeeze down a narrow path.

Had Brian Fitzgerald not been a stellar programmer, the path-finding problem would have prevented the game from launching indefinitely. 
As it was pathing was one of the problems that was only finalized at the end of the project. 
I plan to write more about path-finding in StarCraft because there are lots interesting technical and design bits.

## 第一部分结语

So you’ve heard me whine a bit about how difficult it was to make StarCraft, largely through poor choices made at every level of the company about the game’s direction, technology and design.

We were fortunate to be a foolhardy but valiant crew, and our perspicacity carried the day. 
In the end we buckled down and stopped adding features long enough to ship the game, and players never saw the horror show underneath. 
Perhaps that’s another benefit of compiled languages over scripted ones like JavaScript — end users never see the train wreck!

In part two of this article I’m going to get even more technical and talk about why most programmers get linked lists wrong, then propose an alternative solution that was used successfully for Diablo, battle.net and Guild Wars.

And even if you don’t use linked-lists, the same solutions carry over to more complex data structures like hash tables, B-trees and priority queues. 
Moreover, I believe the underlying ideas generalize well to all programming. 
But let’s not get ahead of ourselves; that’s another article.

Thanks for reading this far, and sorry I haven’t yet discovered how to write concisely.