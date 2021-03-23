# canvas-drawer

Implements a simple drawing api

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake -G "Visual Studio 16 2019" ..
canvas-drawer/build $ start Draw-2D.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
canvas-drawer/build $ ../bin/Debug/draw_test
canvas-drawer/build $ ../bin/Debug/draw_art
```

*macOS*

Open terminal to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake ..
canvas-drawer/build $ make
```

To run each program from build, you would type

```
canvas-drawer/build $ ../bin/draw_test
canvas-drawer/build $ ../bin/draw_art
```

## Supported primitives

1. Lines
2. Triangles
3. Circle
4. Rectangles
5. Star
6. Curve (these are modification for circle like roses)
7. Point

## Filters Implemented
1. drwaing different shapes like rectangle, circle, star, and flowers
2. draw lines with width
3. Point Primitive
4. Support Filled and outlined Shapes 
 ## Future implementation
1. Support different blend modes, such as add, difference, and multiply
2. make it easy for users to specify gradients
3. Support alpha blending

## Results

TODO: Show artworks using your class
1. Lines draw (Simple)


![diagonal-line-2](https://user-images.githubusercontent.com/60520906/112092940-ffd8e500-8b6e-11eb-9259-afdb4383ce1c.png)
![diagonal-line-1](https://user-images.githubusercontent.com/60520906/112092972-0ebf9780-8b6f-11eb-96ff-2170e0ec3ad7.png)
![h-lessthan-w-line-1](https://user-images.githubusercontent.com/60520906/112092979-1121f180-8b6f-11eb-9a14-6b67ec986a0c.png)
![h-lessthan-w-line-2](https://user-images.githubusercontent.com/60520906/112092982-13844b80-8b6f-11eb-853f-e2aac3c089de.png)
![horizontal-line](https://user-images.githubusercontent.com/60520906/112092986-154e0f00-8b6f-11eb-9fd1-af00f20edb85.png)
![vertical-line](https://user-images.githubusercontent.com/60520906/112092990-197a2c80-8b6f-11eb-8a16-b34339f795c6.png)
![w-lessthan-h-line-1](https://user-images.githubusercontent.com/60520906/112092995-1b43f000-8b6f-11eb-9c08-97655938ffdf.png)
![w-lessthan-h-line-2](https://user-images.githubusercontent.com/60520906/112092998-1da64a00-8b6f-11eb-881e-a5b6e77f51ce.png)

2. Lines with Interpolation

![line-color-interpolation](https://user-images.githubusercontent.com/60520906/112093081-36aefb00-8b6f-11eb-8f3e-527b5303fee2.png)
![with-interpolation-lessthan-h-line-1](https://user-images.githubusercontent.com/60520906/112093442-c48ae600-8b6f-11eb-8d78-bea38a40ef0a.png)
![with-interpolation-w-lessthan-h-line-2](https://user-images.githubusercontent.com/60520906/112093447-c785d680-8b6f-11eb-833a-2119e92bde73.png)
![with-interpolation-h-lessthan-w-line-1](https://user-images.githubusercontent.com/60520906/112093455-cc4a8a80-8b6f-11eb-8f18-4bd689586629.png)
![with-interpolation-h-lessthan-w-line-2](https://user-images.githubusercontent.com/60520906/112093466-d3719880-8b6f-11eb-8a7c-2404c117ac1a.png)
![with-interpolation-w-lessthan-h-line-2](https://user-images.githubusercontent.com/60520906/112093471-d4a2c580-8b6f-11eb-957b-4e610b7fe345.png)
![vertical-with-interpolation-line](https://user-images.githubusercontent.com/60520906/112093476-d5d3f280-8b6f-11eb-88f4-82d602441ebf.png)


3. Lines with Width

![vertical-with-width-line](https://user-images.githubusercontent.com/60520906/112093258-7aa20000-8b6f-11eb-84e6-4b00edb19ac5.png)
![with-width-diagonal-line-2](https://user-images.githubusercontent.com/60520906/112093280-82fa3b00-8b6f-11eb-8d76-4f39f063c1f5.png)
![with-width-h-lessthan-w-line-1](https://user-images.githubusercontent.com/60520906/112093282-842b6800-8b6f-11eb-9a14-d85e3a77b2a6.png)
![with-width-h-lessthan-w-line-2](https://user-images.githubusercontent.com/60520906/112093284-855c9500-8b6f-11eb-9681-3ce9611a39e3.png)
![with-width-horizontal-line](https://user-images.githubusercontent.com/60520906/112093289-87beef00-8b6f-11eb-9d3d-4ba20a8abcd4.png)
![with-width-w-lessthan-h-line-2](https://user-images.githubusercontent.com/60520906/112093292-88f01c00-8b6f-11eb-9a7b-bcdc261870e4.png)

3. Triangles with interpolation

![triangle-interpolation two sideways](https://user-images.githubusercontent.com/60520906/112093723-58f54880-8b70-11eb-9974-82c5a69336f2.png)
![triangle](https://user-images.githubusercontent.com/60520906/112093497-e2584b00-8b6f-11eb-9b57-bae69609f9ba.png)

4.Triangle Outlined

![outlined](https://user-images.githubusercontent.com/60520906/112093793-762a1700-8b70-11eb-8621-74feead53329.png)
![unfilled-triangle](https://user-images.githubusercontent.com/60520906/112093752-64487400-8b70-11eb-8f8c-932eb0fec4d8.png)

5. Rectangle Filled

![rectangle-color-interpolation](https://user-images.githubusercontent.com/60520906/112093905-9d80e400-8b70-11eb-8f4a-6b8c6d786623.png)
![rectangle-filled-interpolation](https://user-images.githubusercontent.com/60520906/112093888-98bc3000-8b70-11eb-8c4f-4f57ccd96979.png)

6. Rectangle Outlined

![rectangle-unfilled-interpolation](https://user-images.githubusercontent.com/60520906/112093919-a671b580-8b70-11eb-841b-c7a0d634dfcf.png)

7. Circle Filled

![circle-color-interpolation](https://user-images.githubusercontent.com/60520906/112093966-bb4e4900-8b70-11eb-8f28-d26e16b6dc32.png)

8. Circle Outlined

![circle-unfilled](https://user-images.githubusercontent.com/60520906/112093989-c86b3800-8b70-11eb-90c1-8a366b58fbce.png)

9. Star Filled

![star-draw](https://user-images.githubusercontent.com/60520906/112094010-d15c0980-8b70-11eb-9d28-4f793783f45f.png)

10. Star UnFilled

![unfilled-star-draw](https://user-images.githubusercontent.com/60520906/112094021-d8831780-8b70-11eb-8de4-6b55d9160031.png)

11. curves filled

![curves-color-interpolation](https://user-images.githubusercontent.com/60520906/112094060-ef296e80-8b70-11eb-95ce-717304797dd1.png)
![curves-k-2 7-interpolation](https://user-images.githubusercontent.com/60520906/112094064-f0f33200-8b70-11eb-8118-04ca3781fd4b.png)

12. Curve Outlined

![curves-unfilled-interpolation](https://user-images.githubusercontent.com/60520906/112094072-f781a980-8b70-11eb-815e-a33833ee6873.png)

13. Point Primitive

![points-draw](https://user-images.githubusercontent.com/60520906/112094085-ffd9e480-8b70-11eb-8e26-b2bc1a2936c3.png)

##Unique Images
1. I first drew Interpolated vertical lines. Then, on top of that, I drew a circle in the middle , on top of circle I drew a outlined star, and outlined it with rectangles of varying widths.

![drawing-rectangles-circles](https://user-images.githubusercontent.com/60520906/112094205-3879be00-8b71-11eb-95c9-fd32164e1078.png)

2.For this one, I created four isosceles tringles with their tip sharing one point. Then I randomly created many copies of the same image.

![spiral-using-triangles](https://user-images.githubusercontent.com/60520906/112094311-6f4fd400-8b71-11eb-9945-2477a3cd1715.png)

3. Finally, For this last image, I created both horizontal and vertical interpolated lines. On top of this background I drew a curve in the middle of a square. Then I created multiple copies of the same image.

![mixFilters](https://user-images.githubusercontent.com/60520906/112094439-a3c39000-8b71-11eb-9084-64a99ad09ebf.png)







