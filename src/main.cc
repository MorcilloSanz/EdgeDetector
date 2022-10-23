#include <iostream>

#include "edges/EdgeDetector.h"
#include "edges/EdgeDetectorColor.h"

int main() {

    // EDGE-DETECTOR: edge -> white, else -> black
    ImageTools::Image image = ImageTools::loadPNG("test.png");

    // Edges
    double tau1 = 0.06; // 0 <= tau <= 1
    EdgeDetector edgeDetector(image, tau1);
    edgeDetector.applyFilter();

    // Save output
    ImageTools::savePNG(edgeDetector.getOutputImage(), "output.png");

    // EDGE-DETECTOR-COLOR: edge-> r, g, b, else -> original color
    double tau2 = 0.06; // 0 <= tau <= 1
    EdgeDetectorColor edgeDetectorColor(image, tau2);
    edgeDetectorColor.applyFilter(255, 0, 0);    // Border color red

    // Save output
    ImageTools::savePNG(edgeDetectorColor.getOutputImage(), "output1.png");

    return 0;
}