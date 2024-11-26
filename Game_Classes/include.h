#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Image.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"
#include "GameObject.h"
#include "Line.h"
#include "Path.h"
#include "Tower.h"
#include "QuadTree.h"
#include "Menu.h"

inline
bool in_ob(Mouse & mouse, Tower & ball)
{
    int r = sqrt((ball.x() - mouse.x()) * (ball.x() - mouse.x()) + (ball.y() - mouse.y()) * (ball.y() - mouse.y()));
    return (r < ball.rad());

}
