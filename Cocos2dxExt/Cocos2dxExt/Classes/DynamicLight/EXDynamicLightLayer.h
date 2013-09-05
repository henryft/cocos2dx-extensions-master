//
//  EXDynamicLightLayer.h
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-8-27.
//
//

#ifndef __Cocos2dxExt__EXDynamicLightLayer__
#define __Cocos2dxExt__EXDynamicLightLayer__

#include "textures/CCTexture2D.h"
#include "cocos2d.h"

#include "EXDynamicTimeLayer.h"
#include "EXSunShineSprite.h"
USING_NS_CC;

typedef enum
{
    Morning_to_noon = 0,
    Noon_to_night,
    
    Unkown_time,
}PeriodOfTime;

class EXDynamicLightLayer : public CCLayer
{
public:
	EXDynamicLightLayer();
	virtual ~EXDynamicLightLayer();
    virtual bool init();
    CREATE_FUNC(EXDynamicLightLayer);
    
    void update(float dt);
    
private:
    void _initData();
    bool _dayNightSwitch(bool cur);
    
    void _dayUpdate(float dt);
    void _nightUpdate(float dt);
    
    // size of backgournd
    CCSize mBackgroundArea;
    
    EXDynamicTimeLayer* mDayLayer;
    // sun/moon
    CCSprite* mSun;
    // glow
    EXSunShineSprite* mGlow;
    
    float mAlpha;
    bool mDaytime;
    float mBaseValue;
    // current time
    float mCurTime;
    //
    PeriodOfTime mTimeID;
};


#endif /* defined(__Cocos2dxExt__EXDynamicLightLayer__) */
