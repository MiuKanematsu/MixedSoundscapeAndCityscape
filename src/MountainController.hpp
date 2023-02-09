//
//  MountainController.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/02/09.
//

#ifndef MountainController_hpp
#define MountainController_hpp

#include <stdio.h>
#include <BaseController.hpp>

class MountainController: public BaseController {
public:
    MountainController(float _minDistance);
    void drawArea();
    void draw();
};

#endif /* MountainController_hpp */
