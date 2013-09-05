//
//  EXDynamicTimeLayer.cpp
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-08-27.
//
//

#include "EXDynamicTimeLayer.h"

EXDynamicTimeLayer::EXDynamicTimeLayer()
{
    mLight = NULL;
    mBackgroundArea = CCSizeZero;
}

EXDynamicTimeLayer::~EXDynamicTimeLayer()
{
    unschedule(schedule_selector(EXDynamicTimeLayer::update));
}

bool EXDynamicTimeLayer::init()
{
    if ( !CCLayer::init() )
        return false;
    
    initData();
    return true;
}

void EXDynamicTimeLayer::initData()
{
    mBackgroundArea = CCDirector::sharedDirector()->getWinSize();
    
    mLight = spriteWithColor(0.74f);
    mLight->setPosition(ccp(mBackgroundArea.width * 0.5f, mBackgroundArea.height * 0.5f));
    //ccTexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    //mLight->getTexture()->setTexParameters(&tp);
    addChild(mLight);
}

CCSprite* EXDynamicTimeLayer::spriteWithColor(float alpha)
{
    CCRenderTexture* rt = CCRenderTexture::create(mBackgroundArea.width, mBackgroundArea.height, kCCTexture2DPixelFormat_RGBA8888);
    ccColor4F fColor = {0.0f,0.0f,0.0f,alpha};
    
    if (rt)
    {
        rt->beginWithClear(fColor.r, fColor.g, fColor.b, fColor.a);
        rt->end();
        
        return CCSprite::createWithTexture(rt->getSprite()->getTexture());
    }
    
    return NULL;
}

void EXDynamicTimeLayer::alphaUpdate(float alpha)
{
    mLight->removeFromParentAndCleanup(true);
    mLight = spriteWithColor(alpha);
    mLight->setPosition(ccp(mBackgroundArea.width * 0.5f, mBackgroundArea.height * 0.5f));
    addChild(mLight);
}