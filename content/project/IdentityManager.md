+++

# Date this page was created.
date = 2018-09-14T00:00:00Z

# Project title.
title = "Identity Manager"

# Project summary to display on homepage.
summary = "A tool developed in Android to help manage NDN identity"

# Optional image to display on homepage (relative to `static/img/` folder).
image_preview = "project/IdentityManager/IdentityManager.png"

# Tags: can be used for filtering projects.
# Example: `tags = ["machine-learning", "deep-learning"]`
tags = ["networking", "Android", "selected"]

# Optional external URL for project (replaces project detail page).
# external_link = "https://github.com/DataCorrupted/GamBody_src"

# Does the project detail page use math formatting?
math = false

+++

### Why Named Data Networking(NDN)?

Before we jump into jargons, let's ask ourselves a simple question: How do you Google?
(For Chinese users, unfortunately, you don't Google at all... Then how do you Bing?)
You type in Google.com and the browser magically jumps out the page.
But is that all?
The truth is, in current protocol TCP/IP, every Internet packet needs a source and a destination.
You may think this is trivial, you do that everyday when you mail a UPS.
But src and dest address is not trivial in Networks when the address is composed of 32 bits.
Our solution?
DNS server. 
You simply ask this server: Where is Google and you get the answer.
Then what is the source?
We used to manually configure it, but now we have DHCP to take care of that.

You can easily see the security problems behind this.
Is DHCP safe? Can it be possible that someone just pretend to be your router and gave you a fake address and reads all your communication?
Is DNS safe? Can someone give you the wrong one and lead you to Baidu.com instead of Google.com?
Well if you are a China Telecom's user you run into this on monthly basis because they hijack your DNS server to insert their ad.
And is your communication safe? 
Till now we still have web pages communicate when HTTP where all the data is not encrypted, meaning everyone can read it.

But do you care about that?
No, all you need is data. 
The simple search results from Google.
Then why bother with connection since TCP/IP is connection based?
What we really need is a network architecture that is data based.
And that's when you need NDN.

### Introduction to NDN

NDN is a new networking architecture putting data as first priority passenger.
Unlike TCP/IP, there is no _address_ in this architecture.
In NDN, every piece of data is named. 
To fetch a data, the consumer may simply express an _**Interest**_ packet with the name of that data and certain parameters.
_**Data**_ packet, on the other hand, starts with the name of the data, followed by the data and the producers signature. 
The signature allows all the consumer to verify that the data is secured and unchanged.

<figure>
  <img src="/img/project/IdentityManager/packet.png" alt="team"/>
  <figcaption>The format of Interest and Data packets</figcaption>
</figure>

For each and every router in this network, the following protocol has to be preformed to guarantee the deliver of the packets.

<figure>
  <img src="/img/project/IdentityManager/routers.png" alt="team"/>
  <figcaption>The behavior of a router when Interest/Data packet is received</figcaption>
</figure>

### OpenmHealth & NDNFit

OpenmHealth is a set of applications that initially proposed to do health data tracking.
It consists of several units including Data Storage Unit(DSU), Data Processing Unit(DPU), Data 
<figure>
  <img src="/img/project/IdentityManager/IdentityManager.png" alt="team"/>
  <figcaption>The architecture of NDNFit</figcaption>
</figure>

### IdentityManager

### NDNCERT

### Android
