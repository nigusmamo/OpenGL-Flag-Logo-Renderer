#  Cross-Platform Testing Report (Windows)

This document verifies that the project is fully functional on the Windows operating system.

## Environment Details
- OS: Windows 11 / Windows 10
- Compiler: MinGW-w64 (g++)
- Library: FreeGLUT / OpenGL

## Test Checklist
- Compilation: Successfully built using the provided Makefile.
- Flag Rendering: Guyana flag displays with correct colors and aspect ratio.
- Logo Rendering: 3D Tapered logo displays correctly with sharp outlines.
-  Bonus Feature (Animation): Anchored sine-wave flag animation runs smoothly at 60 FPS.
- Bonus Feature (3D Interaction): Mouse dragging allows full 360-degree rotation.
-  Input Handling: 'F' and 'L' keys toggle between flag and logo correctly.

## Conclusion
The project is fully compatible with the Windows environment. No missing DLLs or performance issues were observed.