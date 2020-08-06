# Median-Filter
### Median Filter algorithm implementation for colored images using OpenCV

## Algorithm
For each pixel, we traverse his neighbours in radius, passed as a parameter to MedianFilter class. And for each colour channel we accumulate the median value, which will be assigned to current pixel.
 * The increasing of the frame size is reducing the noise, but also the quality becomes worse, and "oil paints" effect appears.

## Examples of the result:

<img src = "https://i.ibb.co/zby68rJ/My-Collages-1.png" width=1000 height=1000 align="middle">
<img src = "https://i.ibb.co/Wcm39yK/My-Collages.png" width=1000 height=1000 align="middle">
