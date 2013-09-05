//
//  EXDynamicTimeLayer.h
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-8-27.
//
//

#ifndef __Cocos2dxExt__EXDynamicTimeLayer__
#define __Cocos2dxExt__EXDynamicTimeLayer__

#include "textures/CCTexture2D.h"
#include "cocos2d.h"
USING_NS_CC;

class EXDynamicTimeLayer : public CCLayer
{
public:
	EXDynamicTimeLayer();
	virtual ~EXDynamicTimeLayer();
    virtual bool init();
    CREATE_FUNC(EXDynamicTimeLayer);
    
    void alphaUpdate(float dt);
    
private:
    void initData();
    CCSprite* spriteWithColor(float alpha);
    
    cocos2d::CCSprite* mLight;
    CCSize mBackgroundArea;
};


#endif /* defined(__Cocos2dxExt__EXDynamicTimeLayer__) */
