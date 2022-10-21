# EdgeDetector

A simple equation in order to detect edges in images

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/demo.png)

## Explanation

As we know that the gradient of the image has bigger values in the edges, we can compare that value with a param in order to consider the current pixel as an edge.

Normalizing the gradient will allow us to use a normalized param

**∇m = (∇mx, ∇my)** is a vector where **∇mx** is the maximum color variation with respect to x and **∇my** with respect to y

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/filterDefinition.png)

τ is the tolerance param (0 <= τ <= 1), the more smaller τ is, more edges are detected

Doing some calcs we finally get:

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/filterInequation.png)

The pixels of the image that satisfy the inequation are considered as edges (white). Those that do not are not edges (black).

(This is a solution that I invented, for sure exist better ones)