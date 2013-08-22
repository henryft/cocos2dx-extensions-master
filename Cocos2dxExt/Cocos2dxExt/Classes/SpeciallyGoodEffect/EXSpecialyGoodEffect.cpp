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
    CCSize size = CCDirector::sharedDirector()->getWinSize();
}