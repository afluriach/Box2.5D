
# Box2.5D

This is a fork of the Box2D project. It includes a number of changes to add features & functionality that is/was available in Chipmunk. As the name implies, it supports 2.5D via layers, similar to the functionality available in Chipmunk 6.

## Features

- b2Filter contains layers, allowing for 2.5D.
- Uses doubles (float64), and double-version of all math functions.
- b2RayCastCallback, b2QueryCallback are now std::function instead of a functor interface class.
- All queries now take a b2Filter as an argument. This reduces unnecessary function pointer (previously vptr) invoke for objects that aren't of the right type, and also type filtering is checked before computing narrow-phase collision.
- Generates collision normals for circle-circle collisions (basically, just involves a vector normalization, as b2CollideCircles already computes a displacement vector).


- ShapeQuery - similar to Chipmunk, any b2Shape can be used for a query. It takes a b2Transform representing the position & angle of the shape, plus of course the b2Filter.
- PointQuery - based on QueryAABB, except it uses TestPoint to ensure actual narrow-phase collision. 

- Evaluate collision manifolds for sensor objects. This means you can get a collision normal for non-dynamic collisions.
- Collision detection / callback for static-kinematic collisions: since they both have undefined mass, it is basically the same idea as a sensor collision. 
- Collision detection / callback for static-static, if at least one fixture is sensor type.

b2Filter for queries serves a dual purpose. If the filter provided to the query has a type (category or type is non-zero), the filter is interpreted as though it is the type of the virtual query object, and what types does that collide with. If the filter has no identity, the collision mask is simply the set of types that the query will collide with.

note: My changes were originally made from v2.3.1, but were ported to the latest. Also, a patch.diff is provided.

For more details on these changes, check out this blog post:

<https://afluriach.wordpress.com/2019/07/17/box2-5d/>

## License

Box2D is developed by Erin Catto, and has the [zlib license](http://en.wikipedia.org/wiki/Zlib_License). While the zlib license does not require acknowledgement, we encourage you to give credit to Box2D in your product.
