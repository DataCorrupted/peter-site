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

但是一个更要紧的项目压制了星际争霸,把开发者一个接一个的拉走了.
暗黑破坏神需要额外的帮助.
暗黑破坏神一个角色扮演游戏, 由当时位于加州红木城(Reedwood City)的神鹰工作室(Condor Studios)开发.
神鹰最早是Dave Brevik, Max Schaefer和他兄弟Erich Schaefer组建的公司,当时只有120万美元的预算: 即使是那个年代也是少的可怜的数目.

神鹰团队毫无希望能完成他们想做的游戏,但是他们做的前期开发工作实在是太有趣了.
对于暴雪来说收购神鹰是合情合理的,遂改名北方暴雪(Blizzard North),开始往这个急需帮助的游戏里投钱投人.

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

我们代码的领导层也不是很强.
我们应该给没什么经验的程序员在项目早期提供指导所以他们可以在游戏发布前学到一些必要知识, 但那时我们尚不知道这件事有多重要.
所以对这帮绝地学徒而言,他们基本是自生自灭.
我们问题的很大一部分就是我们如履薄冰: 每个程序员都在疯狂写代码以完成目标,却没有时间做代码审查,审计或者训练.

And not only were there inexperienced junior members on the team, the leader of the StarCraft programming effort had never architected a shipping game engine. 
Bob Fitch had been programming games for several years with great results but his previous efforts were game ports, where he worked within an existing engine, and feature programming for Warcraft I and II, which didn’t require large-scale engine design. 
And while he had experience as the tech lead for Shattered Nations, that project was canceled, therefore no validation of its architectural decisions was possible.

The team was incredibly invested in the project, and put in unheard of efforts to complete the project while sacrificing personal health and family life. 
I’ve never been on a project where every member worked so fiercely. 
But several key coding decisions in the project, which I’ll detail presently, would haunt the programming team for the remainder of the project.

## 有些事变了

After spending months working to launch Diablo, and further months of cleanup effort and patching afterwards, I returned to help with the reboot of StarCraft. 
I wasn’t looking forward to diving into another bug-fest, but that’s exactly what happened.

I thought it would be easy to jump back into the project because I knew the Warcraft code so well — I’d literally worked on every component. 
I was instead terrified to discover that many components of the engine had been thrown away and partially rewritten.

The game’s unit classes were in the process of being rewritten from scratch, and the unit dispatcher had been thrown out. 
The dispatcher is the mechanism I created to ensure that each game unit gets time to plan what it wants to do. 
Each unit periodically asks: “what should I do now that I finished my current behavior?”, “should I re-evaluate the path to get where I’m going?”, “is there a better unit to attack instead of the one that I’m targeting now?”, “did the user give me a new command?”, “I’m dead, how do I clean up after myself?”, and so forth.

There are good reasons code needs to be rewritten, but excising old code comes with risks as well. 
Joel Spolsky said it most eloquently in Things You Should Never Do, Part I:

It’s important to remember that when you start from scratch there is absolutely no reason to believe that you are going to do a better job than you did the first time. 
First of all, you probably don’t even have the same programming team that worked on version one, so you don’t actually have “more experience”. 
You’re just going to make most of the old mistakes again, and introduce some new problems that weren’t in the original version.

The Warcraft engine had taken months of programming effort to get right, and while it needed rework for new gameplay features, a fresh programming team was now going to spend a great deal of time relearning lessons about how and why the engine was architected the way it was in the first place.

## 游戏引擎架构

我以前用C给微软DOS写过魔兽世界的游戏引擎,用的Watcom编译器.
With the switch to releasing on Microsoft Windows, Bob chose to use the Visual Studio compiler and re-architected the game engine in C++. 
Both were reasonable choices but for the fact that — at that point — few developers on the team had experience with the language and more especially with its many pitfalls.

Though C++ has strengths it is easy to misuse. 
As Bjarne Stroustrup, the language’s creator, so famously said: “C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do it blows your whole leg off.”

History tells us that programmers feel compelled to try every feature of their new language during the first project, and so it was with class inheritance in StarCraft. 
Experienced programmers will shudder when seeing the inheritance chain that was designed for the game’s units:

    CUnit < CDoodad < CFlingy < CThingy

CThingy objects were sprites that could appear anywhere on the game map, but didn’t move or have behaviors, while CFlingys were used for creating particles; when an explosion occurred several of them would spin off in random directions. 
CDoodad — after 14 years I think this is the class name — was an uninstantiated class that nevertheless had important behaviors required for proper functioning of derived classes. 
And CUnit was layered on top of that. 
The behavior of units was scattered all throughout these various modules, and it required an understanding of each class to be able to accomplish anything.

And beyond the horror of the class hierarchy, the CUnit class itself was an unholy mess defined across multiple header files:

```cpp
class CUnit ... {
    #include "header_1.h"
    #include "header_2.h"
    #include "header_3.h"
    #include "header_4.h"
};
```

Each of those headers was several hundred lines, leading to an overall class definition that could at best be called amusing.

