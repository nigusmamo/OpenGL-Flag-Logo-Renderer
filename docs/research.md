# Research: Guyana Flag & Logo Geometric Analysis

This document outlines the technical specifications and cultural significance of the assigned tasks to ensure high-fidelity rendering.

## 1. The National Flag of Guyana (The Golden Arrowhead)
The colors are based on the official Vexillological standards (Pantone Matching System).

| Element | Color | RGB (Decimal) | Significance |
| :--- | :--- | :--- | :--- |
| **Background** | Green | (0, 158, 73) | Represents the vast agricultural lands and the lush tropical forests. |
| **Fimbriation** | White | (255, 255, 255) | Symbolizes the many rivers and the "Land of Many Waters" heritage. |
| **Main Triangle** | Yellow | (252, 209, 22) | Represents the country's rich mineral wealth and bright future. |
| **Fimbriation** | Black | (0, 0, 0) | Symbolizes the endurance and resilience of the Guyanese people. |
| **Small Triangle** | Red | (206, 17, 38) | Represents the dynamic nature of the young nation and sacrifice. |

## 2. Geometric Logo Analysis (Task #8)
The assigned logo is a symmetrical 3D geometric construction consisting of four tapered prisms meeting at a central point.

### Technical Plan:
- **Color Selection:** **Pure Black (RGB: 0, 0, 0)** with Grey Shading. This is chosen to match the high-contrast professional look of the reference image.
- **Symmetry & Transformations:**
  - The logo is 4-way symmetrical.
  - **Strategy:** Develop one **Tapered 3D Quadrant** (Wide Front, Narrow Back) and use mirroring.
  - **Transformation 1 (Mirroring):** Use `glScalef` to reflect the base quadrant across the X and Y axes.
  - **Transformation 2 (Interactive Rotation):** Apply mouse-controlled `glRotatef` to explore the 3D volume.
  - **Transformation 3 (Translation):** Position the camera to ensure the wide front face is shown initially.

## 3. Implementation Tools
- **Language:** C++ 
- **Library:** OpenGL (GLUT)  
- **Coordinate System:** NDC