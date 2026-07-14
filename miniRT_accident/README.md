# miniRT

A compact ray tracer for the 42 **miniRT** project. The mandatory renderer
supports ambient and diffuse lighting, hard shadows, cameras, spheres, planes,
and finite capped cylinders.

## Dependency

Place the MiniLibX sources in one of these directories at the repository root:

- `minilibx-linux/` on Linux
- `minilibx_macos/` on macOS

Then build and run:

```sh
make
./miniRT scenes/example.rt
```

Close the window with Escape or the window close button.

## Scene format

The parser accepts the subject's `.rt` elements: `A`, `C`, and `L` exactly
once, followed by any number of `sp`, `pl`, and `cy` objects. Blank lines and
lines beginning with `#` are accepted. Invalid identifiers, field counts,
ranges, numbers, colors, and duplicate singleton elements produce `Error`.
