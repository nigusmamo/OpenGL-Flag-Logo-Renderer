# Project Roadmap: Guyana Flag & Geometric Logo Rendering

This document serves as the strategic development plan for the Computer Graphics Project (Task #8). It outlines the phases of development, technical milestones, and the roadmap toward a high-fidelity OpenGL implementation.

---

## Phase 1: Research, Architecture & Environment Setup
*Focus: Establishing the foundation and official standards.*

- Project Scoping: Identification of Task #8 requirements (Guyana Flag & Geometric Prism Logo).
- Vexillological Research: Mapping official Pantone and RGB standards for the Guyana National Flag.
- Cross-Platform Engineering: Implementation of preprocessor directives (#ifdef __APPLE__) to support both macOS and Windows environments.
- Asset Organization: Centralizing visual references in the assets/ directory.

---

## Phase 2: Core Graphics Implementation
*Focus: Geometric primitives and color accuracy.*

- Vertex Mapping: Calculation of exact coordinates for the 5-layer "Golden Arrowhead" design in Normalized Device Coordinates (NDC).
- Flag Geometry: Rendering of background polygons and overlapping triangles using GL_TRIANGLE_FAN or GL_POLYGON.
- Logo Quadrant Modeling: Development of the base primitive for the geometric logo prism.
- Coordinate Validation: Ensure all primitives maintain proper aspect ratios on different window dimensions.

---

## Phase 3: Transformations & Advanced Features (Bonus)
*Focus: Applying mathematical transformations and creative features.*

- Symmetry Logic: Utilizing glPushMatrix and glPopMatrix to manage the transformation stack.
- Rotational Symmetry: Applying 90°, 180°, and 270° rotations to generate the 4-way symmetrical logo.
- Bonus Milestone (Animation): Implementing a Vertex-based Sine Wave function to simulate dynamic wind effects on the flag.
- Bonus Milestone (Interaction): Enabling real-time 3D rotation of the geometric logo via user input.

---

## Phase 4: Quality Assurance & Final Documentation
*Focus: Testing, code cleanup, and reporting.*

- Cross-Platform Verification: Running build tests on Windows and MacOS.
- Code Refactoring: Ensuring professional naming conventions and comprehensive technical commenting.
- Technical Explanation Report: Drafting a 1–2 page document detailing:
    - Transformation matrices used.
    - Implementation of OpenGL primitives.
    - Challenges solved during development.
- Final Submission: Deployment of the complete repository link.

---
*Created and Maintained by the Development Team (Alemayehu Moges - Strategic Planner)*
