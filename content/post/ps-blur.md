+++
title = "How to PhotoShop a blurred image as backgournd"

date = 2018-09-24T22:12:00
lastmod = 2018-04-20T22:12:00
draft = false

# Authors. Comma separated list, e.g. `["Bob Smith", "David Jones"]`.
authors = ["Peter Rong"]

tags = ["PhotoShop", "Geek", "HowTo"]
summary = "Some simple tricks to do a cool blurred image backgournd"

[header]
image = "post/ps-blur/ps-blur.png"

+++

I didn't came to this ultil I started posting on my personal blog. 
I need images that "happen" to fit in the web page, which is 1200x480px.
But normal image wouldn't have that ratio, you need something to fill in the empty.
Use white can do the job but I don't like it at all.
What I want is blur the image to fill in.
And that's the head image you are seeing now.

To do that, you need a PhotoShop. 
Or if you can do it with something else, please tell me. 
But anyway, I am using PhotoShop CC 2018.
**ShanghaiTech bought a Adobe Suite for everyone, welcome to ShanghaiTech. :)**

## Step 0: Initiate a new Project

I did it with my desired size 1200x480px.
You can change it to anything you want, but it's better decided before hand.
If you can't decide, use a generic size like 1920x1080 and change later.
(Image->Image Size or Alt+Ctrl+I)

<figure>
  <img src="/img/post/ps-blur/0-0.png" alt="team"/>
</figure>

And you would get a canvas like this.
<figure>
  <img src="/img/post/ps-blur/0-1.png" alt="team"/>
</figure>

## Step 1: Remove default background

I am assuming you have (almost) no knowledge in PhotoShop and explicitly stating this.
Notice the lock in the right of layer 1. 
It locks the layer from been deleted.
Now click it to remove the lock, then select the whole canvas by Ctrl+A, delete it.

Then you would get a empty canvas like this:

<figure>
  <img src="/img/post/ps-blur/1.png" alt="team"/>
</figure>

## Step 2: Get the image

Open the image you want in another tab:

<figure>
  <img src="/img/post/ps-blur/2-0.png" alt="team"/>
  <figcaption>Notice in this figure the to-be-edited image is opened in another tab</figcaption>
</figure>

Select them all(Ctrl + A), copy(Ctrl + C).

### First paste
After pasting adjust the height of the image by input 480px in the right box.
Click V or select Move Tool in the upper left to adjust the image to the center of your canvas.
There will be a pink line to guide you when you are close the the center.

<figure>
  <img src="/img/post/ps-blur/2-1.png" alt="team"/>
  <figcaption>In the right box, select the height to be 480px or your canvas' height</figcaption>
</figure>

After finish you can click the eye in the left of the layer to make it invisible. 
This layer is finished and would be of much use to us anymore.

### Second paste
This time adjust the width of the image to the same width as the canvas(1200px).
Again, center it.
<figure>
  <img src="/img/post/ps-blur/2-2.png" alt="team"/>
</figure>

At the time of pasting, a new layer will be created.
Notice that this layer has to be put down and the first paste layer up.
This is a PS detail that the layer in the button will be hidden by the upper layer.

## Step 3: Blur it!
Convert the second layer to _Smart Object_ as the figure below does.
<figure>
  <img src="/img/post/ps-blur/3-0.png" alt="team"/>
</figure>

You don't need to worry about anything else then.
Now, go Filter->Blur-><Anything-you-like>. 
Here, I picked Radial Blur and I got the following window:
<figure>
  <img src="/img/post/ps-blur/3-1.png" alt="team"/>
</figure>
<figure>
  <img src="/img/post/ps-blur/3-2.png" alt="team"/>
  <figcaption>This is the configuration of the head image</figcaption>
</figure>

You can also add multiple blurs to get more interesting effects.
Now re-click the eye of the first layer, Woola, you are done!

In case you want to delete the previous blur effects, do as the following image:
<figure>
  <img src="/img/post/ps-blur/3-3.png" alt="team"/>
</figure>

### Reference

[https://www.photoshopessentials.com/photo-effects/radial-blur-action-effect-photoshop/](https://www.photoshopessentials.com/photo-effects/radial-blur-action-effect-photoshop/)