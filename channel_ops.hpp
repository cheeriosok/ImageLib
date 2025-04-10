#include "utils.hpp"
//
// swap_red_blue: Swap the red and blue color channels of the image
// rotate_rgb: Rotate the color channels (R→G, G→B, B→R cycle)
// replace_color: Replace all pixels of a specified color with another color
// isolate_channel: Extract a single color channel from the image (set other channels to zero)
// split_channels: Split the image into separate images for each color channel
// merge_channels: Combine multiple single-channel images into one multi-channel image
// invert_channel: Invert the values of one color channel (leave other channels unchanged)
// fill_channel: Set all pixels of a given channel to a constant value

#include "utils.hpp"

inline Image invert_colors(const Image& image) {
    if (image.getChannels() < 3) {
        throw std::runtime_error("Image must have at least 3 channels for invert_colors transformation.");
    }

    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();

    Image result(width, height, channels);
    
    const uint8_t* source = image.data();
    uint8_t* destination = result.data();

    const int total_pixels = width * height;

    for (int i = 0; i < total_pixels; i++) {
        int idx = i * channels;
        destination[idx] = 255 - source[idx];
        if (channels >= 2) destination[idx+1] = 255 - source[idx+1];
        if (channels >= 3) destination[idx+2] = 255 - source[idx+2];
        if (channels == 4) destination[idx+3] = 255 - source[idx+3];
    }

    return result;
}
