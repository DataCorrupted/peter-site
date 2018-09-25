+++
title = "How to boot with Thunderbolt 3 support(On TP)"

date = 2018-09-25T22:58:00
lastmod = 2018-09-25T22:58:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["Linux", "Geek", "HowTo"]
summary = "Some maneuvers to boot with Thunderbolt 3 support"

+++

Starting from ThinkPad T470 there is a [Thunderbolt](https://en.wikipedia.org/wiki/Thunderbolt_(interface)) 3 port to the left of the machine.
I didn't had the chance to use it until I got a Thunderbolt Adapter from Bytedance to help me use my MacBook.
(Of course I throw my MacBook away, how stupid it is to leave only a Thunderbolt and ask user to buy an extra adapter? That doesn't sound convenient at all!)
The adapter came with a HDMI port, USB3.0 Type A and a USB3.0 Type C.
With the adapter, I connected my Dell Screen to it.
What many people don't know is that Dell Screens normally comes with a USB Hub inside. 
So I connected the Hub to the adapter too.
Then the problem came: When booting, my screen works once grub starts up, yet my keyboard won't, which is connected to screen and then connects to adapter and to my computer through TB3.

After some digging, here is the fix.

And something you should know:

## Reference
[https://en.wikipedia.org/wiki/Thunderbolt_(interface)](https://en.wikipedia.org/wiki/Thunderbolt_(interface))
