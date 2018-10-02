+++
title = "How to use Netease Cloud Music on Ubuntu 1804"

date = 2018-09-20T10:12:00
lastmod = 2018-09-20T10:12:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["Ubuntu", "Netease", "Geek", "HowTo"]
summary = "Some fixes on Ubuntu 1804 to start Netease Cloud Music"

[header]
image = "post/netease-on-1804/netease-on-1804.png"

+++

## Ubuntu 1804 is out!

Just updated it to 1804 with all the fancy features.
I was so happy about all the changes, especially GNORM desktop until I found that [netease music](https://music.163.com/) cannot start.
(Yes, there is a desktop version for Ubuntu 1604 and you can download it [here](https://music.163.com/#/download))
After some searching, I found some workout, and here I record them.
Unfortunately, after evaluating I still picked the _"Why it worked" fix_ worked on me.

## ["Why it worked" fix](https://blog.csdn.net/Csdoker/article/details/80462163)

The is the fix I am using.
To be honest, I am not really sure why it works. (Or why it won't work.)
The fix is simple: click the icon to start Netease Music like normal, then click upper right of your desktop(system settings) -> power button(but do not power off, just stay on there). 
And then Netease Window will prompt out :)

## [sudo fix](https://blog.csdn.net/Csdoker/article/details/80462163)

You can start Netease Music using sudo:

```shell
sudo netease-cloud-music
```

There are some similar fixes like this.
For example, you can add your user to _sudoer_ like mentioned [here](https://notes.ijustplay.cn/software/ubuntu-netease-cloud-music.html)
But I would not recommend this fix, it feels nasty.

Another similar one also mentioned in the post above is to always run Netease Cloud Music using sudo by changing startup file, however, that didn't work for me.

## permission fix

The comments in that post did mention that the possible reason for the failure is the permission of _/tmp_. 
That does explain why you can succeed with _sudo_.

Doing so should fix the problem:

```shell
sudo chown -R <user-name> /tmp/*
```

Tempting as this might seems to be, this one **didn't** solve my problem.

## Feature or Bug

Whatever method you try, once NetEase cloud music is started, you can shut it down with Alt+F4.
On Ubuntu 1604, Alt+F4 will not put NetEase to the background but kill it.
However, this time it is killed(or not), there is no process trace in the monitor, nor you can retrieve the UI window anymore, but the music will go on.
The moment you press Alt+F4 is a tricky point. 
If you start NetEase again, another client will be started and you will have a new player!
If you do Ctrl+Alt+F4 and do a _ps_ you will see the "remaining" of your last closed NetEase and the music start the moment you log in!

### Reference

[https://blog.csdn.net/Csdoker/article/details/80462163](https://blog.csdn.net/Csdoker/article/details/80462163)
[https://notes.ijustplay.cn/software/ubuntu-netease-cloud-music.html](https://notes.ijustplay.cn/software/ubuntu-netease-cloud-music.html)