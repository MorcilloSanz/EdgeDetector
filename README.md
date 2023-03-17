# Edge Detector

A simple inequation in order to detect edges in images like Canny edge detector, Sobel edge detector, Laplacian...

![alt text](https://github.com/MorcilloSanz/EdgeDetector/blob/main/img/demo.png)

## Explanation

>This is a solution that I invented, for sure better ones exist

As we know that the gradient of the image has bigger values in the edges, we can compare that value with a param in order to consider the current pixel as an edge.

$I$ is the input image and the color variation is given by the gradient of $I$:

$$\nabla I = \left( \frac{\partial I}{\partial x}, \frac{\partial I}{\partial y} \right)$$

Dividing the amount of color variation between the maximum amount of color variation will return a normalized value

$$\frac{\left|| \nabla I \right||}{\left|| \nabla _{m} \right||} \geq \tau$$

Where $\tau$ is the tolerance param $0 \leq \tau \leq 1$. The more smaller $\tau$ is, more edges are detected

$\nabla_m = (\nabla_{m_{x}}, \nabla_{m_{y}})$ is a vector where $\nabla_{m_{x}}$ is the maximum color variation with respect to $x$ and $\nabla_{m_{y}}$ with respect to $y$. As the min color is $0$ and the max color is $255$, the maximum color variation is $255 - 0 = 255$
. So $\nabla_m = (255, 255)$

by simplifying we get:

$$\left( \frac{\partial I}{\partial x} \right)^{2} + \left( \frac{\partial I}{\partial y} \right)^{2} \geq \tau^{2} \left( \nabla^{2}_{m_{x}} + \nabla^{2}_{m_{y}} \right)$$

The pixels of the image that satisfy the inequation are considered as edges (white). Those that do not are not edges (black).
