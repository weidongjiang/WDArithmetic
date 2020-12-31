//
//  WDOCClang.m
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/31.
//

//cd /Users/weidong/Desktop/jwd/WDArithmetic/WDArithmetic/WDArithmetic
//clang -rewrite-objc WDOCClang.m

#import "WDOCClang.h"

@implementation WDOCClang

//----------------------------------------------------
//实现两个NSRange的交集 （0.6）（2，7）
- (NSRange)getIntersectionRangeWithRange1:(NSRange)range1 range2:(NSRange)range2 {
    NSRange newRange = NSIntersectionRange(range1, range2);
    return newRange;
}

@end
