+++
title = "How to Pair your Bluetooth device when using Dual-boot."

date = 2018-11-05T10:58:00
lastmod = 2018-12-15T14:48:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["Linux", "Geek", "HowTo", "Windows", "Dual-boot"]
summary = "When you are using dual boot, Bluetooth seems not pairing all the time. Here's a fix."

+++

I had a Bluetooth device, Sony WI-C400.
I am happy with it until I wanted to pair it with my laptop, twice.

The funny question here is, why I would pair it twice? 
Well, if you have dual boot, you have to. 
I paired it with my Windows10 once, and then Ubuntu1804.
The problem is, every time I pair it with one system, the device will refuse to connect with the other.
Then I would start searching mode and re-pair with the other system, and then the original system won't connect.
Vice versa.

So I have to look it up. Here are the cause and the fix.

## LD; DR(Too long, Didn't read)
1. The device recognizes each other by MAC.
2. Bluetooth connection has a key to guarantee safety.
3. Bluetooth got confused between systems since they have the same MAC but different key.

## ELI5(Explain it Like I am a 5-year-old)
**Bluetooth**: Device "Laptop"(MAC address), I am "Bluetooth"(MAC address), I want to pair. (paring)  
**Laptop(Running Windows)**: Ok, "Windows" is your password, next time use this password and I will connect.  
(Windows record this device MAC address and password pair: "Bluetooth"-"Windows")  
**Bluetooth**: Ok.   

// Sometime later  
**Bluetooth**: Device "Laptop", I am "Bluetooth", I want to connect, the password is "Windows".    
**Laptop(Running Windows)**: Ok.    

// Sometime later  
**Bluetooth**: Device "Laptop", I am "Bluetooth", I want to connect, the password is "Windows"   
**Laptop(Running Ubuntu)**: What? I don't have any record on you. I refuse to connect.  
**Bluetooth**: What?  
// Re-pair  
**Bluetooth**: Device "Laptop"(MAC address), I am "Bluetooth"(MAC address), I want to pair. (paring)    
**Laptop(Running Windows)**: Ok, "Ubuntu" is your password, next time use this password, and I will connect.  
(Ubuntu record this device MAC address and password pair: "Bluetooth"-"Ubuntu")   

// Sometime later   
**Bluetooth**: Device "Laptop", I am "Bluetooth", I want to connect, the password is "Ubuntu"     
**Laptop(Running Windows)**: I know you, but your password is incorrect. I refuse to connect.   
**Bluetooth**: Device "Laptop", I am "Bluetooth", I want to connect, I repeat, the password is "Ubuntu"     
**Laptop(Running Windows)**: Your password is incorrect. I refuse to connect.     
......

## Real Cause

I will save myself some trouble by citing the top answer from [here](https://unix.stackexchange.com/questions/255509/bluetooth-pairing-on-dual-boot-of-windows-linux-mint-ubuntu-stop-having-to-p).

_Basically, when you pair your device, your Bluetooth service generates a unique set of pairing keys. 
First, your computer stores the Bluetooth device's mac address and pairing key. 
Second, your Bluetooth device stores your computer's mac address and the matching key. 
This usually works fine, but the mac address for your Bluetooth port will be the same on both Linux and Windows (it is set on the hardware level). 
However, when you re-pair the device in Windows or Linux, it generates a new key. 
That key overwrites the previously stored key on the Bluetooth device. Windows overwrites the Linux key and vice versa._

## Fix

You can fix it from Windows or Ubuntu end. 
The core idea is to change either system's record, set the password to the one issued by the other system.
Once done, two systems share the same password, whoever issued it.
This way, your device can connect to either system freely.

You may refer to the post [here](https://unix.stackexchange.com/questions/255509/bluetooth-pairing-on-dual-boot-of-windows-linux-mint-ubuntu-stop-having-to-p) for a fix in Ubuntu.
I didn't test any fix on Windows as I am more familiar with Ubuntu.

## Reference
[Bluetooth](https://en.wikipedia.org/wiki/Bluetooth)  
[Bluetooth Pairing on Dual boot of Windows & Linux Mint/Ubuntu - Stop having to Pair Devices](https://unix.stackexchange.com/questions/255509/bluetooth-pairing-on-dual-boot-of-windows-linux-mint-ubuntu-stop-having-to-p)  
[How can I avoid having to pair my bluetooth mouse all the time?](https://askubuntu.com/questions/253949/how-can-i-avoid-having-to-pair-my-bluetooth-mouse-all-the-time)  
[Finding Bluetooth link key in Windows 7, to double pair a device on dualboot computer](https://superuser.com/questions/229930/finding-bluetooth-link-key-in-windows-7-to-double-pair-a-device-on-dualboot-com)  