// normalize: Scale pixel intensities to a standard range (e.g. 0–1 or 0–255)
// clamp: Limit pixel values to lie within a specified min and max range
// histogram_equalization: Enhance overall contrast by spreading out intensity distribution
// adaptive_histogram_equalization: Enhance local contrast via histogram equalization in small regions (CLAHE)
// threshold: Convert to a binary black-and-white image based on a global intensity cutoff
// adaptive_threshold: Generate a binary image using a threshold that adapts to local brightness
// erode: Morphologically erode the image (shrink bright regions and remove small spots)
// dilate: Morphologically dilate the image (expand bright regions and fill in small holes)
// erode_dilate: Apply morphological opening (erode then dilate) to remove small objects/noise
// dilate_erode: Apply morphological closing (dilate then erode) to fill small gaps or holes
// flood_fill: Fill a contiguous region with a given color, starting from a seed pixel
