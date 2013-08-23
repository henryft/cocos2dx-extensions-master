//
//  EXSpecialyGoodEffect.cpp
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-8-22.
//
//

#include "EXSpecialyGoodEffect.h"

EXSpecialyGoodEffect::EXSpecialyGoodEffect()
{
    
}

EXSpecialyGoodEffect::~EXSpecialyGoodEffect()
{
    
}

bool EXSpecialyGoodEffect::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    initData();
    return true;
}

void EXSpecialyGoodEffect::initData()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // liquid
    //-------------------------------------------------------
    CCSprite* liquidSprite = CCSprite::create("Icon.png");
    liquidSprite->setPosition(ccp(winSize.width * 0.3f,winSize.height * 0.7f));
    liquidSprite->setAnchorPoint(ccp(1.0f,1.0f));
    addChild(liquidSprite);    
    // effect liquid
    CCActionInterval* liquidAction = CCLiquid::create(10.0f,CCSize(57,57), 2, 10.0f);
    liquidSprite->runAction(liquidAction);
    //-------------------------------------------------------
    
    // X-axis 3D reversal
    //-------------------------------------------------------
    CCSprite* XaxisSprite = CCSprite::create("Icon.png");
    XaxisSprite->setPosition(ccp(winSize.width * 0.6f,winSize.height * 0.7f));
    addChild(XaxisSprite);
    // effect X-axis 3D reversal
    CCActionInterval* XaxisActon = CCFlipX3D::create(5);
    XaxisSprite->runAction(XaxisActon);
    //-------------------------------------------------------
    
    // glass break
    //-------------------------------------------------------
    CCSprite* glassSprite = CCSprite::create("Icon.png");
    glassSprite->setPosition(ccp(winSize.width * 0.75f,winSize.height * 0.7f));
    addChild(glassSprite);
    // ShatteredTiles
    CCActionInterval* glassAction = CCShatteredTiles3D::create(10.0f, CCSize(10,10), 10, true);
    glassSprite->runAction(glassAction);
    //-------------------------------------------------------
    
    // CCShuffleTiles
    //-------------------------------------------------------
    CCSprite* shuffleSprite = CCSprite::create("Icon.png");
    shuffleSprite->setPosition(ccp(winSize.width * 0.9f,winSize.height * 0.7f));
    addChild(shuffleSprite);
    CCActionInterval* shuffleAction = CCShuffleTiles::create(1.0f, CCSize(100,100), 1);
    shuffleSprite->runAction(shuffleAction);
    //-------------------------------------------------------
    
    
    // CCFadeOutTRTiles
    //-------------------------------------------------------
    CCSprite* fadeoutTRSprite = CCSprite::create("Icon.png");
    fadeoutTRSprite->setPosition(ccp(winSize.width * 0.3f,winSize.height * 0.4f));
    addChild(fadeoutTRSprite);
    CCActionInterval* TRAction = CCFadeOutTRTiles::create(10.0, CCSize(57,57));
    fadeoutTRSprite->runAction(TRAction);
    //-------------------------------------------------------
    
    // CCSplitCols
    //-------------------------------------------------------
    CCSprite* splitSprite = CCSprite::create("Icon.png");
    splitSprite->setPosition(ccp(winSize.width * 0.6f,winSize.height * 0.4f));
    addChild(splitSprite);
    CCActionInterval* splitAction = CCSplitCols::create(10.0f, 57);
    splitSprite->runAction(splitAction);
    //-------------------------------------------------------
    
    // CCPageTurn3D
    //-------------------------------------------------------
    CCSprite* pageTurnSprite = CCSprite::create("Icon.png");
    pageTurnSprite->setPosition(ccp(winSize.width * 0.8f,winSize.height * 0.4f));
    pageTurnSprite->setAnchorPoint(ccp(0.0,0.0));
    addChild(pageTurnSprite);
    CCActionInterval* pageTurnAction = CCPageTurn3D::create(3.0f, CCSize(57,57));
    pageTurnSprite->runAction(pageTurnAction);
    //-------------------------------------------------------
}