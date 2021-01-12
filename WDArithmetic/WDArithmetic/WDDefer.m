//
//  WDDefer.m
//  WDArithmetic
//
//  Created by 伟东 on 2021/1/5.
//

#import "WDDefer.h"

@implementation WDDefer


__unused static void cleanUpBlock(__strong void(^*block)(void)) {
    (*block)();
}

- (void)cleanUp {
    __strong void(^attribute_cleanup_block)(void) __attribute__((cleanup(cleanUpBlock), unused)) = ^{
        NSLog(@"clean up");
    };
    NSLog(@"processing");
}


@end
