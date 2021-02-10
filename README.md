# 8DirJoystick

This arduino library enables you to read joysticks to get their coordinates or the direction the joystick is pointing at.

## Usage

- First create a DirJoystick object:

```c++
DirJoystick joystick = DirJoystick( int xAxis, int yAxis, short deadZonePct = 5)
```

- Then you can either call `joystick.readJoystickDirection()` which returns one of the following values:

DirE - DirNE - DirN - DirNW - DirW - DirSW - DirS - DirSE

- Or if you prefer to get the coordinates:

```c++
joystick.readJoystick()
```
