sdatic (WIP)
======

Some syntax

```
name: value
name: type
name: type{ val1, val2, ... }
name: type = value
name: { ... }
name: [ val1, val2, ... ]
name := { ... }
name := [ val1, val2, ... ]
name := value
```

Example

```
vec3: {
  x, y, z: float32
}

v: vec3{}
v: vec3{10.0, 20.0, 30.0}
v: vec3

abc := { a = 10.0, b = 20.0, c = 30.0: float32 }

v: vec3{abc}

```
