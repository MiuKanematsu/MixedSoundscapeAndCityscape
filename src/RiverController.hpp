//
//  RiverController.hpp
//  MixedSoundscapeAndCityscape
//
//  Created by Katsuya Endoh on 2023/01/29.
//

#ifndef RiverController_hpp
#define RiverController_hpp

#include <stdio.h>
#include <BaseController.hpp>
#include <RiverParticle.hpp>

class RiverController: public BaseController {
public:
    RiverController(float _minDistance);
    void addRivers(int riverIndex, int num);
    void drawPoints();
    bool addPoint(int lineIndex, float x, float y);
    void update();
    void drawRiver();
    void clear() {
        riverParticles.clear();
        BaseController::clear();
    };
private:
    vector<vector<RiverParticle>> riverParticles;
};

#endif /* RiverController_hpp */
