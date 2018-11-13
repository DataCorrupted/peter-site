+++
# Date this page was created.
date = 2018-09-12T10:36:00Z

# Project title.
title = "STAR-ABB"

# Project summary to display on the homepage.
summary = "A joint project did between STAR Lab and ABB Group."

# Optional image to display on homepage (relative to `static/img/` folder).
image_preview = "project/STAR-ABB/STAR-ABB.png"

# Tags: can be used for filtering projects.
# Example: `tags = ["machine-learning", "deep-learning"]`
tags = ["vision", "robotics", "networking", "selected"]

# Optional external URL for project (replaces project detail page).
# external_link = "https://github.com/DataCorrupted/GamBody_src"

# Does the project detail page use math formatting?
math = false

+++

Wheel robots like Husky may provide high mobility, yet it cannot manipulate objects. 
What we have in mind is to combine manipulator and mobile robots and ask them to collaborate. 
One usage for such combination is to ask the robot to patrol the building, with the added manipulator to help it take elevators. 
Another one is in the factory. 
The manipulator no longer needs to be installed on a particular spot but can be moved around freely using the mobile robot.

<figure>
  <img src="/img/project/STAR-ABB/STAR-ABB.png" alt="team"/>
  <figcaption>1st version of our robot, built with Yumi and Husky</figcaption>
</figure>

Thus, with the joint effort with STAR Lab(Now MARS Lab) and ABB Group, we produced this robot as our course project in graduate level course Robotics. 
The first version was build from [Yumi](https://new.abb.com/products/robotics/industrial-robots/yumi) and [Husky](https://www.clearpathrobotics.com/husky-unmanned-ground-vehicle-robot/). 
We would like to point out that the manipulator Yumi provided by ABB is very powerful and user-friendly, it helped us a lot.

Such robotics involves multiple disciplines in Computer Science, Electrical Engineering and even Mechanical Engineering.
For the mobile robot, we have to deal with mapping, navigation and provide computational power. 
For Yumi, we have to adapt its power supply from AC to DC. 
The robots combined are more massive than we expected, that's when we need ME guys to help us to make sure that Yumi is fixed on Husky. 
Finally, two robotics runs on different systems, we hacked Husky to run Ubuntu 1604, yet Yumi has an ABB built OS. 
We used the network to help them communicate.

This project started off as our course project, and we applied the result with ABB's robot. 
It earned us a 9-month internship. 
During my intern, I took care of the mapping and navigation. 
I also wrote a state machine to help manage all the stages in the transaction.

You may see more details on our [project page](https://robotics.shanghaitech.edu.cn/node/204). 
But unfortunately, it's not working now. 
You may also see a demo on [YouTube](https://www.youtube.com/watch?v=QTBZvm4LgKQ)/[bilibili](https://www.bilibili.com/video/av25993612?from=search&seid=14391233130440824408) which shows you the first version of our robot. 
