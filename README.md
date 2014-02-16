sdatic (WIP)
======

Declaring a variable named `name`

```
name: value
name: type
name: type{ val1, val2, valN }
name: type = value
name: [ val1, val2, valN ]
name := { }
name := [ val1, val2, valN ]
name := value
```

Declaring a type named `type`

```
type: { }
type := anotherType
```

Declaring built in types

```
lambda: () return_type @ { ... }
function(): return_type
dynamic_array[]: type
static_array[10]: type
map[key_type]: type
static_map[10][key_type]: type
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

v: vec3{ z:30.0 y:20.0 x:10.0 }

v: vec3
v.{
  x = 10.0
  y = 20.0
  z = 30.0
}

```
