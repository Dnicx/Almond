NOTE:

We're not adding premake to GLFW, Instead we're building it from source as is.

GLFW is already added as submodule, all that left is to build library.

For building on Windows with Visual Studio:
1. Open GLFW directory with visual studio.
2. In solution explorer, switch to cmake target view ( via right click ).
3. Build glfw ( static library ) from right click menu.
