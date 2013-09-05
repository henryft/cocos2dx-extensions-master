//
//  EXDynamicLightLayer.cpp
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-08-27.
//
//

#include "EXDynamicLightLayer.h"
#include "EXSunShineSprite.h"

#define DAY_LENGHT ( 20.0f )
#define HALF_DAY_LENGHT ( DAY_LENGHT * 0.5f)
#define SCENE_MAX_ALPHA ( 190.0f )

EXDynamicLightLayer::EXDynamicLightLayer()
{
    mBackgroundArea = CCSizeZero;
    mDayLayer = NULL;
    mSun = NULL;
    mGlow = NULL;
    
    mAlpha = 0.0f;
    mDaytime = false;
    mCurTime = 0.0f;
    mBaseValue = 0.0f;
    
    mTimeID = Unkown_time;
}

EXDynamicLightLayer::~EXDynamicLightLayer()
{
    unschedule(schedule_selector(EXDynamicLightLayer::update));
    
    //CC_SAFE_RELEASE(mDayLayer);
    //CC_SAFE_RELEASE(mSun);
    //CC_SAFE_RELEASE(mGlow);
    
    removeAllChildrenWithCleanup(true);
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
}

bool EXDynamicLightLayer::init()
{
    if ( !CCLayer::init() )
        return false;
    
    _initData();
    return true;
}

void EXDynamicLightLayer::_initData()
{
    mBackgroundArea = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* mBg = CCSprite::create("BG.png");
    mBg->setPosition(ccp(mBackgroundArea.width * 0.5f,mBackgroundArea.height * 0.5f));
    addChild(mBg);

    mSun = CCSprite::create("sun.png");
    mSun->setPosition(ccp(mBackgroundArea.width * 0.5f, mBackgroundArea.height * 0.5f)); 
    addChild(mSun);
    mGlow = EXSunShineSprite::create("glow.png");
    //mGlow->setPosition(ccp(mBackgroundArea.width * 0.5f,mBackgroundArea.height * 0.5f));
    //addChild(mGlow);
    mGlow->setPosition(ccp(mSun->getContentSize().width * 0.5f, mSun->getContentSize().height * 0.5f));
    mSun->addChild(mGlow);
    
    mDayLayer = EXDynamicTimeLayer::create();
    addChild(mDayLayer);
    
    mTimeID = Morning_to_noon;
    mDaytime = true;
    
    // detlatime
    mBaseValue = SCENE_MAX_ALPHA / DAY_LENGHT * 2.0f;
    CCLOG("%s%d deltaTime = %f",__FUNCTION__,__LINE__,mBaseValue);
    schedule(schedule_selector(EXDynamicLightLayer::update),0.1f);
}

void EXDynamicLightLayer::update(float dt)
{
    mCurTime += dt;
    
    // update timeID
    if (mCurTime >= 0.0f && mCurTime < HALF_DAY_LENGHT)
        mTimeID = Morning_to_noon;
    else if (mCurTime >= HALF_DAY_LENGHT)
        mTimeID = Noon_to_night;
    else
        mTimeID = Unkown_time;
    
    if (mCurTime >= DAY_LENGHT)
    {
        mAlpha = 0.0f;
        
        _dayNightSwitch(mDaytime);
        mCurTime = 0.0f;
    }
    
    if (mDaytime)
        _dayUpdate(dt);
    else
        _nightUpdate(dt);
    
    float alpha = (SCENE_MAX_ALPHA - mAlpha) / 255.0f;
    CCLOG("%s%d alpha = %f",__FUNCTION__,__LINE__,alpha);
    mDayLayer->alphaUpdate(alpha);
    mGlow->setOpacity(mAlpha);
}

void EXDynamicLightLayer::_dayUpdate(float dt)
{
    float base = dt * mBaseValue ;
    switch (mTimeID) 
    {
        case Morning_to_noon:
            break;
        case Noon_to_night:
            base *= -1.0f;
            break;
            
        case Unkown_time:
        default:
            base = 0.0f;
            break;
    }
    
    mAlpha += base;
    
    if (mAlpha >= SCENE_MAX_ALPHA)
        mAlpha = SCENE_MAX_ALPHA;
    else if (mAlpha <= 0.0f)
        mAlpha = 0.0f;
    
    CCLOG("%s%d base = %f mAlpha = %f",__FUNCTION__,__LINE__,base,mAlpha);
}

void EXDynamicLightLayer::_nightUpdate(float dt)
{
    
}

bool EXDynamicLightLayer::_dayNightSwitch(bool cur)
{
    return mDaytime = (!cur) ? true : false;
}