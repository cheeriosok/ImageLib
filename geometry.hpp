// THURSDAY && FRIDAY
// flip_vertically
// flip_diagonal
// flip_main_diagonal
// flip_anti_diagonal
// rotate_90_clockwise
// rotate_90_counterclockwise
// rotate_180
// rotate image270
// rotate_arbitrary (angle) w/ interpolation
// rotate 90cw and flip horizontally
// rotate 90ccw and flip vertically
//random_rotation
//random_flip_horizontal
//random_flip_vertical
//random_transpose
// resize_bicubic(image, scale)	Resize using bicubic interpolation (e.g., 0.5 = downsample by 2×)
// downsample_bicubic_2x(image)	Resize the image to ½ its original size using bicubic interpolation
// downsample_bicubic_4x(image)	Resize the image to ¼ its original size using bicubic interpolation
// downsample_bicubic_8x(image)	Resize the image to ⅛ of its original size (often used in multi-scale ops)
// resize_bicubic_to(image, width, height)	Resize to an exact resolution with bicubic interpolation
// resize_nearest(image, scale)	Fastest resize, but blocky artifacts
// resize_bilinear(image, scale)	Better than nearest, but can be blurry on edges
// resize_lanczos(image, scale)	High-quality downsampling for photo realism (slower, uses sinc kernel)
// resize_area(image, scale)	Average-pixel-based method, often used for large downsampling in OpenCV

#ifndef imageFX_FLIP_HPP
#define imageFX_FLIP_HPP

#include "utils.hpp"
#include <cstring> // for std::memcpy

inline Image flip_horizontally(const Image& image) {
    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();

    if (channels < 1)
        throw std::runtime_error("Image must have at least 1 channel to flip.");

    const int pixel_size = channels;
    const int row_size = width * pixel_size;

    Image result(width, height, channels);
    const uint8_t* src = image.data();
    uint8_t* dst = result.data();

    for (int row = 0; row < height; ++row) {
        const uint8_t* src_row = src + row * row_size;
        uint8_t* dst_row = dst + row * row_size;

        for (int col = 0; col < width; ++col) {
            int src_idx = col * pixel_size;
            int dst_idx = (width - 1 - col) * pixel_size;

            std::memcpy(dst_row + dst_idx, src_row + src_idx, pixel_size);
        }
    }

    return result;
}

#endif 
