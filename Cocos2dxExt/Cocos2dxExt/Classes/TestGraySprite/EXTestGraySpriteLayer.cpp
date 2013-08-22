//
//  EXTestGraySpriteLayer.cpp
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-7-10.
//
//

#include "EXTestGraySpriteLayer.h"
#include "EXGraySprite.h"

EXTestGraySpriteLayer::EXTestGraySpriteLayer()
{
    
}

EXTestGraySpriteLayer::~EXTestGraySpriteLayer()
{
    
}

bool EXTestGraySpriteLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    initData();
    return true;
}

void EXTestGraySpriteLayer::initData()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCSprite* normalSprite = CCSprite::create("Icon.png");
    normalSprite->setPosition(ccp(size.width * .35, size.height * .5));
    addChild(normalSprite);
    
    EXGraySprite* graySprite = EXGraySprite::create("Icon.png");
    graySprite->setPosition(ccp(size.width * .65, size.height * .5));
    addChild(graySprite);
    
    //技能CD
    EXGraySprite * cdNormalSprite = EXGraySprite::create("Icon.png");
    cdNormalSprite->setPosition(ccp(size.width * 0.5f,size.height * 0.35f));
    addChild(cdNormalSprite);
    
    CCProgressTo * time = CCProgressTo::create(5, 100);
    
    CCProgressTimer* cdSprite = CCProgressTimer::create(CCSprite::create("Icon.png"));
    cdSprite->setType(kCCProgressTimerTypeRadial);
    cdSprite->setReverseProgress(false);
    addChild(cdSprite);
    cdSprite->setPosition(cdNormalSprite->getPosition());
    cdSprite->runAction(CCRepeatForever::create((CCSequence::create(time,CCDelayTime::create(1.0),NULL))));
}