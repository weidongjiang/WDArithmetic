//
//  WDArithmeticOCManager.h
//  WDArithmetic
//
//  Created by 伟东 on 2020/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WDArithmeticOCManager : NSObject
//两个很长的数字字符串，计算两个的和(数学加法可能会存在溢出的问题)
- (void)addLongString;


- (void)testRange;

// 字符串里面出现的第一个不重复的字符 umu  gogole
- (NSString *)getFirstC:(NSString *)string;
@end

NS_ASSUME_NONNULL_END
