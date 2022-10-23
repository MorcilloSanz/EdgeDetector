#include <iostream>

#include "edges/EdgeDetector.h"
#include "edges/EdgeDetectorColor.h"

int main() {

    // EDGE-DETECTOR: edge -> white, else -> black
    ImageTools::Image image = ImageTools::loadPNG("test.png");

    // Edges
    double tau = 0.045; // 0 <= tau <= 1
    EdgeDetector edgeDetector(image, tau);
    edgeDetector.applyFilter();

    // Save output
    ImageTools::savePNG(edgeDetector.getOutputImage(), "output.png");

    // EDGE-DETECTOR-COLOR: edge-> r, g, b, else -> original color
    EdgeDetectorColor edgeDetectorColor(image, tau);
    edgeDetectorColor.applyFilter(255, 0, 0);    // Border color red

    // Save output
    ImageTools::savePNG(edgeDetectorColor.getOutputImage(), "output1.png");

    return 0;
}