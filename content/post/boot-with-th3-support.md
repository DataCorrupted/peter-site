+++
title = "How to boot with Thunderbolt 3 support"

date = 2018-09-25T22:58:00
lastmod = 2018-09-25T22:58:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["Linux", "Geek", "HowTo"]
summary = "Some maneuvers to boot with Thunderbolt 3 support"

+++

Starting from ThinkPad T470, there is a [Thunderbolt](https://en.wikipedia.org/wiki/Thunderbolt_(interface)) 3 port to the left of the machine.
I didn't have the chance to use it until I got a Thunderbolt Adapter from Bytedance to help me use my MacBook.
(Of course, I throw my MacBook away, how stupid it is to leave only a Thunderbolt and ask the user to buy an extra adapter? That doesn't sound convenient at all!)
The adapter came with an HDMI port, USB3.0 Type A and a USB3.0 Type C.
With the adapter, I connected my Dell Screen to it.
What many people don't know is that Dell Screens usually comes with a USB Hub inside. 
So I connected the Hub to the adapter too.
Then the problem came: When booting, my screen works once grub starts up, yet my keyboard won't, which is connected to screen and then connects to the adapter and to my computer through TB3.

First, something you should know:

Thunderbolt 3 has different security modes to protect your device. 
The modes are:

* none (or legacy): just accept any device plugged in
* user: user needs to authenticate the device
* secure: same as user but with an additional random key to automatically recognize the device the next time you plug in
* dponly: only allow for the DisplayPort functionality, nothing else

TB3 will allow display upon startup, this requires low-security clearance. 
But other devices like keyboard cannot.
Since TB3 directly connects to your PCIe and an attacker can use an external device to interact with your device through TB3 even if your device is locked.
In this case, the external malicious device can be my keyboard, my poor TP has no way to know.
Hence, It is not safe to turn your TB3 to none safety mode. 
And such mode is likely to be removed in the future.

So here is the fix.

Fire up your laptop and go into [BIOS](https://en.wikipedia.org/wiki/BIOS).
I will not talk about how to do that, you figure it out yourself!
For ThinkPad users, go Config -> Thunderbolt(TM) 3.
Here I set Security level to Secure Connection.
In _Support in Pre Boot Environment_ I disabled Thunderbolt(TM) device but leave USB device on so my keyboard can start up.
Regarding _Wake by Thunderbolt(TM)3_, the description is: 
"Enable or disable Wake Feature with Thunderbolt(TM) 3 Port. If you select Enabled, the
battery life during low power state may become shorter." 
I couldn't find anything about this feature but [this post](http://thinkdeploy.blogspot.com/2017/02/new-ThinkPad-bios-settings-for.html) which basically repeats the BIOS description verbatim.
But for the sake of my battery, I disabled it anyway.

## Reference
[https://en.wikipedia.org/wiki/Thunderbolt_(interface)](https://en.wikipedia.org/wiki/Thunderbolt_(interface))

[https://eischmann.wordpress.com/2017/06/29/thunderbolt-security-levels-and-linux-desktop/](https://eischmann.wordpress.com/2017/06/29/thunderbolt-security-levels-and-linux-desktop/)

[https://christian.kellner.me/2017/12/14/introducing-bolt-thunderbolt-3-security-levels-for-gnulinux/](https://christian.kellner.me/2017/12/14/introducing-bolt-thunderbolt-3-security-levels-for-gnulinux/)

[http://thinkdeploy.blogspot.com/2017/02/new-thinkpad-bios-settings-for.html](http://thinkdeploy.blogspot.com/2017/02/new-thinkpad-bios-settings-for.html)