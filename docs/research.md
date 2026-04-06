# Research: Guyana Flag & Logo Geometric Analysis

This document outlines the technical specifications and cultural significance of the assigned tasks to ensure high-fidelity rendering.

## 1. The National Flag of Guyana (The Golden Arrowhead)
The colors are based on the official Vexillological standards (Pantone Matching System).

| Element | Color | RGB (Decimal) | Significance |
| :--- | :--- | :--- | :--- |
| **Background** | Green | (0, 158, 73) | Represents the vast agricultural lands and the lush tropical forests that cover the majority of Guyana. |
| **Fimbriation** | White | (255, 255, 255) | Symbolizes the many rivers, water potential, and the "Land of Many Waters" heritage. |
| **Main Triangle** | Yellow | (252, 209, 22) | Represents the country's rich mineral wealth and the bright future promised by its natural resources. |
| **Fimbriation** | Black | (0, 0, 0) | Symbolizes the endurance, resilience, and the zeal of the Guyanese people in nation-building. |
| **Small Triangle** | Red | (206, 17, 38) | Represents the dynamic nature of the young nation and the sacrifice required to achieve progress. |

*Source: World Flag Database / Pantone Color Standards.*

## 2. Geometric Logo Analysis (Task #8)
The assigned logo is a symmetrical geometric construction consisting of four 3D-styled prisms meeting at a center point.

### Technical Plan:
- **Color Selection:** **Deep Navy Blue (RGB: 0, 51, 102)**. This color is chosen to reflect a professional "Corporate Identity" suitable for architectural or financial institution logos.
- **Symmetry & Transformations:**
  - The logo is 4-way symmetrical.
  - **Strategy:** Develop one quadrant (one prism) as a base primitive.
  - **Transformation 1 (Rotation):** Apply 90°, 180°, and 270° rotations to duplicate the base part into four quadrants.
  - **Transformation 2 (Translation):** Precisely position each part to maintain the central cross-gap.
  - **Transformation 3 (Scaling):** Ensure the logo fits proportionally alongside the flag.

## 3. Implementation Tools
- **Language:** C++
- **Graphics Library:** OpenGL (GLUT/FreeGLUT)
- **Coordinate System:** Normalized Device Coordinates (NDC)