//
//  EXSunShineSprite.h
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-8-30.
//
//

#ifndef __Cocos2dxExt__EXSunShineSprite__
#define __Cocos2dxExt__EXSunShineSprite__

#include "sprite_nodes/CCSprite.h"
#include "textures/CCTexture2D.h"
#include "cocoa/CCGeometry.h"
#include "cocos2d.h"
USING_NS_CC;

class EXSunShineSprite : public CCSprite
{
public:
	EXSunShineSprite();
	virtual ~EXSunShineSprite();
	static EXSunShineSprite* create(const char* pszFileName);
    static EXSunShineSprite* createWithSpriteFrameName(const char *pszSpriteFrameName);
    static EXSunShineSprite* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    
public:
    void setShinePic(const char* picName);
    
	virtual void draw();
};


#endif /* defined(__Cocos2dxExt__EXGraySprite__) */
