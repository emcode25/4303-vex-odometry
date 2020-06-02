Vex Odometry -- VODOM

REQUIREMENTS:
-Windows 10 PC (MacOS is untested but should work)
-VEXcode V5 Text v1.0.4

1. Add include files here:
[VEX Robotics directory]\VEXcode V5 Text\sdk\vexv5\include;
2. Add "libvodom.a" file here:
[VEX Robotics directory]\VEXcode V5 Text\sdk\vexv5\gcc\libs;


After you create a project, you will need to copy the "vex"
folder to your project to compile correctly. 
--------------------------------------------------------------
Alternatively, if you'd like to edit the files yourself, edit 
the "mkenv.mk" file and copy-paste this line where it says 
LIBS like so:

  Original:
LIBS =  --start-group -lv5rt -lstdc++ -lc -lm -lgcc --end-group

  Replaced:
LIBS =  --start-group -lv5rt -lstdc++ -lc -lm -lgcc -lvodom --end-group

--------------------------------------------------------------

USAGE:
The three header files are to be included as needed like so:
#include "robot.h"
#include "vmath.h"
#include "vmap.h"

The "vmap.h" requires "robot.h" and "vmath.h" to function properly.

DOCS:
robot.h - A subclass of vex::smartdrive which includes a timeout
parameter that will stop when either the robot is done or the time
has been reached, "preventing" stuck robots in auton. It includes all 
the functionality of vex::smartdrive and by inheritance, vex::drivetrain.

vmath.h - A math namespace "vmath" that contains a Vector2D class for 
"physics" applications, including scalar and dot products. There is no
plan as of now to create a Vector3D class.

vmap.h - A math namespace "vmap" that contains a Map class to provide a
virtual map for the VEX playing field, and an interface to control the robot.

LICENSE:
See "LICENSE.txt"