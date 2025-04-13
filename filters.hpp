// TUESDAY & WEDNESDAY
// grayscale: Convert the image to shades of gray (remove all color)
// median_filter: Reduce noise by replacing each pixel with the median of its neighborhood
// sharpen: Enhance edge contrast to make the image appear clearer or crisper
// unsharp_mask: Sharpen the image by subtracting a blurred copy to boost detail
// edge_detect: Highlight edges by detecting rapid intensity changes in the image
// sobel_filter: Detect edges using the Sobel operator (emphasizes horizontal and vertical edges)
// emboss: Create a raised emboss effect by turning edges into shadows and highlights
// laplacian_filter: Detect edges using the Laplacian operator (finds outlines in all directions)
// bilateral_filter: Smooth the image while preserving edges using an edge-aware blur
// motion_blur: Simulate movement by blurring the image along a specific direction
// sepia: Apply a warm brown tone for an old-fashioned photo appearance
// invert_colors: Invert all the colors to produce a photographic negative effect
// posterize: Reduce the number of color levels to create flat, poster-like regions
// solarize: Partially invert colors above a certain brightness threshold
// tint: Overlay a uniform color tint onto the image, shifting its overall hue
// pixelate: Reduce detail by enlarging pixels, creating a blocky retro effect
// dither: Apply dithering noise to simulate more colors when reducing color depth
// vignette: Darken the corners and edges to draw attention to the center of the image

#include "utils.hpp"    

inline Image to_grayscale(const Image& image) {
    if (image.getChannels() < 3)
        throw std::runtime_error("Image must have at least 3 channels for grayscale conversion");

    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();

    std::vector<uint8_t> new_data(image.data(), image.data() + width * height * channels);
    Image result(width, height, channels, new_data);

    uint8_t* ptr = result.data();
    int total_pixels = width * height;

    for (int i = 0; i < total_pixels; ++i, ptr += channels) {
        uint8_t r = ptr[0];
        uint8_t g = ptr[1];
        uint8_t b = ptr[2];
        uint8_t gray = (r * 77 + g * 150 + b * 29) >> 8;
        ptr[0] = ptr[1] = ptr[2] = gray;
    }

    return result;
}
