//
//  EXSunShineSprite.cpp
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-8-30.
//
//

#include "EXSunShineSprite.h"
EXSunShineSprite::EXSunShineSprite()
{
    
}

EXSunShineSprite::~EXSunShineSprite()
{
    
}

EXSunShineSprite* EXSunShineSprite::create( const char* pszFileName )
{
	EXSunShineSprite* pSprGrayScale = new EXSunShineSprite;
	if (pSprGrayScale && pSprGrayScale->initWithFile(pszFileName))
    {
		pSprGrayScale->autorelease();
	}else{
		CC_SAFE_RELEASE(pSprGrayScale);
	}
	return pSprGrayScale;
}

EXSunShineSprite* EXSunShineSprite::createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pszSpriteFrameName);
    char msg[256] = {0};
    sprintf(msg, "Invalid spriteFrameName: %s", pszSpriteFrameName);
    CCAssert(pFrame != NULL, msg);
    return createWithSpriteFrame(pFrame);
}

EXSunShineSprite* EXSunShineSprite::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame)
{
    EXSunShineSprite *pobSprite = new EXSunShineSprite();
    if (pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void EXSunShineSprite::setShinePic(const char* picName)
{
    this->setTexture(CCTextureCache::sharedTextureCache()->addImage(picName));
}

void EXSunShineSprite::draw()
{
	ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);
    m_sBlendFunc.src = GL_DST_COLOR;
    m_sBlendFunc.dst = GL_ONE;
	ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );
    
	this->getShaderProgram()->use();
	this->getShaderProgram()->setUniformsForBuiltins();
    
	ccGLBindTexture2D(  this->getTexture()->getName() );
    
#define kQuadSize sizeof(m_sQuad.bl)
	long offset = (long)&m_sQuad;
    
	// vertex
	int diff = offsetof( ccV3F_C4B_T2F, vertices);
	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));
    
	// texCoods
	diff = offsetof( ccV3F_C4B_T2F, texCoords);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));
    
	// color
	diff = offsetof( ccV3F_C4B_T2F, colors);
	glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	CC_INCREMENT_GL_DRAWS(1);
}
