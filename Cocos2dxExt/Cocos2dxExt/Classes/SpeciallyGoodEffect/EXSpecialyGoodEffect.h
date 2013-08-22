//
//  EXSpecialyGoodEffect.h
//  Cocos2dxExt
//
//  Created by HeiRenGa on 13-8-22.
//
//

#ifndef __Cocos2dxExt__EXSpecialyGoodEffect__
#define __Cocos2dxExt__EXSpecialyGoodEffect__

#include "cocos2d.h"
USING_NS_CC;

class EXSpecialyGoodEffect : public CCLayer
{
public:
    EXSpecialyGoodEffect();
    ~EXSpecialyGoodEffect();
    virtual bool init();
    CREATE_FUNC(EXSpecialyGoodEffect);
    
private:
    void initData();
};

#endif /* defined(__Cocos2dxExt__EXSpecialyGoodEffect__) */