It wasn’t until many years later that the mantra “favor composition over inheritance” gained credence among programmer-kind, but those who worked on StarCraft learned the hard way much earlier.

## 只剩两个月就要发布了!

With its troubled early history, after the reboot the development team was pressured to finish up, and so schedules were bandied about that showed the game could be launched in two months.

Given the number of game units and behaviors that needed to be added, the changes necessary to switch from top-down to isometric artwork, a completely new map editor, and the addition of Internet play over battle.net, it was inconceivable that the game actually could ship in that time, even assuming that the art team, designers, sound engineers, game-balancers and testers could finish their end of the bargain. 
But the programming team continually worked towards shipping in only two months for the next fourteen months!

The entire team worked long hours, with Bob working stretches of 40 hours, 42 hours, even 48 hours programming. 
As I recall no one else attempted these sorts of masochistic endeavors, though everyone was putting in massive, ridiculous hours.

My experiences developing Warcraft, with frequent all-nighters coding, and later Diablo, where I coded fourteen-plus hour days seven days a week for weeks at a time, suffered me to learn that there wasn’t any point in all-nighters. 
Any code submissions [ha! what an appropriate word] written after a certain point in the evening would only be regretted and rewritten in the clear light of following days.

Working these long hours made people groggy, and that’s bad when trying to accomplish knowledge-based tasks requiring an excess of creativity, so there should have been no surprises about the number of mistakes, misfeatures and outright bugs.

Incidentally, these sorts of crazy hours weren’t mandated — it was just the kind of stuff we did because we wanted to make great games. 
In retrospect it was foolish — we could have done better work with more reasonable efforts.

One of my proudest accomplishments was to ship four Guild Wars campaigns in a two-year window without leading the development team down that dark path.

## 星际争霸游戏崩溃的最常见原因

While I implemented some important features in StarCraft, including fog-of-war, line-of-sight, flying unit pathing-repulsion, voice-chat, AI reinforcement points, and others, my primary job gravitated to fixing bugs.

等下: 语音聊天! 1998年?!? 是: 我1997年12月就全干好了.
I used a 3rd-party voice-to-phoneme compressor, and wrote the code to send the phonemes across the network, decompress them, and then play them back on the other seven players’ computers.

But every single sound-card in our offices required a driver upgrade to make it work, if the sound card was even capable of full-duplex sound (simultaneous recording and playback of sounds), so I regretfully made the recommendation to scrap the idea. 
The tech-support burden would have been so high that we would have spent more money on game support than we would have made selling the game.

So anyway I fixed lots of bugs. 
Some of my own, sure, but mostly the elusive bugs written by other tired programmers. 
One of the best compliments I’ve received came just a few months ago, when Brian Fitzgerald, one of two best programmers I’ve had occasion to work with, mentioned a code-review of StarCraft; they were blown away by how many changes and fixes I had made over the entire code-base. 
At least I got some credit for the effort, if only well after the fact!

Given all the issues working against the team, you might think it was hard to identify a single large source of bugs, but based on my experiences the biggest problems in StarCraft related to the use of doubly-linked linked lists.

Linked lists were used extensively in the engine to track units with shared behavior. 
With twice the number of units of its predecessor — StarCraft had a maximum of 1600, up from 800 in Warcraft 2 — it became essential to optimize the search for units of specific types by keeping them linked together in lists.

Recalling from distant memory, there were lists for each player’s units and buildings, lists for each player’s “power-generating” buildings, a list for each Carrier’s fighter drones, and many many others.

All of these lists were doubly-linked to make it possible to add and remove elements from the list in constant time — O(1) — without the necessity to traverse the list looking for the element to remove — O(N).

Unfortunately, each list was “hand-maintained” — there were no shared functions to link and unlink elements from these lists; programmers just manually inlined the link and unlink behavior anywhere it was required. 
And hand-rolled code is far more error-prone than simply using a routine that’s already been debugged.

Some of the link fields were shared among several lists, so it was necessary to know exactly which list an object was linked into in order to safely unlink. 
And some link fields were even stored in C unions with other data types to keep memory utilization to a minimum.

So the game would blow up all the time. 
All the time.

## 但你为啥要这么做啊?

Tragically, there was no need for these linked-list problems to exist. 
Mike O’Brien, who, along with Jeff Strain, cofounded ArenaNet with me, wrote a library called Storm.DLL, which shipped with Diablo. 
Among its many features, storm contained an excellent implementation of doubly-linked lists using templates in C++.

During the initial development of StarCraft, that library was used. 
But early in the development the team ripped out the code and hand-rolled the linked-lists, specifically to make writing save-game files easier.

我来说说保存游戏你就懂了.

## 保存游戏

我在开发魔兽争霸之前玩的很多游戏中保存游戏的功能都很糟糕.
Gamers who played any game created by Origin will remember how looooooong it took to write save-game files. 
I mean sure, they were written by slow microprocessors onto hard-drives that — by today’s standards — are as different as tricycles and race cars. 
But there was no reason for them to suck, and I was determined that Warcraft wouldn’t have those problems.

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