# Coordinate Mapping & Vertex Definitions (Final Version)

This document defines the exact X, Y coordinates used in the source code. We use Normalized Device Coordinates (NDC) tailored for a 1000x600 window to maintain visual realism.

---

## 1. Guyana National Flag Implementation
To ensure the flag looks realistic in a 1000x600 window, the Y-axis has been enhanced to prevent a "thin" appearance.

| Layer | Shape | Vertices (X, Y) | Color (RGB) |
| :--- | :--- | :--- | :--- |
| Background | Rectangle | (-0.9, 0.9), (0.9, 0.9), (0.9, -0.9), (-0.9, -0.9) | (0, 158, 73) |
| White Triangle | Triangle | (-0.9, 0.9), (0.9, 0.0), (-0.9, -0.9) | (255, 255, 255) |
| Yellow Triangle | Triangle | (-0.9, 0.75), (0.75, 0.0), (-0.9, -0.75) | (252, 209, 22) |
| Black Triangle | Triangle | (-0.9, 0.9), (-0.1, 0.0), (-0.9, -0.9) | (0, 0, 0) |
| Red Triangle | Triangle | (-0.9, 0.75), (-0.25, 0.0), (-0.9, -0.75) | (206, 17, 38) |

---

## 2. Geometric Logo (Task #8)
The logo is rendered using Mirroring Transformations (glScalef). The base quadrant (Top-Right) uses a center gap of 0.05 for a professional look.

### Base Primitive (Top-Right Quadrant):
- Gap Offset: 0.05
- Front Square: (0.25, 0.25), (0.75, 0.25), (0.75, 0.75), (0.25, 0.75)
- Left Slope: (0.25, 0.25), (0.25, 0.75), (0.05, 0.55), (0.05, 0.05)
- Bottom Slope: (0.25, 0.25), (0.75, 0.25), (0.55, 0.05), (0.05, 0.05)

---

## 3. Mathematical Logic & Corrections
- Aspect Ratio Correction: In a 1000x600 window, NDC units are non-uniform. We adjusted the Y-range to 0.9 and 0.75 (instead of the mathematical 0.6) to achieve a visually accurate and realistic flag thickness.
- Symmetry Strategy: The 4-way symmetry is achieved by defining the Top-Right quadrant and using glScalef(1, -1, 1), glScalef(-1, -1, 1), and glScalef(-1, 1, 1) to reflect the logo across the axes.
- Visual Separation: A 2.0-unit line width is applied to the white outlines to ensure clear separation between the 3D-styled blocks.

---
*Mapped by: Muluken Melkie (Math & Logic Specialist)*
