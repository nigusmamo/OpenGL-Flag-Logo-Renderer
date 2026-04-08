# Coordinate Mapping & Vertex Definitions (Final Version)

This document defines the exact X, Y, and Z coordinates used in the source code. We use **Normalized Device Coordinates (NDC)** tailored for a 1000x600 window to maintain high visual realism and 3D depth.

---

## 1. Guyana National Flag Implementation
To ensure the flag looks realistic in a 1000x600 window, the Y-axis range is expanded to maintain the official 3:5 aspect ratio without appearing "thin."

| Layer | Shape | Vertices (X, Y) | Color (RGB) | Z-Depth |
| :--- | :--- | :--- | :--- | :--- |
| **Green** | Quad Strip | (-0.9, 0.9) to (0.9, -0.9) | (0, 158, 73) | 0.001 |
| **White** | Triangle | (-0.9, 0.9), (0.9, 0.0), (-0.9, -0.9) | (255, 255, 255) | 0.002 |
| **Yellow** | Triangle | (-0.9, 0.75), (0.75, 0.0), (-0.9, -0.75) | (252, 209, 22) | 0.003 |
| **Black** | Triangle | (-0.9, 0.9), (-0.1, 0.0), (-0.9, -0.9) | (0, 0, 0) | 0.004 |
| **Red** | Triangle | (-0.9, 0.75), (-0.25, 0.0), (-0.9, -0.75) | (206, 17, 38) | 0.005 |

---

## 2. Geometric Logo (Task #8) - Tapered 3D Version
The logo is rendered as a **Solid Tapered Prism** using Mirroring Transformations (`glScalef`). It features a wide front face and a narrow back face to create an aggressive 3D perspective.

### Base Quadrant (Top-Right):

**A. Wide Front Face (Z = -0.4):**
- Inner Corner: (0.22, 0.22)
- Outer Corner: (0.85, 0.85)

**B. Narrow Back Face (Z = 0.3):**
- Inner Corner: (0.01, 0.01)
- Outer Corner: (0.45, 0.45)

---

## 3. Mathematical Logic & Perspective Corrections
- **Front-Facing Orientation:** The front face is positioned at a negative Z-coordinate (-0.4) while the back is at a positive Z (0.3). This ensures the wide black face is correctly oriented toward the default OpenGL camera position upon launch.
- **Aggressive Tapering:** By setting the front inner gap to 0.22 and the back inner gap to 0.01, we create a high "V-shape" inclination, making the logo appear to expand towards the viewer.
- **Symmetry Strategy:** The 4-way symmetry is achieved by defining the Top-Right quadrant and reflecting it using:
  - `glScalef(1, -1, 1)` (Bottom-Right)
  - `glScalef(-1, -1, 1)` (Bottom-Left)
  - `glScalef(-1, 1, 1)` (Top-Left)
- **Visual Separation:** A 2.0-unit line width is applied to the white outlines on the front face to ensure the blocks remain distinct during 3D rotation.

---
*Mapped by: Muluken Melkie (Math & Logic Specialist)*