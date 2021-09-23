# miniRT
A basic ray tracer using the CPU, featuring antialiasing via adaptative supersampling and a multithreaded render. The supported primitives are spheres, planes, cylinders, squares, triangles.
# Installation
    git clone https://github.com/LucienKarri/miniRT.git && cd miniRT && make
# Usage
To render scene
    ./miniRT <scene.rt>
To save .bmp file
    ./miniRT <scene.rt> --save
