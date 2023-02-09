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
#include <Building.hpp>

class BuildingController: public BaseController{
private:
    vector<Building> buildings;
public:
    BuildingController(float _minDistance);
    void update(int _x, int _y);
    void update(ofVec2f _p);
    void addPoint(float _x, float _y);
    
    // *** debug draw method ***
    void drawPoints();
    void drawBuildings();
};

#endif /* BuildingController_hpp */
