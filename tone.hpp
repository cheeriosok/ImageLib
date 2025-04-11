// adjust_brightness: Increase or decrease the overall brightness of the image // DONE - NAIVE
// adjust_contrast: Increase or decrease the difference between light and dark areas // DONE - NAIVE
// gamma_correction: Apply gamma correction to adjust brightness in a non-linear way // DONE - NAIVE
// adjust_exposure: Make the image lighter or darker, simulating camera exposure change // DONE - NAIVE
// adjust_saturation: Increase or decrease the intensity of all colors // DONE - NAIVE
// adjust_hue: Shift all colors by a given offset around the color wheel
// auto_contrast: Automatically stretch image intensities to enhance contrast
// apply_alpha_mask(mask)	Applies an alpha mask (grayscale or binary) to adjust transparency
// extract_alpha()	Extracts the alpha channel as a separate grayscale image
// composite_over(background)	Alpha-blends the image onto another background
// premultiply_alpha()	Converts RGBA to pre-multiplied alpha (for compositing)
// unpremultiply_alpha()	Reverses premultiplied alpha
// alpha_to_mask()	Converts alpha transparency to a binary mask
#include "utils.hpp"

inline Image adjust_brightness(const Image& image, float brightness) {
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    if (channels < 1)
        throw std::runtime_error("Image must have at least one channel");

    Image result(width, height, channels);
    const uint8_t* src = image.data();
    uint8_t* dst = result.data();

    int total_pixels = width*height;

    for (int p = 0; p < total_pixels; p++) {
        for (int c = 0; c < channels; c++) {
            if (c < 3) {
                dst[p * channels + c] = std::clamp(int(src[p * channels + c] * brightness), 0, 255);
            }
        }
    }

    return result;
}

inline Image adjust_contrast(const Image& image, const float contrast_const) {
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    if (channels < 1)
        throw std::runtime_error("Image must have at least one channel");
    
    Image result(width, height, channels);
    const uint8_t* src = image.data();
    uint8_t* dst = result.data();

    int pixel_size = width*height;

    for (int i = 0; i < pixel_size; i++) {
        for (int c = 0; c < channels; c++) {
            if (c < 3) {
                dst[i * channels  + c] = std::clamp(static_cast<int>((float(src[i * channels + c]) - 128.0f) * contrast_const + 128.0f), 0, 255);
            }
        }
    }

    return result;

}

inline Image adjust_gamma(const Image& image, float gamma_const) {
    int width = image.getWidth();
    int height = image.getHeight();
    int channels = image.getChannels();
    
    if (channels < 1)
        throw std::runtime_error("Image must have at least one channel.\n");
    
    Image result(width, height, channels);

    const uint8_t* src = image.data();
    uint8_t* dst = result.data();

    int pixel_count = width * height;

    for (int p = 0; p < pixel_count; p++) {
        for (int c = 0; c < channels; c++) {
            if (c < 3)
                dst[p * channels + c] = std::clamp(int((std::pow((src[p * channels + c] / 255.0), 1.0 / gamma_const))*255.0), 0, 255);
        }
    }

    return result;
}

inline Image adjust_exposure(const Image& image, int exposure_factor) {
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels = image.getChannels();

    if (channels < 1)
        throw std::runtime_error("Image must have at least one channel.\n");

    Image result(width, height, channels);
    const uint8_t* src = image.data();
    uint8_t* dst = result.data();

    int total_pixels = width*height;
    float exposure_multiplier = std::pow(2.0f, exposure_factor);

    for (int p = 0; p < total_pixels; p++) {
        for (int c = 0; c < channels; c++) {
            if (c < 3) {
                dst[p * channels + c] = std::clamp(int(src[p * channels + c] * exposure_multiplier), 0, 255);
            }
        }
    }

    return result;
}

inline Image adjust_saturation(const Image& image, float saturation_const) {
    const int width = image.getWidth();
    const int height = image.getHeight();
    const int channels =  image.getChannels();

    if (channels < 3) 
        throw std::runtime_error("Image must have at least three channels.\n");

    Image result(width, height, channels);

    const uint8_t* src = image.data();
    uint8_t* dst = result.data();

    int pixel_count = width * height;

    for (int p = 0; p < pixel_count; p++) {
        float gray = 0.299*src[p*channels] + 0.587*src[p*channels+1] + 0.114*src[p*channels+2];
        dst[p * channels] = std::clamp(static_cast<int>(gray + (src[p*channels] - gray) * saturation_const), 0, 255);
        dst[p * channels + 1] = std::clamp(static_cast<int>(gray + (src[p*channels + 1] - gray) * saturation_const), 0, 255);
        dst[p * channels + 2] = std::clamp(static_cast<int>(gray + (src[p*channels + 2] - gray) * saturation_const), 0, 255);
        if (channels == 4) dst[p * channels + 3] = src[p * channels + 3];
    }

    return result;
}