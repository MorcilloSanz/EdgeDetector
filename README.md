# EdgeDetector

A simple inequation in order to detect edges in images like Canny edge detector, Sobel edge detector, Laplacian...

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/demo.png)

## Explanation

As we know that the gradient of the image has bigger values in the edges, we can compare that value with a param in order to consider the current pixel as an edge.

Dividing the amount of color variation between the maximum amount of color variation will return a normalized value

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/filterDefinition.png)

τ is the tolerance param (0 <= τ <= 1), the more smaller τ is, more edges are detected

**∇m = (∇mx, ∇my)** is a vector where **∇mx** is the maximum color variation with respect to x and **∇my** with respect to y. As the min color is 0 and the max color is 255, the maximum color variation is 255 - 0 = 255

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/nablaMax.png)

by simplifying we get:

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/filterInequation.png)

The pixels of the image that satisfy the inequation are considered as edges (white). Those that do not are not edges (black).

>(This is a solution that I invented, for sure better ones exist)