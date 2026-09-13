# Qt Fixed Shooter

A fixed-shooter arcade game in C++ with Qt — move a ship horizontally along the
bottom of the screen, shoot descending enemies, and survive as the pace climbs.

Built on Qt's Graphics View framework rather than a game library, which makes it
a useful example of how a general-purpose 2D scene graph maps onto a real-time
game loop.

## How it works

**Everything on screen is a scene item.** The game is five classes, each
inheriting from Qt's graphics primitives:

| Class | Inherits | Role |
|---|---|---|
| `GamePlay` | `QGraphicsView` | The window and the scene it renders |
| `Actor` | `QObject, QGraphicsPixmapItem` | Player ship, keyboard input, firing |
| `Bullet` | `QObject, QGraphicsPixmapItem` | Projectile, self-destructs off-screen |
| `Enemy` | `QObject, QGraphicsPixmapItem` | Descending target |
| `Score` | `QGraphicsTextItem` | The running total |

The dual inheritance from `QObject` and `QGraphicsPixmapItem` is what makes
this work: `QGraphicsPixmapItem` provides position, rendering and collision
geometry, while `QObject` brings the signals-and-slots machinery that lets a
`QTimer` drive each item independently. Every moving thing owns its own timer
and advances itself, instead of one central loop iterating over everything.
That's the idiomatic Qt shape, and it's quite different from the single
fixed-step loop a game framework would give you.

**Collision uses the scene graph.** Bullets query `collidingItems()` rather
than comparing coordinates by hand — Qt already maintains the spatial index, so
hit detection is a lookup against the same structure that drives rendering.

**Objects clean up after themselves.** A bullet that leaves the top of the
scene removes itself and deletes; one that hits an enemy removes both. Nothing
central tracks live objects, so the item count stays bounded during sustained
fire without a garbage-collection pass.

**Difficulty scales with score.** Each enemy reads the current score when it
spawns and sets its own descent speed from it, so the pace climbs as you win
and already-falling enemies keep the speed they were born with.

**A run ends** when any enemy reaches the bottom of the play area.

## Run it

Needs Qt 5 with the Multimedia module.

```bash
qmake MyGame.pro
make
./MyGame
```

Or open `MyGame.pro` in Qt Creator and build there. Assets are compiled into
the binary through `res.qrc`, so it runs from anywhere once built.

| Action | Keys |
|---|---|
| Move | `←` / `→` |
| Fire | `Space` |

## Stack

C++, Qt 5 (Widgets, Graphics View, Multimedia), qmake.

Sprites and audio from [OpenGameArt](https://opengameart.org/); the `Pixelette`
typeface is bundled for the score display.
