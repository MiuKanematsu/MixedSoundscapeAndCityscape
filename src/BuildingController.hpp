//
//  BuildingController.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by 兼松 美羽 on 2023/01/29.
//

#ifndef BuildingController_hpp
#define BuildingController_hpp

#include <stdio.h>
#include <BaseController.hpp>

class BuildingController: public BaseController{
public:
    BuildingController(float _minDistance);
};

#endif /* BuildingController_hpp */
