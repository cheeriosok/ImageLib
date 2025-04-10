// blur: Soften the image by averaging each pixel with its neighbors
// gaussian_blur: Apply Gaussian-weighted blurring for a smooth, natural look

// box_blur	Average pixels in a square kernel; simplest and fastest blur
// gaussian_blur	Weighted average using a Gaussian kernel; produces smooth, natural blur
// median_blur	Replaces each pixel with the median in its neighborhood; removes salt-noise
// bilateral_blur	Blur that preserves edges by considering pixel similarity and spatial distance
// motion_blur	Simulates blur caused by movement; directional kernel along X/Y/diagonal
// radial_blur	Blurs pixels outward from a center point; gives a zoom or whirl look
// box_blur_integral	Fast box blur using summed-area table (integral image)
// stack_blur	Approximation of Gaussian blur using multiple box blurs
// anisotropic_blur	Applies more blur in one direction than another (e.g., horizontal smoothing)
// variable_blur	Blur radius varies based on a mask or per-pixel map (depth-of-field effect)
// directional_blur(angle)	Applies blur along an arbitrary angle instead of just X or Y
// selective_blur(mask)	Applies blur only to selected areas of the image using a binary or alpha mask
// depth_blur(depth_map)	Simulates depth-of-field using a depth map to control blur strength
// edge_preserving_blur()	Smooths inside regions but avoids blurring across edges (e.g. bilateral)
// recursive_gaussian_blur()	Optimized separable Gaussian using recursive filters (faster for large radii)
